#include<stdio.h>
#include"types.h"
#include<string.h>
#include"view.h"

Status help_menu()
{
    //Help menu printing
    printf(CYAN"mp3tag --help\n"RESET);
    printf(BLUE"----------------------------------------------------------------------------\n"RESET);
    printf("Command formats for different options:\n");
    printf("%-7s : ./a.out -h\n","help");
    printf("%-7s : ./a.out -v <file_name>\n","view");
    printf("%-7s : ./a.out -e <tag> <new_data> <file_name>\n\n","edit");
    printf("tags:\n");
    printf("%-7s   Modifies a Title tag\n","-t");
    printf("%-7s   Modifies a Artist tag\n","-A");
    printf("%-7s   Modifies a Album tag\n","-a");
    printf("%-7s   Modifies a Year tag\n","-y");
    printf("%-7s   Modifies a Content type tag\n","-c");
    printf("%-7s   Modifies a Comment tag\n","-C");
    printf(BLUE"----------------------------------------------------------------------------\n"RESET);
    return e_success;
}