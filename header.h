#include <stdio.h>
#include "stdlib.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>

#ifndef HEADER_H
# define HEADER_H

//function_str
void	ft_putstr(char *str);
int	ft_strlen(const char *str);
char	*ft_strncpy(char *dest, char *src, int n);
char	*ft_strcat(char *dest, char *src);
char *ft_strdup(char *src);
char	*ft_strcpy(char *dest, char *src);
int	ft_strcmp(char *s1, char *s2);
int	ft_natoi(const char *str, int nb_char);

//function
char *ft_str_in_dict(char *str);
void ft_print_tens(char *str);
void ft_print_hundred(char *str);
void ft_print(char *str);
int ft_is_only_zero(char *str);
char *ft_add_zero(char *str_copy, char *str, int zero);
void ft_main_while(char *str, int packet_of_three, int power);
void ft_to_power_ten(int power);


//parsing
char **ft_get_words(char *buf, int num_lines);
char **ft_get_numbers(char *buf, int num_lines);
int ft_get_nblines(char *str);
int ft_get_index(char *number, char **numbers, int nb_lines);
char *ft_get_word(char *num);
int main(int argc, char *argv[]);


//is_argv
int	is_num(char *str);
char    *rm_zero(char   *str);
int	max_num(int dictionary);
int	is_valid(char *str, int dictionary);
char *is_arg(int argc, char **argv);

#endif