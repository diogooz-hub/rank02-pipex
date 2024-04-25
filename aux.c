/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:24:58 by dpaco             #+#    #+#             */
/*   Updated: 2023/11/07 23:15:51 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(int n)
{
	if (n == 1)
		perror("Type this noob: ./pipex infile cmd1 cmd2 outfile\n");
	else if (n == 2)
		perror("Error creating pipe\n");
	else if (n == 3)
		perror("Error creating fork");
	exit (EXIT_FAILURE);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_clean(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free (array[i]);
		i++;
	}
	free (array);
}

char	*search_env(char *env_name, char **env)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (env[i])
	{
		n = 0;
		while (env[i][n] && env[i][n] != '=')
			n++;
		if (ft_strncmp(env[i], env_name, n) == 0)
			return (&(env[i][n + 1]));
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **env)
{
	int		i;
	char	**allpaths;
	char	*path;
	char	*exec_path;

	i = 0;
	allpaths = ft_split(search_env("PATH", env), ':');
	while (allpaths[i])
	{
		path = ft_strjoin(allpaths[i], "/");
		exec_path = ft_strjoin(path, cmd);
		free(path);
		if (access(exec_path, F_OK | X_OK) == 0)
		{
			ft_clean(allpaths);
			return (exec_path);
		}
		free(exec_path);
		i++;
	}
	ft_clean(allpaths);
	return (cmd);
}
