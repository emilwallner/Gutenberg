/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:23:12 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/06 18:33:28 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "./libft/libft.h"
#include "ft_print.h"

int ft_printf(char *str, ...)
{
	int val = 0;
	va_list ap;
	int i;

	i = -1;
	va_start(ap, str);
	ft_parser(str);
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
	}
	va_end(ap);

	return val;
}


int main(void)
{
	//ft_printf("This is a string: %-1238970.54zs9458s \nThis is a number: % -0#hhd \n", "It's workin", 43452345342);
	wchar_t t;
	t = ሴ;
	write(1, &t, 1);
	return 0;
}
