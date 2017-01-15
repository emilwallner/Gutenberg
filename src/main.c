/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:23:12 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/16 00:23:27 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "../libft/libft.h"
#include "ft_print.h"
#include <locale.h>

int ft_printf(char *str, ...)
{
	int val = 0;
	va_list ap;
	int i;
	t_vars	e;
	
	e.totcount = 0;
	i = -1;
	va_start(ap, str);
	e = ft_parser(str);
	typeformat(&e);
//	ft_printvars(&e);
	printf(">>>\n\n\n");
	ftprint(ap, &e);
	printf("|");
	printf("\n\n\n>>>");
	ft_printvars(&e);
	printf("\nThis is my len: %d\n", e.totcount + 1);
	va_end(ap);

	return val;
}


int main(void)
{

	setlocale (LC_ALL, "");
	wchar_t		*i;
	i = L"✰ 〶e●";
	ft_printf("%.9ls", i);
	printf("\nThis is it: %d", printf("%.9ls|", i));
	return 0;
}
