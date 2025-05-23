/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:59:40 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/19 17:19:44 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ノードの数を返す関数＝単方向リストのサイズ

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
