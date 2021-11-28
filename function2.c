/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:21:39 by jpicron           #+#    #+#             */
/*   Updated: 2021/11/28 20:24:34 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	ft_is_only_zero(char *str)
{
    if (str[0] == '0' && str[1] == '0' && str[2] == '0')
        return (1);
    return (0);
}

void	ft_print_written_number_2(char *str, int packet_of_three,
                                  int power, int zero_to_be_added)
{
    char	*str_copy;
    char	*str_copy_free;

    str_copy = malloc((ft_strlen(str) + zero_to_be_added) * sizeof(char) + 1);
    if (!str_copy)
        return ;
    str_copy_free = str_copy;
    str_copy = ft_add_zero(str_copy, str, zero_to_be_added);
    ft_main_while(str_copy, packet_of_three, power);
    free(str_copy_free);
}

void	ft_print_written_number(char *str)
{
    int	packet_of_three;
    int	power;
    int	zero_to_be_added;
    int	len_str;

    zero_to_be_added = 0;
    len_str = ft_strlen(str);
    if (str[0] == '0' && len_str == 1)
        ft_putstr(ft_str_in_dict("0", 1));
    else if (len_str == 3)
        ft_print_hundred(str);
    else
    {
        if (ft_strlen(str) % 3 == 1)
            zero_to_be_added = 2;
        else if (ft_strlen(str) % 3 == 2)
            zero_to_be_added = 1;
        packet_of_three = (len_str + zero_to_be_added) / 3;
        power = ((ft_strlen(str) - 1) / 3) * 3;
        if (power == 0)
            power = 2;
        ft_print_written_number_2(str, packet_of_three,
                                  power, zero_to_be_added);
    }
}

void	ft_main_while(char *str, int packet_of_three, int power)
{
    while (packet_of_three > 0)
    {
        ft_print_hundred(str);
        if (!ft_is_only_zero(str) && power > 2)
            ft_to_power_ten(power);
        packet_of_three--;
        power -= 3;
        str += 3;
    }
}
