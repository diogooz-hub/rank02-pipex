/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:38:20 by dpaco             #+#    #+#             */
/*   Updated: 2023/10/25 20:39:39 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

void	child_process(int *p_fd, char **av, char **env);
void	parent_process(int *p_fd, char **av, char **env);
void	execute_process(char *cmd, char **env);
void	ft_clean(char **tab);
void	error_exit(int n);
char	*find_path(char *cmd, char **env);
char	*search_env(char *env_name, char **env);
int		ft_strcmp(const char *s1, const char *s2);

#endif