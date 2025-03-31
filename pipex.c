/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matda-co <matda-co@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:06:44 by matda-co          #+#    #+#             */
/*   Updated: 2025/03/28 11:28:29 by matda-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **envp)
{
	char	**com;
	char	*path;

	com = ft_split(cmd, ' ');
	if (!com || !com[0])
		exit_error("Invalid Command\n", com);
	path = get_path(com[0], envp);
	if (!path)
	{
		exit_error("Command not found", com);
		ft_putstr_fd(com[0], 2);
		ft_putstr_fd("\n", 2);
		free_rest(com);
		free(path);
		exit(EXIT_FAILURE);
	}
	if (execve(path, com, envp) == -1)
	{
		free(path);
		free_rest(com);
		exit_error("Failed to execute", NULL);
	}
	free(path);
	free_rest(com);
}

void	child_process(char **argv, int *pipe_fd, char *cmd, char **envp)
{
	int	fd;

	fd = file_open(argv[1], 0);
	if (fd == -1)
		exit(EXIT_FAILURE);
	close(pipe_fd[0]);
	dup2(fd, 0);
	dup2(pipe_fd[1], 1);
	close(fd);
	close(pipe_fd[1]);
	exec(cmd, envp);
}

void	parent_process(char **argv, int	*pipe_fd, char *cmd, char **envp)
{
	int	fd;

	fd = file_open(argv[4], 1);
	if (fd == -1)
		exit(EXIT_FAILURE);
	close(pipe_fd[1]);
	dup2(fd, 1);
	dup2(pipe_fd[0], 0);
	close(fd);
	close(pipe_fd[0]);
	exec(cmd, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc < 5)
		exit_error("Too few arguments", NULL);
	if (argc > 5)
		exit_error("Too many arguments", NULL);
	if (pipe(pipe_fd) == -1)
		exit_error("Error: Pipe failed", NULL);
	pid = fork();
	if (pid == -1)
		exit_error("Fork failed", NULL);
	if (pid == 0)
		child_process(argv, pipe_fd, argv[2], envp);
	else
	{
		waitpid(pid, NULL, WNOHANG);
		parent_process(argv, pipe_fd, argv[3], envp);
	}
	return (0);
}
