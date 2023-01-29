#include "../includes/minishell.h"

void    ft_put_equal(int *k, int j, int i, int *m)
{
    g_info->env[i][j] = '=';
    (*k) = 0;
    (*m) = 0;
}

void    add_env_norm(char *select, char *value, size_t len, int i)
{
    size_t j;
    int m;
    int k;

    m = 0;
    k = 0;
    j = 0;
    while (j < len)
    {
        if (j < ft_strlen(select))
        {
            g_info->env[i][j] = select[j];
            k = 1;
        }
        else
        {
            if (k)
                ft_put_equal(&k, j, i, &m);
            else
                g_info->env[i][j] = value[m];
        }
        j++;
        m++;
    }
    g_info->env[i][j] = '\0';
}

void    add_env(char *select, char *value, int i, int j)
{
    size_t len;

    len = 0;
    if (value)
    {
        len = ft_strlen(value) + ft_strlen(select) + 1;
        g_info->env[i] = malloc((len + 1) * sizeof(char));
        add_env_norm(select, value, len, i);
    }
    else
        ft_create_var(i, select, j);
}


void    alloc_export()
{
    int i;

    i = 0;
    while (g_info->env[i])
        i++;
    g_info->expor = malloc(sizeof(char *) * (i + 1));
     i =0;
    while (g_info->env[i])
    {
        g_info->expor[i] = ft_strdup(g_info->env[i]);
        i++;
    }
    g_info->expor[i] = NULL;
}