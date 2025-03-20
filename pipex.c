#include "pipex.h"

void	exec(char *cmd, char **envp)
{
	char	**com;
	char	*path;

	com = ft_split(cmd, ' ');
	if(!com)
		exit_error("split failed", NULL);
	path = get_path(com[0], envp);
	if(!path)
	{
		ft_putstr_fd("Command not found", 2);
		ft_putstr_fd(com[0], 2);
		free_rest(com);
		exit(EXIT_FAILURE);
	}
	if(execve(path, com, envp) == -1)
		exit_error("Failed to execute", com);
}

void	child ()

void	parent()

int	main
