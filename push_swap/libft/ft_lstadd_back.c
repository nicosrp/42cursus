/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:48:22 by nsherpa           #+#    #+#             */
/*   Updated: 2023/02/17 18:01:08 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*search;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		search = ft_lstlast(*lst);
		search->next = new;
	}
}
