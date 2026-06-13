/*
                                            MP3 TAG READER AND EDITOR
                                
                    Name : Avinash Patil
                    Batch: 25036A
                    Date : 25/02/2026

                    Description : MP3 tag reader & editor is a software application which is used to read and edit tags data from a mp3 file.
*/

#include<stdio.h>
#include"types.h"
#include<string.h>
#include"view.h"

int main(int argc, char *argv[])
{
    mp3Info info;
    
    if(argc<2 || argc>5)
    {
        //If no of arguments invalid,print error msg and help menu reference
        printf("\033[31m""ERROR: Invalid no of arguments\n""\033[37m");
        printf("\033[36m""Refer help menu :\n");
        printf("Use Command : ./a.out -h\n""\033[37m");
        // help_menu();
        return e_failure;
    }

    //call check_operation_type() function to check which operation command user has given
    int ret = check_operation_type(argv[1]);

    if(ret == e_view)
    {
        if(argc != 3)
        {
            //If no of arguments invalid,print error msg and help menu reference
            printf("\033[31m""ERROR: Invalid no of arguments\n""\033[37m");
            printf("\033[36m""Refer help menu :\n");
            printf("Use Command : ./a.out -h\n""\033[37m");
            return e_failure;
        }

        //validate the file passed is mp3 or not
        if(read_and_validate_mp3(argv[2])==e_success)
        {
            printf("\033[32m""File validation successful\n""\033[37m");
            //if valid file store the file name
            info.mp3_fname = argv[2];
        }
        else
        {
            printf("\033[31m""ERROR : Invalid file\n""\033[37m");
            return e_failure;
        }

        //opening MP3 file
        info.fptr_mp3 = fopen(info.mp3_fname,"r");

        //if file opening failed return e_failure
        if(info.fptr_mp3 == NULL)
        {
            printf("\033[31m""File opening failed\n""\033[37m");
            return e_failure;
        }
        else
        {
            printf("\033[32m""File opened successfully\n""\033[37m");
        }

        //call view_and_print_data() function to read data from file & print it to the terminal
        if(view_and_print_data(&info) == e_success)
        {
            printf("\033[32m""View tags successful\n""\033[37m");
            return e_success;
        }
        else
        {
            printf("\033[31m""View tags failed\n""\033[37m");
            return e_failure;
        }

    }
    else  if(ret == e_edit)
    {
        //If edit option is selected check no of arguments passed, should be 5 arguments
        if(argc != 5)
        {
            //If arguments invalid,print error msg and help menu reference
            printf("\033[31m""ERROR: Invalid no of arguments\n""\033[37m");
            printf("\033[36m""Refer help menu :\n");
            printf("Use Command : ./a.out -h\n""\033[37m");
            return e_failure;
        }

        //validate the file passed is mp3 or not
        if(read_and_validate_mp3(argv[4])==e_success)
        {
            printf("\033[32m""File validation successful\n""\033[37m");
            info.mp3_fname = argv[4];
        }
        else
        {
            printf("\033[31m""ERROR : Invalid file\n");
            return e_failure;
        }

        //validate user entered tag 
        if(validate_tag(argv[2],&info) == e_success)
        {
            printf("\033[32m""Valid tag found\n""\033[37m");
        }
        else
        {
            printf("\033[31m""InValid tag found\n""\033[37m");
            return e_failure;
        }

        //store new data
        info.new_data = argv[3];

        //opening files
        info.fptr_mp3 = fopen(info.mp3_fname,"r");
        info.fptr_temp = fopen("temp.mp3","w");

        //if file opening failed return e_failure
        if(info.fptr_mp3 == NULL || info.fptr_temp == NULL)
        {
            printf("\033[31m""File opening failed\n""\033[37m");
            return e_failure;
        }
        else
        {
            printf("\033[32m""File opened successfully\n""\033[37m");
        }

        //call do edit function
        if(do_edit(&info) == e_success)
        {
            printf("\033[32m""File edited successfully\n""\033[37m");
            return e_success;
        }
        else
        {
            printf("\033[31m""Editing failed\n""\033[37m");
            return e_failure;
        }
    }
    else  if(ret == e_help)
    {
        //If help option is selected check no of arguments passed, should be 2 arguments
        if(argc != 2)
        {
            //If arguments invalid,print error msg and help menu reference
            printf("\033[31m""ERROR: Invalid no of arguments\n""\033[37m");
            printf("\033[36m""Refer help menu :\n");
            printf("Use Command : ./a.out -h\n""\033[37m");
            return e_failure;
        }

        //if arguments valid then call help_menu() function to print help menu
        help_menu();
        return e_success;
    }
    else
    {
        //If operation type invalid,print error msg and help menu reference
        printf("\033[31m""ERROR: Invalid operation type\n""\033[37m");
        printf("\033[36m""Refer help menu :\n");
        printf("Use Command : ./a.out -h\n""\033[37m");
        // help_menu();
        return e_failure;
    }
}

OperationType check_operation_type(char *symbol)
{
    //step1 -> check it is -v or -e 
    // if it is -v return e_view
    // else if it is -e rteun e_edit
    // else if it is -h rteun e_help
    // else return e_unsuported
    if(strcmp(symbol,"-v")==0)
    {
        return e_view;
    }
    else if(strcmp(symbol,"-e")==0)
    {
        return e_edit;
    }
    else if(strcmp(symbol,"-h")==0)
    {
        return e_help;
    }
    else
    {
        return e_unsupported;
    }
}