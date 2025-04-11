/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:57:34 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/19 17:22:51 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//リストを繰り返し処理し、各ノードの内容に関数fを適用する関数

#include "libft.h"

// #include <stdlib.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
	{
		return ;
	}
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
