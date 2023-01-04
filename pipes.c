#include "minishell.h"

void    one_pipe(t_cmd **input, t_info **info)
{
  (void)input;
      // Get the value of the PATH environment variable
      char *path = get_path();
    // printf("%s\n",path);
    // Find the length of the PATH variable
    int i = ft_strlen(path);
    printf("%d\n",i);
    // Find the length of the command name
    int j = 0;

    while (j < info[0]->n_cmd)
    {
      // printf("%d\n",info[0]->n_cmd);
      j++;
    }
    
    // Allocate memory for the full path of the program
    // Iterate over the PATH variable
      // Find the next directory in the PATH
      // Concatenate the directory and the program name
      // Check if the program is executable
      // Try the next directory
  // If execve returns, it means the program was not found
}