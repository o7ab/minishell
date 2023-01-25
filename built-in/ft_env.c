
#include "../includes/minishell.h"

char    *remove_equal(char *str)
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

char *ft_env(void)
{
    int i;

    i = 0;
    while (g_info->env[i])
    {
        printf("%d %s\n",i,g_info->env[i]);
        i++;
    }
    return (NULL);
}