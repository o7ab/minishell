#include "../includes/minishell.h"

void    ft_cd()
{
    char *cwd;
    cwd = getcwd(NULL, 0);
    change_env("OLDPWD", cwd, 0);  
    if (chdir(g_info->cmd->s_cmd[1]) != 0)
        perror("cd");
    cwd = getcwd(NULL, 0);
    change_env("PWD", cwd, 0);
}