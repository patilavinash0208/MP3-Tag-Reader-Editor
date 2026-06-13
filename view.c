#include<stdio.h>
#include"types.h"
#include"view.h"
#include<string.h>

char *tags_arr[6] = {"Title","Artist","Album","Year","Content Type","Comment"}; //Array of strings containing full forms of tags

void big_to_lil(void * size)
{
    //logic to change endianness of size
    char temp;
    for(int i=0;i<2;i++)
    {
        temp = *((char*)size+i);
        *((char*)size+i) = *((char*)size+3-i);
        *((char*)size+3-i) = temp;
    }
}

Status read_and_validate_mp3(char *fname)
{
    //check if file having .mp3 extension
    if(strstr(fname,".mp3") != NULL)
    {
        return e_success;
    }
    else
    {
        return e_failure;
    }
}



Status view_and_print_data(mp3Info *info)
{
    //skip 10 header bytes by moving offset
    fseek(info->fptr_mp3, 10, SEEK_SET);

    char buffer[5];
    int size;
    char data[100];

    printf(BLUE"----------------------------------------------------------------------------\n"RESET);
    printf(BCYAN"MP3 Tag Reader and Editor for ID3v2.3\n"RESET);
    printf(BLUE"----------------------------------------------------------------------------\n"RESET);

    for(int i = 0; i < 6; i++)
    {
        //read 4 bytes of tag_name & store in buffer
        if(fread(buffer,1,4,info->fptr_mp3) != 4)
            return e_failure;

        //add last byte as null character to print it as a string
        buffer[4] = '\0';
        //printf("Frame ID: %s\n", buffer);

        //read 4 bytes of size from file & store in int variable
        if(fread(&size,1,4,info->fptr_mp3) != 4)
            return e_failure;

        //convert big endian size to little endian
        big_to_lil(&size);
        //printf("Size: %d\n", size);

        //skip 2 bytes of flags
        fseek(info->fptr_mp3, 2, SEEK_CUR);

        if(size > sizeof(data))
            return e_failure;

        //read size bytes of data from file & store into data buffer
        if(fread(data,1,size,info->fptr_mp3) != size)
            return e_failure;

        //add last byte as null character to print it as a string
        data[size] = '\0';
        //printf("Data: %s\n\n", data+1);
       
        //print tag name full form & tag data (exclude first encoded byte hence print from data+1)
        printf(BWHITE"%-20s :"RESET YELLOW"\t\t %-70s\n"RESET,tags_arr[i],data+1);
    }
    printf(BLUE"----------------------------------------------------------------------------\n"RESET);
    return e_success;
}
