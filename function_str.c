#include "header.h"

void	ft_putstr(char *str)
{
    if (*str == 0)
        return ;
    while (*str)
    {
        write(1, str++, 1);
    }
}

int	ft_strlen(const char *str)
{
    int		i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
    int	i;

    i = 0;
    while (src[i] != '\0' && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
    char *d;

    d = dest;
    while (*d != '\0')
        d++;
    while (*src != '\0')
        *d++ = *src++;
    *d = '\0';
    return (dest);
}

int	ft_natoi(const char *str, int nb_char)
{
    int	res;
    int	i;

    res = 0;
    i = 0;
    while (str[i] >= '0' && str[i] <= '9' && nb_char)
    {
        res = res * 10 + str[i] - '0';
        i++;
        nb_char--;
    }
    return (res);
}