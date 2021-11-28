/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:07:49 by jpicron           #+#    #+#             */
/*   Updated: 2021/11/28 18:17:09 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

//check if our args are valide 
//and give back the string without it's starting 0 
//or null if the args are invalid
char	*argc2(char **argv)
{
	int		dictionary;
	char	*str;

	if (argv[1][0] == '\0')
		return (0);
	dictionary = open("number", O_RDONLY);
	str = rm_zero(argv[1]);
	if (is_valid(str, dictionary))
		return (0);
	return (str);
}

char	*argc3(char **argv)
{
	int		dictionary;
	char	*str;

	if (argv[1][0] == '\0')
		return (0);
	dictionary = open(argv[1], O_RDONLY);
	if (dictionary == -1)
		return (0);
	if (argv[2][0] == '\0')
		return (0);
	str = rm_zero(argv[2]);
	if (is_valid(str, dictionary))
		return (0);
	return (str);
}

char	*is_arg(int argc, char **argv)
{
	char	*str;

	if (argc != 2 && argc != 3)
		return (0);
	if (argc == 2)
		str = argc2(argv);
	if (argc == 3)
		str = argc3(argv);
	return (str);
}
