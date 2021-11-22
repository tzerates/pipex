/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:58:45 by tristan           #+#    #+#             */
/*   Updated: 2021/10/25 01:36:55 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char   *ft_error(t_pipex *pipex, char *s)
{
    ft_putstr_fd(s,0);
    if (pipex->in > 0)
		close(pipex->in);
	if (pipex->out > 0)
		close(pipex->out);
	if (pipex->pipefd[0] > 0)
		close(pipex->pipefd[0]);
	if (pipex->pipefd[1] > 0)
		close(pipex->pipefd[1]);
	exit(EXIT_FAILURE);
}

void ft_perror(char* s)
{
    perror(s);
    exit(EXIT_FAILURE);
}

static char *get_env_path(char** env)
{
    unsigned int    i;

    i = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0)
            return(ft_substr(env[i], 5, ft_strlen(env[i])));
        i++;
    }
    ft_perror("Erreur d'environnement, chemin non trouvé.");
    return(NULL);
}

static t_pipex ft_init(char** av, char** env)
{
    t_pipex pipex;
    
    ft_memset(&pipex, 0, sizeof(pipex));
    pipex.in = open_r(av[1]);
    pipex.out = open_w(av[4]);
    pipex.cmd1 = av[2];
    pipex.cmd2 = av[3];
    pipex.path = get_env_path(env);
    if (pipex.path == NULL)
        ft_perror("Aucun chemin trouvé");
    pipex.env = env;
    return(pipex);
}

int main(int ac, char** av, char** env)
{
    t_pipex pipex;

    if (ac != 5)
    {
        ft_perror("Mauvais nombre d'arguments, veuillez respecter la forme :' ./pipex file1 cmd1 cmd2 file2' \n");
        exit(EXIT_FAILURE);
    }
    pipex = ft_init(av, env);
    if (pipe(pipex.pipefd) == -1)
        ft_perror("Echec de la création du pipe");
    cmd_1(&pipex);
    cmd_2(&pipex);
    free(pipex.path);
}
