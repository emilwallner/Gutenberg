/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converttype.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:22:51 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/07 20:02:53 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <stdarg.h>
#include "./libft/libft.h"

char		*converttype(t_vars *e, void (*p)(va_list ap))
{
	char *str;
	t_types t;

	(e->f == 18) ? str = (*p[1])(va_arg(ap, char*)) : e->type;
	(e->type == d && e->flags == ll) ? str = (*p[4])(va_arg(ap, int)) : e->type;
	return (str);
}

void		*typeformat(t_vars *e)
{
	(ft_strchr("di", e->type) && e->flags == 0) ? e->f = 1 : e->f;
	(ft_strchr("di", e->type) && e->flags == 1) ? e->f = 2 : e->f;
	(ft_strchr("di", e->type) && e->flags == 2) ? e->f = 3 : e->f;
	(ft_strchr("di", e->type) && e->flags == 3) ? e->f = 4 : e->f;
	(ft_strchr("di", e->type) && e->flags == 4) ? e->f = 5 : e->f;
	(ft_strchr("di", e->type) && e->flags == 5) ? e->f = 6 : e->f;
	(ft_strchr("di", e->type) && e->flags == 6) ? e->f = 7 : e->f;
	(ft_strchr("uoxX", e->type) && e->flags == 0) ? e->f = 8 : e->f;
	(ft_strchr("uoxX", e->type) && e->flags == 1) ? e->f = 9 : e->f;
	(ft_strchr("uoxX", e->type) && e->flags == 2) ? e->f = 10 : e->f;
	(ft_strchr("uoxX", e->type) && e->flags == 3) ? e->f = 11 : e->f;
	(ft_strchr("uoxX", e->type) && e->flags == 4) ? e->f = 12 : e->f;
	(ft_strchr("uoxX", e->type) && e->flags == 5) ? e->f = 13 : e->f;
	(ft_strchr("uoxX", e->type) && e->flags == 6) ? e->f = 14 : e->f;
	(ft_strchr("fFeEgGaA", e->type) && e->flags == 0) ? e->f = 15 : e->f;
	(e->type == 'c' && e->flags == 0) ? e->f = 16 : e->f;
	((e->type == 'c' && e->flags == 4) || e->type == 'C') ? e->f = 17 : e->f;
	(e->type == 's' && e->flags == 0) ? e->f = 18 : e->f;
	((e->type == 's' && e->flags == 4) || e->type == 'S') ? e->f = 19 : e->f;
	(e->type == 'p' && e->flags == 0) ? e->f = 20 : e->f;
}



/*
void		format_and_print(t_vars *e, char *str)
{
	
}
*/


