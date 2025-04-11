/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:55:54 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 00:25:17 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//指定したノードとその後全てのノードを削除、メモリを解放する関数

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clear;

	if (lst == NULL || del == NULL)
	{
		return ;
	}
	while (*lst != NULL)
	{
		clear = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = clear;
	}
	*lst = NULL;
}
