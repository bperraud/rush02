#include "header.h"

int main(int argc, char **argv) {


    char *string;

    string = is_arg(argc, argv);

    if (!string)
        printf("Wrong number or wrong dictionnary");
    else
        printf("%s", is_arg(argc, argv));
    //ft_print_written_number(string);

    return (0);
}