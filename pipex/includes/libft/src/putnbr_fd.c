/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:06:30 by tristan           #+#    #+#             */
/*   Updated: 2021/11/22 23:06:31 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (nb >= 0 && nb < 10)
		{
			ft_putchar_fd('0' + nb, fd);
		}
		else if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(nb * (-1), fd);
		}
		else
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putnbr_fd(nb % 10, fd);
		}
	}
}
