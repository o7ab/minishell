#include "../includes/minishell.h"

int ft_is_flg(char *option)
{
    int i;

    i = 0;
    if (option[i] == '-')
    {
        i++;
        while (option[i])
        {
            i++;
        }
    }
    else
        return (1);
    if (i == 2 && option[i - 1] == 'n')
        return (0);
    return (1);
}

void    ft_echo()
{
    int i;
    int option;

    option = 0;
    if (g_info->cmd)
    {
        i = 1;
        if (ft_is_flg(g_info->cmd->s_cmd[i]) == 0)
            option = 1;
        while (g_info->cmd->s_cmd[i])
        {
            ft_putstr_fd(g_info->cmd->s_cmd[i], 1);
            ft_putstr_fd(" ",1);
            i++;
        }
        if (option == 0)
            ft_putstr_fd("\n",1);
    }
    g_info->cmd = g_info->cmd->next;
}