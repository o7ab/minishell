#include "../includes/minishell.h"

void    change_value_expo(int i, int m)
{
    int j;

    j = 0;
    while (g_info->cmd->s_cmd[m][j])
        j++;
    g_info->expor[i] = malloc((j + 1) * sizeof(char));
    j = 0;
    while (g_info->cmd->s_cmd[m][j])
    {
        g_info->expor[i][j] = g_info->cmd->s_cmd[m][j];
        j++;
    }
    g_info->expor[i][j] = '\0';
}

int     is_inside_expo(char *key)
{
    int i;
    
    i = 0;
    while (g_info->expor[i])
    {
        if ((ft_strncmp(g_info->expor[i], key, ft_strlen(key))) == 0)
            return(i);
        i++;
    }
    return(0);
}

char    **ft_create_expo(int len, char *key, int m)
{
    char **new_envi;
    int i;
    int index;

    i = 0;
    index = is_inside_expo(key);
    if (index == 0)
    {
        new_envi = malloc(sizeof(char *) * (len + 2));
        if (!new_envi)
            return (NULL);
        while (g_info->expor[i])
        {
            new_envi[i] = g_info->expor[i];
            i++;
        }
        new_envi[i] = ft_strdup(g_info->cmd->s_cmd[m]);
        i++;
        new_envi[i] = NULL;
        g_info->expor = new_envi;
    }
    else
        change_value_expo(index, m);
    return(new_envi);
}

void    add_export(char *select, int i, int j)
{
    ft_create_expo(i, select, j);
}

void    change_expo(char *select, int j)
{
    int i;

    i = 0;
    while (g_info->expor[i])
    {
        if ((ft_strncmp(g_info->expor[i], select, ft_strlen(select))) == 0)
        {
            add_export(select, i, j);
            break;
        }
        i++;
    }
    add_export(select, i, j);
}