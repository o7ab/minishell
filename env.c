#include "minishell.h"

char *get_path(void)
{
    int i;
    // int j;

    i = 0;
    // j = 0;
    while (__environ[i])
    {
        if ((ft_strncmp(__environ[i],"PATH=",5)) == 0)
        {
            // printf("%s\n",__environ[i]);
            return (__environ[i]);
            break;
        }
        i++;
    }
    return (NULL);
}