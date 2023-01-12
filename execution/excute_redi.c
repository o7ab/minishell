#include "../includes/minishell.h"

void    redir()
{
    int i;

    i = 0;
    while (g_info->cmd)
    {
        i = 0;
        while (g_info->cmd->full_cmd[i])
        {
            // printf("this is redir %s\n",g_info->cmd->full_cmd);
            i++;
        }
        g_info->cmd = g_info->cmd->next;
    }
    
}