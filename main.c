/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:23:12 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/05 18:10:33 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "./libft/libft.h"

int ft_printf(char *str, ...)
{
	int val = 0;
	va_list ap;
	int i;

	i = -1;
	va_start(ap, str);
	while(str[++i])
	{
		if(str[i] == '%' && str[i + 1] == 'd')
		{
			ft_putnbr(va_arg(ap, int));
			i++;
		}
		else if(str[i] == '%' && str[i + 1] == 's')
		{
			ft_putstr(va_arg(ap, char *));
			i++;
		}
		else
			ft_putchar(str[i]);
	}
	va_end(ap);

	return val;
}


int main(void)
{
	ft_printf("This is a string: %s \nThis is a number: %d \n", "It's workin", 42);
	ft_base(1000, 16, BASE16);
	return 0;
}
