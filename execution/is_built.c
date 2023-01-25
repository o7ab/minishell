#include "../includes/minishell.h"

void    ft_is_built(char *command)
{
    char *path;

    if (ft_strcmp(command, "echo") == 0)
        ft_echo();
    else if (ft_strcmp(command, "cd") == 0)
        ft_cd();
    else if (ft_strcmp(command, "env") == 0)
        ft_env();
    else if (ft_strcmp(command, "pwd") == 0)
        ft_pwd();
    else if (ft_strcmp(command, "export") == 0)
        ft_export();
    else if (ft_strcmp(command, "unset") == 0)
        ft_unset();
    else
    {
        path = ft_getenv("PATH");
        if (path != NULL)
            if (execve(put_cmd_in_path(g_info->cmd->s_cmd[0], path), g_info->cmd->s_cmd, NULL) < 0)
            {
                printf("Bash : Command not found\n");
                exit(1);
            }
    }
}