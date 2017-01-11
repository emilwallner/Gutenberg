/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converttype.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:22:51 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/11 23:34:08 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <stdarg.h>
#include <wchar.h>
#include "./libft/libft.h"


void		sn(char *str, t_vars *e);
void		sc(char	 c, t_vars *e);
void		su(wchar_t c, t_vars *e);
void		sw(wchar_t *str, t_vars *e);

void		*u(intmax_t nb, t_vars *e);
char		*n(uintmax_t nb, t_vars *e);

void		ftprint(va_list ap, t_vars *e)
{
	(e->f == 1) ? sn(n((intmax_t)(va_arg(ap, int)), e), e) : 0;
	(e->f == 2) ? sn(n((intmax_t)(va_arg(ap, int)), e), e) : 0;
	(e->f == 3) ? sn(n((intmax_t)(va_arg(ap, int)), e), e) : 0;
	(e->f == 4) ? sn(n((intmax_t)(va_arg(ap, long int)), e), e) : 0;
	(e->f == 5) ? sn(n((intmax_t)(va_arg(ap, long long int)), e), e) : 0;
	(e->f == 6) ? sn(n((va_arg(ap, intmax_t)), e), e) : 0;
	(e->f == 7) ? sn(n((intmax_t)(va_arg(ap, size_t)), e), e) : 0;
	(e->f == 8) ? sn(u((intmax_t)(va_arg(ap, unsigned int)), e), e) : 0;
	(e->f == 9) ? sn(u((intmax_t)(va_arg(ap, unsigned int)), e), e) : 0;
	(e->f == 10) ? sn(u((intmax_t)(va_arg(ap, unsigned int)), e), e) : 0;
	(e->f == 11) ? sn(u((intmax_t)(va_arg(ap, unsigned long int)), e), e) : 0;
	(e->f == 12) ? sn(u((intmax_t)(va_arg(ap, unsigned long long int)), e), e) : 0;
	(e->f == 13) ? sn(u((va_arg(ap, intmax_t)), e), e) : 0;
	(e->f == 14) ? sn(n((intmax_t)(va_arg(ap, double)), e), e) : 0;
	(e->f == 15) ? sc((char)(va_arg(ap, int)), e) : 0;
	(e->f == 16) ? su((wchar_t)(va_arg(ap, wint_t)), e) : 0;
	(e->f == 17) ? sn((va_arg(ap, char*)), e) : 0;
	(e->f == 18) ? sw((va_arg(ap, wchar_t*)), e) : 0;
	(e->f == 19) ? sn((char*)(va_arg(ap, void*)), e) : 0;
}


void		typeformat(t_vars *e)
{
	(ft_strchr("di", e->type) && e->flags == 0) ? e->f = 1 : 0;
	(ft_strchr("di", e->type) && e->flags == 1) ? e->f = 2 : 0;
	(ft_strchr("di", e->type) && e->flags == 2) ? e->f = 3 : 0;
	(ft_strchr("di", e->type) && e->flags == 3) ? e->f = 4 : 0;
	(ft_strchr("di", e->type) && e->flags == 4) ? e->f = 5 : 0;
	(ft_strchr("di", e->type) && e->flags == 5) ? e->f = 6 : 0;
	(ft_strchr("di", e->type) && e->flags == 6) ? e->f = 7 : 0;
	(ft_strchr("uoxX", e->type) && e->flags == 0) ? e->f = 8 : 0;
	(ft_strchr("uoxX", e->type) && e->flags == 1) ? e->f = 9 : 0;
	(ft_strchr("uoxX", e->type) && e->flags == 2) ? e->f = 10 : 0;
	(ft_strchr("uoxX", e->type) && e->flags == 3) ? e->f = 11 : 0;
	(ft_strchr("uoxX", e->type) && e->flags == 4) ? e->f = 12 : 0;
	(ft_strchr("uoxX", e->type) && e->flags == 5) ? e->f = 13 : 0;
	(ft_strchr("uoxX", e->type) && e->flags == 6) ? e->f = 14 : 0;
	(e->type == 'c' && e->flags == 0) ? e->f = 15 : 0;
	((e->type == 'c' && e->flags == 4) || e->type == 'C') ? e->f = 16 : 0;
	(e->type == 's' && e->flags == 0) ? e->f = 17 : 0;
	((e->type == 's' && e->flags == 4) || e->type == 'S') ? e->f = 18 : 0;
	(e->type == 'p' && e->flags == 0) ? e->f = 19 : 0;
}

















/*
void		format_and_print(t_vars *e, char *str)
{
	
}
*/


