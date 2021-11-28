#include "header.h"

int main(int argc, char **argv) {


    char *string;

    string = is_arg(argc, argv);

    printf("%s", is_arg(argc, argv));
    //ft_print_written_number(string);

    return (0);
}