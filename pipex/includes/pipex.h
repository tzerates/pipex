/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:00:56 by tristan           #+#    #+#             */
/*   Updated: 2021/10/25 12:55:12 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/inc/libft.h"

typedef struct s_pipex
{
	int		in;
	int		out;
	char	*cmd1;
	char	*cmd2;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**env;
	char	*path;
	int		fd_dir;
}				t_pipex;

int		main(int ac, char **av, char **envp);
void	ft_perror(char *s);
char	*ft_error(t_pipex *pipex, char *s);
int		open_r(char *av);
int		open_w(char *av);
int		cmd_1(t_pipex *pipex);
int		cmd_2(t_pipex *pipex);
char	*pathing(t_pipex *pipex, char *cmd_0);

#endif