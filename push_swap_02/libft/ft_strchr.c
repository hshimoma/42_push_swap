/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:16:50 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/23 00:57:42 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//文字列中の文字の位置を特定する,最初の

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	target;

	i = 0;
	target = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == target)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (target == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

// #include <stdio.h>

// int main(void)
// {
//     const char *str = "Hello, world!";
//     char target = 'o';
//     char *result = ft_strchr(str,target);
//     if (result != NULL)
//     {
//         printf("target '%c' 場所: %ld\n",target,result - str);
//     }
//     else
//     {
//         printf("target '%c'not found.\n",target);
//     }
//     return (0);
// }