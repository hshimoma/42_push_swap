/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:15:25 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/23 01:03:37 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//文字列中の文字の位置を特定、最後の

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		target;
	size_t		i;
	const char	*last_ptr = NULL;

	target = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == target)
		{
			last_ptr = &s[i];
		}
		i++;
	}
	if (target == '\0')
	{
		return ((char *)&s[i]);
	}
	return ((char *)last_ptr);
}

int main(void)
{
    const char *str = "Hello, world!";
    char target = 'o';
    char *result = ft_strrchr(str,target);
    if (result != NULL)
    {
        printf("target '%c' 場所: %ld\n",target,result - str);
    }
    else
    {
        printf("target '%c'not found.\n",target);
    }
    return (0);
}