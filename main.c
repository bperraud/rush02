#include "header.h"

int ISFIRST;
int main(int argc, char **argv) {


    char *string;

    ISFIRST = 1;
    string = is_arg(argc, argv);
    if (!string)
        printf("Wrong number or wrong dictionnary");
    else
    {
        printf("%s\n", string);
        ft_print_written_number(string);
    }
    return (0);
}