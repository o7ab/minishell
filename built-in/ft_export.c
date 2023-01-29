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

void    ft_add_expo_only(char *key)
{
    int i;
    char **new;

    i = 0;
    while (g_info->expor[i])
        i++;
    new = malloc(sizeof(char *) * (i + 2));
    i = 0;
    while (g_info->expor[i])
    {
        new[i] = ft_strdup(g_info->expor[i]);
        i++;
    }
    new[i] = ft_strdup(key);
    i++;
    new[i] = NULL;
    free_double(g_info->expor);
    g_info->expor = new;
}

char    *ft_separat_key(int m)
{
    int i;
    char *vari;

    i = 1;
    while (g_info->cmd->s_cmd[m][i] != '=' && g_info->cmd->s_cmd[m][i])
    {
        if (!(g_info->cmd->s_cmd[m][i] == '_') && !(ft_isalnum(g_info->cmd->s_cmd[m][i])))
        {
            printf("%d wrong\n",i);
            exit(0);
        }
        i++;
    }
    vari = ft_var(i, m);
    if (g_info->cmd->s_cmd[m][i] == '\0')
        ft_add_expo_only(vari);
    else
    {
        change_env(vari, NULL, m);
        change_expo(vari, m);
    }
    return (vari);
}

void    ft_export()
{
    int j;

    j = 1;
    while (g_info->cmd->s_cmd[j])
    {
        if (g_info->cmd->s_cmd[j][0] == '_' || ft_isalpha(g_info->cmd->s_cmd[j][0]) == 1)
            ft_separat_key(j);
        else
        {
            printf("not vaild key\n");
            exit(1);
        }
        j++;
    }
    if (!g_info->cmd->s_cmd[1])
    {
        j = 0;
        while (g_info->expor[j])
        {
            printf("declare -x %s\n",g_info->expor[j]);
            j++;
        }
    }
}