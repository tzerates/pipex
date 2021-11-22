/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:02:14 by tristan           #+#    #+#             */
/*   Updated: 2021/11/22 23:02:50 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen2(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_line(char *save)
{
	int	i;

	if (!save)
		return (-1);
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
