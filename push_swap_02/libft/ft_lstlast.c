/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:58:08 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 17:04:10 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//リストの最後のノードを取得するための関数、リストの最後にノードを返す

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
