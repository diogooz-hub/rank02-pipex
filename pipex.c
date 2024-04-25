/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:25:05 by dpaco             #+#    #+#             */
/*   Updated: 2023/11/07 22:19:52 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_process(char *cmd, char **env)
{
	char	*path;
	char	**cmd_array;

	cmd_array = ft_split(cmd, ' ');
	path = find_path(cmd_array[0], env);
	if (execve(path, cmd_array, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd_array[0], 2);
		ft_clean(cmd_array);
		exit (EXIT_FAILURE);
	}
}

void	child_process(int *p_fd, char **av, char **env)
{
	int	fd;

	fd = open(av[1], O_RDONLY, 0777);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	execute_process(av[2], env);
}

void	parent_process(int *p_fd, char **av, char **env)
{
	int	fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	execute_process(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	int		status;
	pid_t	pid;

	if (ac != 5)
		error_exit(1);
	if (pipe(p_fd) == -1)
		error_exit(2);
	pid = fork();
	if (pid == -1)
		error_exit(3);
	if (pid == 0)
		child_process(p_fd, av, env);
	else
	{
		waitpid(pid, &status, 0);
		parent_process(p_fd, av, env);
	}
	return (0);
}
