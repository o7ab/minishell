#include "../includes/minishell.h"

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
    if (access(cmd_with_cmd, X_OK) == 0)
      return (cmd_with_cmd);
    i++;
    free(cmd_with_cmd);
  }
  return (NULL);
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

int    one_pipe()
{
  int i;
  int pid;
  int **fd;
  int j;

  i = 0;
  j = 0;
  pid = 0;
  if (g_info->cmd->s_cmd[0] == NULL)
  {
    printf("erro");
    return 0;
  }
  if(g_info->n_cmd > 1)
    fd = malloc((g_info->n_cmd - 1) * sizeof(int *));
  while (j < g_info->n_cmd - 1)
  {
    fd[j] = malloc(2 * sizeof(int));
    j++;
  }
  
  while (i < g_info->n_cmd - 1)
  {
    if (pipe(fd[i]) < 0)
    {
      write(1,"Error in the pipes\n",50);
      exit(1);
    }
    i++;
  }
  i = 0;
  if (check_builtin() == 0)
    return (0);
  while (i < g_info->n_cmd)
  {
    pid = fork();
    if (pid == 0)
    {
      if(g_info->n_cmd > 1)
      {
        if (i != 0)
        {
          dup2(fd[i-1][0],STDIN_FILENO);
          close(fd[i-1][0]);
        }
        if (i + 1 < g_info->n_cmd)
        {
          dup2(fd[i][1],STDOUT_FILENO);
          close(fd[i][1]);
          close(fd[i][0]);
        }
      }
      redir();
      if (check_built_in(g_info->cmd->s_cmd[0]) == 1)
      {
        char *path;

        path = ft_getenv("PATH");
        if (path != NULL)
        {
            if (execve(put_cmd_in_path(g_info->cmd->s_cmd[0], path), g_info->cmd->s_cmd, NULL) < 0)
            {
                printf("Bash : Command not found\n");
                exit(1);
            }
        }
      }
      else
        excute_built_in(g_info->cmd->s_cmd[0]);
    }
    else if (pid > 0)
    {
        if( i < g_info->n_cmd - 1)
          close(fd[i][1]);
        if( i > 0)
          close(fd[i - 1][0]);
    }
    i++;
    g_info->cmd = g_info->cmd->next;
  }
  i = 0;
  while(i < g_info->n_cmd)
  {
      wait(NULL); 
      i++;
  }
  return(0);
}