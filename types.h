#ifndef TYPES_H
#define TYPES_H

/* User defined types */
typedef unsigned int uint;

/* Status will be used in fn. return type */
typedef enum
{
    e_failure,
    e_success
} Status;

typedef enum
{
    e_view,
    e_edit,
    e_help,
    e_unsupported
} OperationType;

//printf color macros
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BCYAN    "\033[1;36m"
#define BWHITE   "\033[1;37m"
#define RESET   "\033[37m"



#endif
