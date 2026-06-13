#ifndef VIEW_H
#define VIEW_H
#include"types.h"
#include <stdio.h>


typedef struct _MP3INFO
{
    char *mp3_fname;
    FILE *fptr_mp3;
    FILE *fptr_temp;
    char *user_tag;

    char *new_data;

}mp3Info;

void big_to_lil(void * size);
Status view_and_print_data(mp3Info *info);
OperationType check_operation_type(char *);
Status read_and_validate_mp3(char *fname);
Status help_menu();
Status validate_tag(char *,mp3Info*);
Status do_edit(mp3Info *);
Status copy_header(mp3Info *);
Status read_and_write(mp3Info *);
Status write_new_data(mp3Info *);
Status copy_remaining_data(mp3Info *);
#endif