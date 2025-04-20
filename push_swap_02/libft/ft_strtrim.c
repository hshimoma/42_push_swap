/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:15:55 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/23 01:04:36 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// setからc文字を切り取る

#include "libft.h"

static int	set_search(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/*
aabb12456ab, ab
4, 2
12456
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*arr;
	size_t	k;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	j = ft_strlen(s1);
	while (s1[i] != '\0' && set_search(s1[i], set))
		i++;
	while (j > i && set_search(s1[j - 1], set))
		j--;
	arr = (char *)malloc((j - i + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	k = 0;
	while (i < j)
		arr[k++] = s1[i++];
	arr[k] = '\0';
	return (arr);
}

//todo
//set_searchのヌル処理は必要？