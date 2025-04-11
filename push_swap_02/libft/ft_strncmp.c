/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:07:09 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/23 01:00:43 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// n文字分までs１s２を比較する

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && ((s1[i] != '\0') || (s2[i] != '\0')))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (i < n)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	else
	{
		return (0);
	}
}

// #include <stdio.h>
// #include <string.h>

// int main(void)	//tasecase1
// {
//     const char *s1 = "hello";
//     const char *s2 = "hello";
//     int result = ft_strncmp(s1, s2, 5);
//     printf("Test Case 1: %d\n", result); // 期待される出力: 0
//     return (0);
// }

// int main(void)	//testcase2
// {
//     const char *s1 = "apple";
//     const char *s2 = "banana";
//     int result = ft_strncmp(s1, s2, 5);
//     printf("Test Case 2: %d\n", result); // 期待される出力: 負の値
//     return (0);
// }

// int main(void)	//testcase3
// {
//     const char *s1 = "hello world";
//     const char *s2 = "hello everyone";
//     int result = ft_strncmp(s1, s2, 5);
//     printf("Test Case 3: %d\n", result); // 期待される出力: 0
//     return (0);
// }
