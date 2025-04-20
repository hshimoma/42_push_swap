/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:54:50 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 00:15:25 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ノードをリストの最後に追加します

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (lst == NULL || new == NULL)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		back = ft_lstlast(*lst);
		back->next = new;
	}
}
