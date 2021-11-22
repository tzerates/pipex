/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listadd_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:04:34 by tristan           #+#    #+#             */
/*   Updated: 2021/11/22 23:04:35 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*back;

	back = *alst;
	if (*alst)
	{
		while (back->next != NULL)
			back = back->next;
		back->next = new;
	}
	else
		*alst = new;
}
