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
    while (__environ[i])
    {
        if ((ft_strncmp(__environ[i],"PATH=",5)) == 0)
        {
            return (remove_equal(__environ[i]));
            break;
        }
        i++;
    }
    return (NULL);
}