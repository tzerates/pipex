/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:40:51 by tristan           #+#    #+#             */
/*   Updated: 2021/10/25 01:23:21 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*parse_file(char *cmd, char *directory)
{
	char	*path;
	char	*entire_path;

	if (directory[ft_strlen(directory) - 1] == '/')
		path = ft_strdup(directory);
	else
		path = ft_strjoin(directory, "/");
	if (path == NULL)
		exit_error("Entire path Error\n");
	entire_path = ft_strjoin(path, cmd);
	if (entire_path == NULL)
		exit_error("Entire path Error: Empty path\n");
	free(path);
	return (entire_path);
}

static char	*parse_dir(t_pipex *pipex, char *cmd)
{
	size_t	index;
	char	**dir;
	char	*path;

	index = 0;
	dir = ft_split(pipex->path, ':');
	if (dir == NULL)
		exit_error("Split Error: Directory error\n");
	while (dir[index])
	{
		path = parse_file(cmd, dir[index]);
		if (access(path, R_OK) != 0)
			free(path);
		else
		{
			ft_free_split(dir);
			return (path);
		}
		index++;
	}
	ft_free_split(dir);
	return (ft_error(pipex, "Path Error: Path does not exist\n"));
}

char	*pathing(t_pipex *pipex, char *cmd)
{
	char	*path;

	if (cmd[0] == '/' || cmd[0] == '.' || cmd[0] == '~')
	{
		path = ft_strdup(cmd);
		if (path == NULL)
			ft_perror("Erreur de pathing : NULL path\n");
		return (path);
	}
	return (parse_dir(pipex, cmd));
}
