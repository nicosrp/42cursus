/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:39:45 by nsherpa           #+#    #+#             */
/*   Updated: 2023/03/13 18:21:47 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlenpf(const char *str);
void	ft_putcharpf(char c);
void	ft_putstrpf(char *str);
void	ft_putnbrpf(int i);
int		ft_checkpf(char c, va_list *list);
int		ft_checkpf2(char c, va_list *list);
int		ft_checkpf3(char c, va_list *list);
void	ft_putunbrpf(unsigned int n);
int		ft_lenuint(unsigned int n);
int		ft_lenint(int i);
int		ft_putnbrpf_hex(unsigned int u, char c);
int		ft_ptrpf(uintptr_t u);

#endif
