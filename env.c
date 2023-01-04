#include "minishell.h"
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

char *get_path(void)
{
    int i;

    i = 0;
    while (g_info->env[i])
    {
        if ((ft_strncmp(g_info->env[i],"PATH=",5)) == 0)
        {
            return (remove_equal(g_info->env[i]));
            break;
        }
        i++;
    }
    return (NULL);
}