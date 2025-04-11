/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:07:57 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/19 00:55:53 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// little文字列内の(big)部分文字列を探す

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	big_len;
	size_t	lit_len;

	if ((big == NULL && len != 0) || little == NULL)
		ft_strlen(NULL);
	if (big == NULL && len == 0)
		return (NULL);
	big_len = ft_strlen(big);
	lit_len = ft_strlen(little);
	if (lit_len == 0)
		return ((char *)big);
	if (big_len < lit_len || len < lit_len)
		return (NULL);
	i = 0;
	while (i <= len - lit_len && big[i])
	{
		if (big[i] == little[0] && !ft_strncmp(&big[i], little, lit_len))
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

// test
// void test_strnstr(const char *big, const char *little, size_t len) {
//     char *result = ft_strnstr(big, little, len);
//     if (result != NULL)
//     {
//         printf("Searching for '%s' in '%s' (len=%zu): Found at '%s'\n",
// 	little, big, len, result);
// 			}
// 			else
// 			{
// 			  printf("Searching for '%s' in '%s' (len=%zu): Not found\n",
// 		little,
// 	big, len);
// 			}
// 	}

// #include <string.h>

// 	int main(void)
// 	{
// 		// printf("World %s\n",ft_strnstr("Hello", "World", 5));
// 		printf("World %s\n",ft_strnstr(NULL, "1", 0));
// 		//  test_strnstr("Hello, World!", "World", 13); // Found at "World!"
// 		//  test_strnstr("Hello, World!", "Hello", 5);  // Found at "Hello"
// 		//  test_strnstr("Hello, World!", "lo", 5);     // Found at "lo, World!"
// 		//  test_strnstr("Hello, World!", "o, W", 10);   // Found at "o, World!"
// 		//  test_strnstr("Hello, World!", "", 10);       // Found at "Hello,
// 		// // World!"
// 		//  test_strnstr("Hello, World!", "NotFound", 10); // Not found

// 			return (0);
// 	}
