/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:05:07 by tristan           #+#    #+#             */
/*   Updated: 2021/11/22 23:05:08 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*ele;
	t_list	*prev;

	if (!lst || !f)
		return (NULL);
	first = ft_lstnew(f(lst->content));
	if (!first)
		return (NULL);
	ele = first;
	while (lst->next)
	{
		lst = lst->next;
		prev = ele;
		ele = ft_lstnew(f(lst->content));
		if (ele == NULL)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		prev->next = ele;
	}
	ele->next = NULL;
	return (first);
}
