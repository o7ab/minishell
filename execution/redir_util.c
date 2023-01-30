#include "../includes/minishell.h"

void	input_redi(int i)
{
	int	fd;

	fd = 0;
	if ((fd = open(g_info->cmd->files[i], O_RDONLY)) < 0)
		printf("Error\n");
	if (dup2(fd, STDIN_FILENO) < 0)
		printf("%s\n",strerror(errno));
	close(fd);
}

void	redir_heredoc(int i)
{
	dup2(ff(i), STDOUT_FILENO);
}