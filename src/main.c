/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:23:12 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/15 00:21:45 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "../libft/libft.h"
#include "ft_print.h"

int ft_printf(char *str, ...)
{
	int val = 0;
	va_list ap;
	int i;
	t_vars	e;
	
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
	va_end(ap);

	return val;
}


int main(void)
{
	int		i;
	i = -123123;
	ft_printf("%.6d|", i);
	printf("%.6d|", i);
	return 0;
}
