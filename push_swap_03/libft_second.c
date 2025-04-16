/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:51:15 by hshimoma          #+#    #+#             */
/*   Updated: 2025/04/16 20:56:43 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strncpy(char *dst, const char *src, int size)
{
	int	i;

	i = 0;
	while (i < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	**copy_words(const char *str, char **arr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
				|| str[i] == '\n'))
			i++;
		j = i;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t'
			&& str[i] != '\n')
			i++;
		if (i != j)
		{
			arr[k] = (char *)malloc(sizeof(char) * (i - j + 1));
			if (arr[k] == NULL)
				return (NULL);
			ft_strncpy(arr[k++], &str[j], (i - j));
		}
	}
	arr[k] = NULL;
	return (arr);
}

char	**ft_split(const char *str)
{
	char	**arr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
				|| str[i] == '\n'))
			i++;
		if (str[len] != '\0')
			len++;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t'
			&& str[i] != '\n')
			i++;
	}
	arr = (char **)malloc(sizeof(char *) * (len + 1));
	if (arr == NULL)
		return (NULL);
	return (copy_words(str, arr));
}

void	free_split(char **arr)
{
	int i;

	i = 0;
	if(!arr || !*(arr))
		return ;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}