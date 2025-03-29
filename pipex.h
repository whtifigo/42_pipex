/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matda-co <matda-co@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:17:33 by matda-co          #+#    #+#             */
/*   Updated: 2025/03/11 13:18:01 by matda-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

void	free_rest(char **rest);
void	exit_error(char*msg, char **to_free);
int		file_open(char *file, int inout);
char	**get_env(char **envp);
char	*get_path(char *cmd, char **envp);
void	exec(char *cmd, char **envp);
#endif
