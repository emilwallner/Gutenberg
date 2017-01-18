/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:25:37 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/18 22:35:24 by ewallner         ###   ########.fr       */
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
	t_vars e;

	e.totcount = 0;
	va_start(	ap, str);
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
			if(ft_error_handle(&e))
				return (-1);
			typeformat(&e);
			ftprint(ap, &e);
			//ft_printvars(&e);
			if(e.nb)
				free(e.nb);
			e.nb = NULL;
		}
	}
	va_end(ap);
	return (e.totcount);
}

