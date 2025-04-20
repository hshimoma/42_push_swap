/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:11:14 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/18 09:17:33 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//指定されたファイルディスクリプタに整数nを出力する関数

#include "libft.h"

static void	ft_putnbrse(unsigned int nb, int fd)
{
	if (nb > 9)
	{
		ft_putnbrse(nb / 10, fd);
		ft_putchar_fd(nb % 10 + '0', fd);
	}
	else
	{
		ft_putchar_fd(nb + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;

	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == INT_MAX)
	{
		write(fd, "2147483647", 10);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		i = -1 * n;
	}
	else
	{
		i = n;
	}
	ft_putnbrse(i, fd);
}

// int main(void)
// {
//     ft_putnbr_fd(123, 1);
//     write(1, "\n", 1);
//     return (0);
// }
