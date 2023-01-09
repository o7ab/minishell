#include "minishell.h"

void    ft_cd()
{
    if (chdir(g_info->cmd->s_cmd[1]) != 0)
        perror("cd");
}