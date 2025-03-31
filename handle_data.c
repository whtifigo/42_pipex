/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matda-co <matda-co@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:11:36 by matda-co          #+#    #+#             */
/*   Updated: 2025/03/11 13:11:56 by matda-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_rest(char **rest)
{
	size_t	i;

	i = 0;
	while (rest[i])
	{
		free(rest[i]);
		i++;
	}
	free(rest);
}

void	exit_error(char *msg, char **to_free)
{
	if (msg)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	if (to_free)
		free_rest(to_free);
	exit(EXIT_FAILURE);
}

int	file_open(char *file, int inout)
{
	int	fd;

	fd = 0;
	if (inout == 0)
		fd = open(file, O_RDONLY, 0644);
	else if (inout == 1)
		fd = open(file, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	else if (fd == -1)
		exit_error("Error opening file", NULL);
	else
		exit_error("Can't open file / Invalid open flag", NULL);
	return (fd);
}

char	**get_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) != envp[i])
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*pathing;
	char	*path_full;
	char	**pathen;

	i = 0;
	pathen = get_env(envp);
	if (!pathen)
		return (NULL);
	while (pathen[i])
	{
		pathing = ft_strjoin(pathen[i], "/");
		path_full = ft_strjoin(pathing, cmd);
		free(pathing);
		if (access(path_full, X_OK) == 0)
			return (path_full);
		free(path_full);
		i++;
	}
	i = -1;
	while (pathen[++i])
		free(pathen[i]);
	free(pathen);
	return (NULL);
}
