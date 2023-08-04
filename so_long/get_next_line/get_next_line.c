/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <nsherpa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:07:43 by nsherpa           #+#    #+#             */
/*   Updated: 2023/08/04 18:48:28 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	int		rd;
	char	c;
	char	*buffer;

	buffer = malloc(10000);
	i = 0;
	rd = 0;
	if (BUFFER_SIZE <= 0)
		return (free(buffer), NULL);
	rd = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1);
	while (rd > 0)
	{
		buffer[i++] = c;
		if (c == '\n')
			break ;
		rd = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1);
	}
	if ((!buffer[i - 1] && !rd) || rd == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}
