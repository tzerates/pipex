/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:02:38 by tristan           #+#    #+#             */
/*   Updated: 2021/11/22 23:02:40 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	norme_gnl(char *reste, int i, int *j, char *new)
{
	while (reste[i + *j])
	{
		new[*j] = reste[i + *j];
		(*j)++;
	}
}
