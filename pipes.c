#include "minishell.h"

char  *put_cmd_in_path(char *cmd, char *path)
{
  char **sp;
  int i;
  int l;
  int m;
  char *cmd_with_cmd;
  int len_path;
  int len_cmd;

  i = 0;
  l = 0;
  m = 0;
  sp = ft_split_set(path,":");
  len_cmd = ft_strlen(cmd);
  while (sp[i])
  {
    len_path = ft_strlen(sp[i]);
    l = 0;
    m = 0;
    cmd_with_cmd = malloc((len_cmd + len_path + 2) * sizeof(char));
    while (l < len_path)
    {
      cmd_with_cmd[l] = sp[i][l];
      l++;
    }
    cmd_with_cmd[l++] = '/';
    while (m < len_cmd)
    {
      cmd_with_cmd[l] = cmd[m];
      l++;
      m++;
    }
    cmd_with_cmd[l] = '\0';
    if (access(cmd_with_cmd,X_OK) == 0)
      return (cmd_with_cmd);
    i++;
    free(cmd_with_cmd);
  }
  return (NULL);
}

void    one_pipe()
{
  int i;
  char *path;
  int pid;
  int fd[2];

  i = 0;
  pid = 0;
  path = get_path();
  if (pipe(fd) < 0)
  {
    write(2, "Error IN Pipe\n",14);
  }
  while (i < g_info->n_cmd)
  {
    if (g_info->cmd_struct->s_cmd[0] && put_cmd_in_path(g_info->cmd_struct->s_cmd[0], path) != NULL)
    {
      pid = fork();
      if (pid == 0)
      {
        if ( i == 0 )
        {
          dup2(fd[1], STDOUT_FILENO);
          close(fd[1]);
          close(fd[0]);
        }
        else if ( i == 1 )
        {
          dup2(fd[0], STDIN_FILENO);
          close(fd[0]);
          close(fd[1]);
        }
        if(execve(put_cmd_in_path(g_info->cmd_struct->s_cmd[0], path), g_info->cmd_struct->s_cmd, NULL) < 0)
        {
          write(2, "ERROR IN excv1()\n", 17);
          exit(1);
        }
      }
      else if (pid > 0)
      {
          if( i == 0)
              close(fd[1]);
          if( i == 1)
              close(fd[0]);
      }
      else
      {
          write(2, "ERROR IN FORK()\n", 17);
      }
    }
    i++;
    g_info->cmd_struct = g_info->cmd_struct->next;
  }
  i = 0;
  while(i < 2)
  {
      wait(NULL); 
      i++;
  }
}