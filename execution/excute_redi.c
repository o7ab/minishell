#include "../includes/minishell.h"

int ft_strcmp(char *s1, char *s2)
{
  size_t i;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] && s2[i]))
  {
    i++;
  }
  if (s1[i] == '\n')
    i--;
  return (s1[i] - s2[i]);
}

// signal(SIG_INT, &handler);
int    ff(int i)
{
    int fd;

    fd  = 0;
    if (g_info->cmd->files[i] && i != 0)
    {
        if ((fd = open(g_info->cmd->files[i], O_RDWR | O_CREAT , 0644)) < 0)
        {
            printf("%s\n",strerror(errno));
            return (1);
        }
    }
    return (fd);
}

void    ft_is_heredoc(int i)
{
    int pip[2];
    char *s;

    if (g_info->cmd->redir[i][1] == '<')
    {
        if(pipe(pip) < 0)
            write(2, "ERROR IN PIPE()\n", 17);
        ff(i);
        s = get_next_line(STDIN_FILENO);
        while (s)
        {
            if (ft_strcmp(s, g_info->cmd->files[0]) == 0)
                break;
            write(pip[1], s, strlen(s));
            s = get_next_line(STDIN_FILENO);
        }
        dup2(pip[0], STDIN_FILENO);
        close(pip[0]);
        close(pip[1]);
        if (g_info->cmd->files && i != 0)
        {
            dup2(ff(i), STDOUT_FILENO);
            close(pip[1]);
            close(pip[0]);
        }
    }
}

void    redir()
{
    int fd;
    int i;

    i = 0;
    fd = 0;
    if (g_info->cmd->redir)
    {
        while (g_info->cmd->redir[i])
        {
            if(g_info->cmd->redir[i][0] == '<')
            {
                if (g_info->cmd->redir[i][1] == '<')
                    ft_is_heredoc(i);
                else 
                {
                    if ((fd = open(g_info->cmd->files[i], O_RDONLY)) < 0)
                        printf("Error\n");
                    if (dup2(fd, STDIN_FILENO) < 0)
                        printf("%s\n",strerror(errno));
                    close(fd);
                }
            }
            if(g_info->cmd->redir[i][0] == '>')
            {
                if ((fd = open(g_info->cmd->files[i], O_CREAT | O_APPEND | O_WRONLY)) < 0)
                    printf("Error\n");
                if (dup2(fd, STDOUT_FILENO) < 0)
                    printf("%s\n",strerror(errno));
                close(fd);
            }
            i++;
        }
    }
}