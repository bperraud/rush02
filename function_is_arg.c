/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_is_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:53:22 by jpicron           #+#    #+#             */
/*   Updated: 2021/11/28 18:16:06 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"
#define TAILLE_MAX 1000
//find if string is all number

int	is_num(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (str[a] < '0' || str[a] > '9')
			return (1);
		a++;
	}
	return (0);
}
//remove starting 0 from string

char	*rm_zero(char *str)
{
	int	a;

	a = 0;
	while (str[a] == '0')
	{
		a++;
	}
	if (str[a] == '\0')
		str = &str[a - 1];
	else
		str = &str[a];
	return (str);
}
// find the highest possible number in the dictionary

int	max_num(int dictionary)
{
	int		a;
	int		max;
	int		b;
	char	temp[TAILLE_MAX];

	max = 0;
	read(dictionary, temp, TAILLE_MAX);
	a = 0;
	b = 0;
	while (temp[a])
	{
		while ((temp[a] >= '0' && temp[a] <= '9') && temp[a])
		{
			b++;
			a++;
		}
		if (b > max)
			max = b;
		b = 0;
		while ((temp[a] < '0' || temp[a] > '9') && temp[a])
		{
			a++;
		}
	}
	return (max);
}
//check if the string is an integer 
//and that we can write it using the dictionary

int	is_valid(char *str, int dictionary)
{
	if (ft_strlen(str) > max_num(dictionary))
		return (1);
	if (is_num(str))
		return (1);
	return (0);
}
