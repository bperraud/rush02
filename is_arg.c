/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:07:49 by jpicron           #+#    #+#             */
/*   Updated: 2021/11/28 16:42:38 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
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

char    *rm_zero(char   *str)
{
	int a;

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
//check if the string is an integer and that we can write it using the dictionary

int	is_valid(char *str, int dictionary)
{
	if (ft_strlen(str) > max_num(dictionary))
		return (1);
	if (is_num(str))
		return (1);
	return (0);
}
//check if our args are valide and give back the string without it's starting 0 or null if the args are invalid

char *is_arg(int argc, char **argv)
{
	int	dictionary;
	char *str;

	if (argc != 2 && argc != 3)
		return (0);
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
			return(0);
		dictionary = open("numbers.dict", O_RDONLY);
		str = rm_zero(argv[1]);
		if (is_valid(str, dictionary))
			return (0);
	}
	if (argc == 3)
	{
		if (argv[1][0] == '\0')
			return(0);
		dictionary = open(argv[1], O_RDONLY);
		if (dictionary == -1)
			return (0);
		str = rm_zero(argv[2]);
		if (is_valid(str, dictionary))
			return (0);
	}
	return (str);
}