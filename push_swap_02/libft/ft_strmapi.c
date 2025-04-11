/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:06:09 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 17:35:47 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//第２引数の関数ポインタを適用して文字列を変換する関数

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*arr;
	size_t	i;
	size_t	j;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	arr = (char *)malloc((i + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		arr[j] = f(j, s[j]);
		j++;
	}
	arr[j] = '\0';
	return (arr);
}
