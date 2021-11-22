/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:04:47 by tristan           #+#    #+#             */
/*   Updated: 2021/11/22 23:04:48 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buffer;

	if (*lst == NULL || del == NULL)
		return ;
	buffer = *lst;
	while (buffer != NULL)
	{
		*lst = buffer;
		ft_lstdelone(*lst, del);
		buffer = buffer->next;
	}
	*lst = NULL;
}
