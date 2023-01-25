#include "../includes/minishell.h"

void    ft_pwd()
{
    char *path;

    path = getcwd(NULL, 0);
    ft_putendl_fd(path, 1);
    // free(path);
}