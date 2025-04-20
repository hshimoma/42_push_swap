/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:24:39 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/23 00:58:56 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//領域を確保して文字を連結させる

#include "libft.h"

static void	join_help(char *arr, char const *s1, char const *s2)
{
	size_t			i;
	size_t			j;
	const size_t	s1_len = ft_strlen(s1);
	const size_t	s2_len = ft_strlen(s2);

	i = 0;
	while (i < s1_len)
	{
		arr[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
	{
		arr[i + j] = s2[j];
		j++;
	}
	arr[i + j] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	arr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (arr == NULL)
	{
		return (NULL);
	}
	join_help(arr, s1, s2);
	return (arr);
}

//todo
//ヌル処理必要？join_help