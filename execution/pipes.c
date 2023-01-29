#include "../includes/minishell.h"

char  *put_cmd_in_path(char *cmd, char *path)
{
  char **sp;
  int i;
  char *cmd_with_cmd;
  int len_path;
  int len_cmd;

  i = 0;
  sp = ft_split_set(path,":");
  len_cmd = ft_strlen(cmd);
  while (sp[i])
  {
    len_path = ft_strlen(sp[i]);
    cmd_with_cmd = ft_put_path(len_path, len_cmd, sp[i], cmd);
    if (access(cmd_with_cmd, X_OK) == 0)
      return (cmd_with_cmd);
    i++;
    free(cmd_with_cmd);
  }
  return (NULL);
}

void	print_quit(int signal)
{
	(void)signal;
	write(1, "Quit: 3\n", 9);
}

int  check_builtin()
{
  if (g_info->n_cmd == 1 && !check_built_in(g_info->cmd->s_cmd[0]))
  {
    redir();
    excute_built_in(g_info->cmd->s_cmd[0]);
    return (0);
  }
  return(1);
}

void  ft_child(int i)
{
  signal(SIGINT, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
  if(g_info->n_cmd > 1)
  {
    if (i != 0)
    {
      dup2(g_info->fd[i-1][0],STDIN_FILENO);
      close(g_info->fd[i-1][0]);
    }
    if (i + 1 < g_info->n_cmd)
    {
      dup2(g_info->fd[i][1],STDOUT_FILENO);
      close(g_info->fd[i][1]);
      close(g_info->fd[i][0]);
    }
  }
  redir();
  excute_command();
}

void  ft_parent(int i)
{
  if( i < g_info->n_cmd - 1)
    close(g_info->fd[i][1]);
  if( i > 0)
    close(g_info->fd[i - 1][0]);
}

int    one_pipe()
{
    int i;
    int pid;

    i = 0;
    pid = 0;
    if (ft_create_fd())
      return(1);
    if (check_builtin() == 0)
      return (0);
    while (i < g_info->n_cmd)
    {
      signal(SIGINT, SIG_IGN);
      signal(SIGQUIT, SIG_IGN);
      pid = fork();
      if (pid == 0)
        ft_child(i);
      else if (pid > 0)
        ft_parent(i);
      i++;
      g_info->cmd = g_info->cmd->next;
    }
    i = 0;
    while(i < g_info->n_cmd)
    {
        wait(NULL); 
        i++;
    }
    signal(SIGINT, &sig_handler);
    signal(SIGQUIT, &sig_handler);
    return(0);
}