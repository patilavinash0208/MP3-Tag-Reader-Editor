#include<stdio.h>
#include"types.h"
#include"view.h"
#include<string.h>

char *tag_command[6] = {"-t","-A","-a","-y","-c","-C"};     //array containing tag commands
char *tag_name[6] = {"TIT2","TPE1","TALB","TYER","TCON","COMM"};    //array containing original tag names

Status validate_tag(char *tag, mp3Info *info)
{
    //check if user entered tag matches with any tag_command[] element if matches then store its equivalent tag_name[] from the same index position in the structure member user_tag 
    for(int i=0;i<6;i++)
    {
        if(strcmp(tag,tag_command[i]) == 0)
        {
            info->user_tag = tag_name[i];
            return e_success;
        }
    }
    return e_failure;
}

Status copy_header(mp3Info *info)
{
    //read first 10 header bytes from the file & write into temp file
    char buffer[10];
    fread(buffer,1,10,info->fptr_mp3);
    fwrite(buffer,1,10,info->fptr_temp);
    return e_success;
}

Status write_new_data(mp3Info *info)
{
    //read 4 bytes of size from file & store into size variable
    int size;
    fread(&size,1,4,info->fptr_mp3);
    //convert Big Endian size to little endian
    big_to_lil(&size);

    //write new_size of new_data to temp file (allocate 1 extra byte memory for encoding byte)
    int new_size = strlen(info->new_data)+1;

    //convert our little endian new_size to big endian
    big_to_lil(&new_size);
    //write new_size to the temp file
    fwrite(&new_size,1,4,info->fptr_temp);

    //convert big endian new_size to little endian again to write that many bytes of new_data  
    big_to_lil(&new_size);

    //copy 2 bytes of flag
    char flag[2];
    fread(flag,1,2,info->fptr_mp3);
    fwrite(flag,1,2,info->fptr_temp);

    //Write Encoding byte before new_data
    char encoding = 0x00;
    fwrite(&encoding,1,1,info->fptr_temp);

    //write new_data of new_size-1 (excluded 1 encoded byte,already written) to the temp file
    fwrite(info->new_data,1,new_size-1,info->fptr_temp);

    //move offset size bytes ahead in the original file to point to next tag
    fseek(info->fptr_mp3,size,SEEK_CUR);

    return e_success;
}

Status read_and_write(mp3Info *info)
{
    char buffer[5];
    int size;
    char flag[2];
    char data[100];
    for(int i=0;i<6;i++)
    {
        //Read 4 bytes of tag from original file & write to temp  file
        fread(buffer,1,4,info->fptr_mp3);
        fwrite(buffer,1,4,info->fptr_temp);

        //if tag in file matches with user entered tag then start writing new_data
        if(strcmp(buffer,info->user_tag)==0)
        {
            if(write_new_data(info) == e_success)
            {
                printf("\033[32m""Written new data successfully\n""\033[37m");
            }
            else
            {
                printf("\033[31m""Writing new data failed\n""\033[37m");
                return e_failure;
            }
        }
        else //if tag doesn't match copy entire data as it is to temp file
        {
            //Read and write size
            fread(&size,1,4,info->fptr_mp3);
            fwrite(&size,1,4,info->fptr_temp);

            //convert big endian size to little endian
            big_to_lil(&size);
            
            //Copy flag
            fread(flag,1,2,info->fptr_mp3);
            fwrite(flag,1,2,info->fptr_temp);

            //read and write size bytes of data from original file to temp file
            fread(data,1,size,info->fptr_mp3);
            fwrite(data,1,size,info->fptr_temp);
        }
    }

    return e_success;
}

Status do_edit(mp3Info *info)
{
    //call copy_header(info) function from original file to temp file
    if(copy_header(info) == e_success)
    {
        printf("\033[32m""Copy header successful\n""\033[37m");
    }
    else
    {
        printf("\033[31m""Copy header failed\n""\033[37m");
        return e_failure;
    }

    //call read_and_write(info) function to read and write data
    if(read_and_write(info) == e_success)
    {
        printf("\033[32m""Read and write successful\n""\033[37m");
    }
    else
    {
        printf("\033[31m""Read and write failed\n""\033[37m");
        return e_failure;
    }
    
    //call copy_remaining_data(info) function to copy all the remaining data as it is
    if(copy_remaining_data(info) == e_success)
    {
        printf("\033[32m""Copied remaining Data successfully\n""\033[37m");
        //after copying data remove the original file
        remove(info->mp3_fname);
        //rename temp file with the user entered file name
        rename("temp.mp3",info->mp3_fname);
        return e_success;
    }
    else{
        printf("\033[31m""Copy remaining Data failed\n""\033[37m");
        return e_failure;
    }

    return e_success;
}


Status copy_remaining_data(mp3Info *info)
{
    //copy remainig data
    int ch;
    while((ch = getc(info->fptr_mp3)) != EOF)
    {
        putc(ch , info->fptr_temp);
    }

    return e_success;
}