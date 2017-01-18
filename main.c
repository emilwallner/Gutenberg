/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:23:12 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/18 13:15:18 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_print.h"
#include <locale.h>

int ft_printf(char *str, ...)
{
	va_list ap;
	t_vars	e;
	
	e.totcount = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str != '%')
		{
			e.totcount += ft_putchar_count(*str);
			str++;
		}
		else
		{
			str++;
			str = ft_printtype(str, &e);
			typeformat(&e);
			//ft_error_handle(&e);
			ftprint(ap, &e);
			//ft_printvars(&e);
		}
	}
	va_end(ap);

	return (e.totcount);
}


