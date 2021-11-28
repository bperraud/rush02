#include "header.h"

extern int ISFIRST;
char **ft_get_words(char *buf, int num_lines)
{
	int i;
	char **words;
	int j;
	char *newword;
	int len_word;
	
	words = malloc(num_lines * sizeof(char *));
	i = 0;
	while(*buf)
	{
		j = 0;
		newword = buf;
		len_word = 0;
		while ((*buf >= '!' && *buf <= '~')
				&& !(*buf >= '0' && *buf <= ':'))
		{
			len_word ++;
			buf ++;
		}
		buf = newword;
		if ((*buf >= '!' && *buf <= '~')
				&& !(*buf >= '0' && *buf <= ':'))
			words[i] = malloc(len_word + 1 * sizeof(char));
		while ((*buf >= '!' && *buf <= '~')
				&& !(*buf >= '0' && *buf <= ':'))
		{
			words[i][j] = *buf;
			j ++;
			buf ++;
			if (j == len_word)
			{
				words[i][j] = '\0';
				i ++;
			}
		}
		while (!((*buf >= '!' && *buf <= '~')
				&& !(*buf >= '0' && *buf <= ':')) && *buf)
			buf ++;
	}
	return (words);
}

char **ft_get_numbers(char *buf, int num_lines)
{
	int i;
	char **numbers;
	int j;
	char *newnumber;
	int len_num;

	numbers = malloc(num_lines * sizeof(char *));
	i = 0;
	while(*buf)
	{
		j = 0;
		len_num = 0;
		newnumber = buf;
		while (*buf >= '0' && *buf <= '9')
		{
			len_num ++;
			buf ++;
		}
		buf = newnumber;
		if (*buf >= '0' && *buf <= '9')
			numbers[i] = malloc(len_num + 1 * sizeof(char));
		while (*buf >= '0' && *buf <= '9')
		{
			numbers[i][j] = *buf;
			j ++;
			buf ++;
			if (j == len_num)
			{
				numbers[i][j] = '\0';
				i ++;
			}
		}
		while (!(*buf >= '0' && *buf <= '9') && *buf)
			buf ++;
	}
	return (numbers);
}

int ft_get_nblines(char *str)
{
	int nblines;

	nblines = 0;
	while (*str)
	{
		if (*str == '\n')
			nblines ++;
		str ++;
	}
	return (nblines);
}

int ft_get_index(char *number, char **numbers, int nb_lines)
{
	bool are_equal;
	int i;
	int j;
	int k;

	are_equal = false;
	i = 0;
	j = 0;
	k = 0;
	while (!are_equal && i < nb_lines)
	{
		while (number[k] == numbers[i][j] && number[k] && numbers[i][j])
		{
			k ++;
			j ++;
		}
		if (number[k] == '\0')
			are_equal = true;
		else 
		{
			k = 0;
			j = 0;
			i ++;
		}
	}
	if (are_equal)
		return (i);
	return (-1);
}

char *ft_str_in_dict(char *num, int is_zero)
{
	char *buf;
	int fd;
	char **numbers;
	char **words;
	int	index;
	int nb_lines;

	if (!ISFIRST)
	    write(1, " ", 1);
	ISFIRST = 0;
	fd = open("number", O_RDONLY);
	buf = malloc(2048 * sizeof(char));
	if (!buf)
		return ("Error\n");
	read(fd, buf, 2048);
	close(fd);
	nb_lines = ft_get_nblines(buf);
	numbers = ft_get_numbers(buf, nb_lines);
	words = ft_get_words(buf, nb_lines);
	free(buf);
	index = ft_get_index(num, numbers, nb_lines);
	if (index < 0)
    {
        printf("index ; %d\n", index);
        printf("num ; %s\n", num);
        printf("%s\n", words[index]);
        return ("Error ici\n");
    }

	if (ft_natoi(num, ft_strlen(num) != 0 || is_zero))
	    return (words[index]);
	return NULL;
}
