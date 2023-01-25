#include "../includes/minishell.h"

char    *ft_var(int i, int j)
{
    char *ptr;
    int m;

    m = 0;
    ptr = malloc((i + 1) * sizeof(char));
    while (m < i)
    {
        ptr[m] = g_info->cmd->s_cmd[j][m];
        m++;
    }
    ptr[m] = '\0';
    return(ptr);
}

void    ft_export()
{
    int i;
    int j;
    char *vari;
    i = 1;
    j = 1;
    if (!g_info->cmd->s_cmd[j])
    {
        printf("inside\n");
    }
    while (g_info->cmd->s_cmd[j])
    {
        if (g_info->cmd->s_cmd[j][0] == '_' || ft_isalpha(g_info->cmd->s_cmd[j][0]) == 1)
        {
            while (g_info->cmd->s_cmd[j][i] != '=' && g_info->cmd->s_cmd[j][i])
            {
                if (!(g_info->cmd->s_cmd[j][i] == '_') && !(ft_isalnum(g_info->cmd->s_cmd[j][i])))
                {
                    printf("%d wrong\n",i);
                    exit(0);
                }
                i++;
            }
            vari = ft_var(i, j);
            change_env(vari, NULL, j);
        }
        else
        {
            printf("not vaild key\n");
            exit(1);
        }
        j++;
    }
    
}