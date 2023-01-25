#include "../includes/minishell.h"

char    *rem(char *str)
{
    int i;

    i = 0;
    while (str[i] != '=')
    {
        i++;
    }
    i++;

    return ((char *)&str[i]);
}

char *ft_getenv(char *s)
{
    int i;

    i = 0;
    while (g_info->env[i])
    {
        if ((ft_strncmp(g_info->env[i], s,ft_strlen(s))) == 0)
        {
            return (rem(g_info->env[i]));
            break;
        }
        i++;
    }
    return (NULL);
}