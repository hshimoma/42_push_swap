/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:20:12 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 00:06:12 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//文字を大文字に変換

#include "libft.h"

int	ft_toupper(int c)
{
	char	s;

	s = 'a';
	while (s <= 'z')
	{
		if (c == s)
		{
			return (s - 32);
		}
		s++;
	}
	return (c);
}

// #include <stdio.h>

// int main(void)
// {
//     char low = 'a';
//     char up = ft_toupper(low);

//     printf("オリジナル %c,upcase %c\n",low,up);
//     return (0);
// }
