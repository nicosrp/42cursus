/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:24:34 by nsherpa           #+#    #+#             */
/*   Updated: 2023/03/22 17:07:48 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>


void	ft_putstr(char *str, int *l)
{
	if (!str)
		str = "(null)";
	while (*str)
		*l +=  write(1, str++, 1);
}

void	ft_putd(long long int i, int base, int *l)
{
	char *hex;
	
	hex = "0123456789abcdef";

	if (i < 0)
	{
		i *= -1;
		l += write(1, "-", 1);
	}
	if (i >= base)
		ft_putd((i/base), base, l);
	*l += write(1, &hex[i % base], 1);
}

int	ft_printf(const char *input, ...)
{
	int l;
	va_list ptr;
	va_start(ptr, input);

	l = 0;
	while(*input)
	{
		if ((*input == '%') && *(input + 1))
		{
			input ++;
			if (*input == 's')
				ft_putstr(va_arg(ptr, char *), &l);
			else if (*input == 'd')
				ft_putd((long long int)va_arg(ptr, int), 10, &l);
			else if(*input == 'x')
				ft_putd((long long int)va_arg(ptr, unsigned int), 16, &l);
		}
		else
			l += write(1, input, 1);
		input ++;
	}
	return (va_end(ptr), l);
}

int main()
{
	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
}
