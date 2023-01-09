#include "minishell.h"

void    redir()
{
    int pid;
    char *path;

    pid = fork();
    path = get_path();
    if (pid == 0)
    {
        int fd;
        if ((fd = open(g_info->cmd->files[0], O_RDONLY)) < 0)
            printf("Error\n");
        if (dup2(fd, STDIN_FILENO) < 0)
            printf("Erro from dup2 \n");
        close(fd);
        // int i = 0;
        // while (g_info->cmd)
        // {
        //     i = 0;
        //     while (g_info->cmd->s_cmd[i])
        //     {
                printf("this is cmd %s\n",g_info->cmd->full_cmd);
        //         i++;
        //     }
        //     g_info->cmd = g_info->cmd->next;
        // }
        
        if(execve(put_cmd_in_path(g_info->cmd->s_cmd[0], path), g_info->cmd->s_cmd, NULL) < 0)
        { 
            write(2, "ERROR IN excv1()\n", 17);
            exit(1);
        }
    }
    wait(0);
    // return 0;
    // int i;

    // i = 0;
    // while (g_info->cmd)
    // {
    //     i = 0;
    //     while (g_info->cmd->files[i])
    //     {
    //         printf("this is redir %s\n",g_info->cmd->files[i]);
    //         i++;
    //     }
    //     g_info->cmd = g_info->cmd->next;
    // }
}