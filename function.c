#include "header.h"

char *ft_str_in_dict(char *str)
{
    write(1, " ", 1);

    if (!ft_strcmp(str, "1000000"))
        return "million";
    if (!ft_strcmp(str, "12"))
        return "twelve";
    if (!ft_strcmp(str, "14"))
        return "fourteen";
    if (!ft_strcmp(str, "80"))
        return "eighty";
    if (!ft_strcmp(str, "0"))
        return "";
    if (!ft_strcmp(str, "1"))
        return "one";
    if (!ft_strcmp(str, "2"))
        return "two";
    if (!ft_strcmp(str, "3"))
        return "three";
    if (!ft_strcmp(str, "4"))
        return "four";
    if (!ft_strcmp(str, "5"))
        return "five";
    if (!ft_strcmp(str, "100"))
        return "hundred";
    if (!ft_strcmp(str, "1000"))
        return "thousand";
    if (!ft_strcmp(str, "10"))
        return "ten";
    return "rien";
}

/*
 * print the first char of str
 */
void ft_print_char(char *str) {
    char r[2];

    r[0] = str[0];
    r[1] = '\0';
    ft_putstr(ft_str_in_dict(r));
}

/*
 * print first two char of str
 */
void ft_print_tens(char *str)   //ne prend que des strings de 2 char
{
    char r[3];
    int number;

    number = ft_natoi(str, 2);
    if (number != 0)
    {
        if (number <= 20)
        {
            if (str[0] == '0')
                ft_print_char(str + 1);
            else
                ft_putstr(ft_str_in_dict(ft_strncpy(r, str, 2)));
        }
        else
        {
            r[0] = str[0];
            r[1] = '0';
            //r[2] = '\0';
            ft_putstr(ft_str_in_dict(r));   // taille de la puissance de 10 + taille du premier chiffre + 2 espaces
            ft_print_char(str + 1);
        }
    }
}

/*
 * print first three char of str
 */
void ft_print_hundred(char *str)
{
    if (str[0] == '0' && str[1] == '0' && str[2] == '0')
        return ;
    if (str[0] == '0')
        ft_print_tens(str + 1);
    else
    {
        ft_print_char(str);
        ft_putstr(ft_str_in_dict("100")) ;
        ft_print_tens(str + 1);
    }
}

char *ft_add_zero(char *str_copy, char *str, int zero_to_be_added)
{
    int i;

    i = 0;
    while (i < zero_to_be_added)
    {
        str_copy[i] = '0';
        i++;
    }
    ft_strcat(str_copy, str);
    str_copy[ft_strlen(str_copy)] = '\0';
    return (str_copy);
}

/*
 * create a string of 10 power of "power" and print it
 */
void ft_to_power_ten(int power) {
    char *str_power_ten;
    int i;

    i = 1;
    str_power_ten = malloc(power * sizeof(char) + 2);   // nombre de zero + 1 pour le premier chiffre + 1 pour '\0'
    if (!str_power_ten)
        return ;
    str_power_ten[0] = '1';
    while (i < power + 1)
    {
        str_power_ten[i] = '0';
        i++;
    }
    str_power_ten[i] = '\0';
    ft_putstr(ft_str_in_dict(str_power_ten));
    free(str_power_ten);
}

int ft_is_only_zero(char *str)
{
    if (str[0] == '0' && str[1] == '0' && str[2] == '0')
        return (1);
    return (0);
}

void ft_print(char *str)
{
    int len_str;
    int packet_of_three;
    int power;
    int zero_to_be_added;
    char *str_copy;
    char *str_copy_free;

    zero_to_be_added = 0;
    len_str = ft_strlen(str);
    if (str[0] == '0' && len_str == 1)
        ft_putstr(ft_str_in_dict("0"));
    else if (ft_strlen(str) == 3)
        ft_print_hundred(str);
    else
    {
        if (len_str % 3 == 1)
        {
            packet_of_three = (len_str + 2) / 3;
            zero_to_be_added = 2;
        }
        else if (len_str % 3 == 2)
        {
            packet_of_three = (len_str + 1) / 3;
            zero_to_be_added = 1;
        }
        else
            packet_of_three = (len_str / 3);

        power = ((len_str - 1) / 3) * 3;
        if (power == 0)
            power = 2;

        str_copy = malloc((len_str + zero_to_be_added) * sizeof(char) + 1);
        str_copy_free = str_copy;
        str_copy = ft_add_zero(str_copy , str, zero_to_be_added);
        ft_main_while(str_copy, packet_of_three, power);
        free(str_copy_free);
    }
}

void ft_main_while(char *str, int packet_of_three, int power)
{
    while (packet_of_three > 0)
    {
        ft_print_hundred(str);
        if (!ft_is_only_zero(str) && power > 2)    // si que des zero on print pas la puissance de 10
            ft_to_power_ten(power);
        packet_of_three--;
        power -= 3;
        str += 3; // passe au paquet suivant
    }
}
