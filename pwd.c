#include "minishell.h"

void    ft_pwd()
{
    size_t k = 100;
    char *buff = malloc(k);

    char *pwd = getcwd(buff, k);

    if (pwd == NULL)
    {
        perror("getcwd");
        // return 1;
    }

    printf("%s\n",pwd);
}