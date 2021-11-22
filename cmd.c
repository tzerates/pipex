/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:13:15 by tristan           #+#    #+#             */
/*   Updated: 2021/11/22 15:06:32 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_w(char *av)
{
	int	fd;

	fd = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		ft_perror( "Erreur avec l'outfile: N'a pas pu ouvrir et lire celui-ci");
	return (fd);
}

int	open_r(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_perror("Erreur avec l'infile, N'a pas pu ouvrir et lire celui-ci");
	return (fd);
}

int	cmd_1(t_pipex *pipex)
{
	char	**cmd;
	char	*binary;

	cmd = ft_split(pipex->cmd1, ' ');
	if (cmd == NULL)
		ft_perror("Split a échoué en cmd1");
	binary = pathing(pipex, cmd[0]);
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
	{
		dup2(pipex->in, STDIN_FILENO);
		dup2(pipex->pipefd[1], STDOUT_FILENO);
		execve(binary, cmd, pipex->env);
		ft_perror("N'a pas pu éxécuter en cmd1");
	}
	waitpid(pipex->pid1, NULL, 0);
	close(pipex->in);
	close(pipex->pipefd[1]);
	pipex->pipefd[1] = -1;
	ft_free_split(cmd);
	free(binary);
	return (0);
}

int	cmd_2(t_pipex *pipex)
{
	char	**cmd;
	char	*binary;

	cmd = ft_split(pipex->cmd2, ' ');
	if (cmd == NULL)
		ft_perror("Split a échoué en cmd2");
	binary = pathing(pipex, cmd[0]);
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
	{
		dup2(pipex->pipefd[0], STDIN_FILENO);
		dup2(pipex->out, STDOUT_FILENO);
		execve(binary, cmd, pipex->env);
		ft_perror("N'a pas pu éxécuter en cmd2");
	}
	waitpid(pipex->pid2, NULL, 0);
	close(pipex->out);
	close(pipex->pipefd[0]);
	pipex->pipefd[0] = -1;
	ft_free_split(cmd);
	free(binary);
	return (0);
}
