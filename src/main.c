/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:23:12 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/16 11:47:48 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "../libft/libft.h"
#include "ft_print.h"
#include <locale.h>

int ft_printf(char *str, ...)
{
	va_list ap;
	int i;
	t_vars	e;
	
	e.totcount = 0;
	i = -1;
	va_start(ap, str);
	while (str[++i] != '\0')
	{
		if (str[i] != '%')
			e.totcount = ft_putchar_count(str[i]);
		if(str[i] == '%')
		{
			i++;
			e = ft_printtype(str, &i);
			typeformat(&e);
			ft_error_handle(&e);
			ftprint(ap, &e);
		}
	}
	va_end(ap);

	return (e.totcount);
}

/*
int main(void)
{

	setlocale (LC_ALL, "");
	wchar_t		*i;
	wchar_t		c;
	i = L"✰ 〶e●";
	c = L'⦿';
	ft_printf("%s%#x", "This is the moment of truth, a number: ", 100);
	//printf("\nThis is it: %d", printf(""));
	return 0;
}*/
