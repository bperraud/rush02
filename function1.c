/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:14:21 by jpicron           #+#    #+#             */
/*   Updated: 2021/11/28 20:23:14 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * print the first char of str
 */
void	ft_print_char(char *str)
{
    char	r[2];

    r[0] = str[0];
    r[1] = '\0';
    ft_putstr(ft_str_in_dict(r, 0));
}

/*
 * print first two char of str
*/
void	ft_print_tens(char *str)
{
    char	r[3];
    int		number;

    number = ft_natoi(str, 2);
    if (number != 0)
    {
        if (number <= 20)
        {
            if (str[0] == '0')
                ft_print_char(str + 1);
            else
                ft_putstr(ft_str_in_dict(ft_strncpy(r, str, 2), 0));
        }
        else
        {
            r[0] = str[0];
            r[1] = '0';
            ft_putstr(ft_str_in_dict(r, 0));
            ft_print_char(str + 1);
        }
    }
}

/*
 * print first three char of str
 */
void	ft_print_hundred(char *str)
{
    if (str[0] == '0' && str[1] == '0' && str[2] == '0')
        return ;
    if (str[0] == '0')
        ft_print_tens(str + 1);
    else
    {
        ft_print_char(str);
        ft_putstr(ft_str_in_dict("100", 0));
        ft_print_tens(str + 1);
    }
}

char	*ft_add_zero(char *str_copy, char *str, int zero_to_be_added)
{
    int	i;

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
void	ft_to_power_ten(int power)
{
    char	*str_power_ten;
    int		i;

    i = 1;
    str_power_ten = malloc(power * sizeof(char) + 2);
    if (!str_power_ten)
        return ;
    str_power_ten[0] = '1';
    while (i < power + 1)
    {
        str_power_ten[i] = '0';
        i++;
    }
    str_power_ten[i] = '\0';
    ft_putstr(ft_str_in_dict(str_power_ten, 0));
    free(str_power_ten);
}
