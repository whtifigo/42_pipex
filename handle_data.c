#include "../pipex.h"

exit

void	free_rest(char *rest)
{
	size_t	i;

	i = 0;
	while (rest[i])
	{
		free(rest[i])
		i++;
	}
	free(rest);
}

file (opener in and out)

char	**get_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) != envp[i]) 
	       i++;

	if (!envp[i])
		return (NULL);

	return (ft_split(envp[i] + 5, ":"));
}

char	*get_path(char *cmd, char **envp)
{
	int	i;
	char	*pathing;
	char	*path_full;
	char	**pathen;

	i = 0;
	pathen = get_env(envp)
	if (!pathen)
		return NULL;
	while (pathen[i])
	{
		pathing = ft_strjoin(pathen[i], "/");
		path_full = ft_strjoin(pathing, cmd);
		free(pathing);
		if (access(path_full, F_OK) == 0)
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
