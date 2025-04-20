/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:56:23 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/19 19:03:41 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1個のノードに関数を当てはめる関数

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
	{
		return ;
	}
	del(lst->content);
	free(lst);
	lst = NULL;
}
