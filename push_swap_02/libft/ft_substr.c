/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:18:11 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/19 19:04:00 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//指定した文字列から部分文字列を取り出す

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;
	size_t	j;

	i = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s);
	if (start >= j)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (len > j - start)
		len = j - start;
	arr = (char *)malloc((len + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		arr[i] = s[start + i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
