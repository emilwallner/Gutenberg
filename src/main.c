/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:23:12 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/15 17:13:25 by ewallner         ###   ########.fr       */
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
	va_end(ap);

	return val;
}


int main(void)
{
	int		i;
	i = 'o';
	ft_printf("%10s|", "0123456789");
	printf("%10s|", "0123456789");
	return 0;
}
