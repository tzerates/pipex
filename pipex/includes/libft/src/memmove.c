/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:05:46 by tristan           #+#    #+#             */
/*   Updated: 2021/11/22 23:05:47 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove( void *dest, const void *src, size_t n)
{
	if (src < dest)
		while (n--)
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
