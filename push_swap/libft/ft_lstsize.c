/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:31:43 by nsherpa           #+#    #+#             */
/*   Updated: 2023/02/17 18:02:22 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*next_node;

	next_node = lst;
	count = 0;
	while (next_node != NULL)
	{
		count++;
		next_node = next_node->next;
	}
	return (count);
}
