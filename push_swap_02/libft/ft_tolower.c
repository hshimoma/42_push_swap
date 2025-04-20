/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:19:55 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/11 20:20:00 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//文字を小文字に変換

#include "libft.h"

int	ft_tolower(int c)
{
	char	s;

	s = 'A';
	while (s <= 'Z')
	{
		if (c == s)
		{
			return (s + 32);
		}
		s++;
	}
	return (c);
}

// #include <stdio.h>

// int main(void)
// {
//     char low = 'A';
//     char up = ft_tolower(low);

//     printf("オリジナル %c,upcase %c\n",low,up);
//     return (0);
// }