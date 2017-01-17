/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:35:59 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/17 19:44:20 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "ft_print.h"


void	ft_printspace(int i, char c, t_vars *e)
{
	while (i-- > 0)
		e->totcount += ft_putchar_count(c);
}

void	ft_printprefix(t_vars *e)
{
	if (e->type == UOCTAL || e->type == OCTAL)
		e->totcount += ft_putchar_count('0');
	if (e->type == HEX)
		e->totcount += ft_putstr_count("0x");
	if (e->type == UHEX)
		e->totcount += ft_putstr_count("0X");
	if (e->type == POINTER)
		e->totcount += ft_putstr_count("0x7fff");
}

void	nb_post_flags(t_vars *e)
{
	if (e->width > e->printlen + e->printextra && e->align)
		ft_printspace((e->width - (e->printlen + e->printextra)), ' ', e);
}

void	addsign(char c, t_vars *e)
{
	e->printsign = c;
	e->printextra = 1;
}

void	n(intmax_t nb, t_vars *e)
{
	char *str;
	e->len = ft_size_of_intmax(nb, e);
	e->printchar = (e->zero && e->pointlen == -1) ? '0' : ' ';
	if (e->plus && !e->neg)
		addsign('+', e);
	if (e->printspace && !e->plus && !e->neg)
		addsign(' ', e);
	if (e->neg)
		addsign('-', e);
	e->printlen = (e->len >= e->pointlen) ? e->len : e->pointlen;
	if((e->printlen + e->printextra >= e->width || e->printchar == '0' || e->align) && e->printextra)
		e->totcount += ft_putchar_count(e->printsign);
	if((e->width > e->printextra + e->printlen) && !e->align)
		ft_printspace(e->width - (e->printextra + e->printlen), e->printchar, e);
	if(e->printlen + e->printextra < e->width && e->printextra && !e->align && e->printchar != '0')
		e->totcount += ft_putchar_count(e->printsign);
	if(e->len < e->pointlen)
		ft_printspace(e->pointlen - e->len, '0', e);
	str = ft_atoi_intmax(nb, e);
	if(!(e->pointlen != -1 && *str == '0'))
		e->totcount += ft_putstr_count(str);
	nb_post_flags(e);
	//ft_printvars(e);
}

void		calc_printextra(t_vars *e)
{
	if ((e->type == UOCTAL || e->type == OCTAL) && e->printprefix)
		e->printextra = 1;
	if ((e->type == HEX || e->type == UHEX) && e->printprefix)
		e->printextra = 2;
	if (e->type == POINTER)
		e->printextra = 6;
}

void u(uintmax_t nb, t_vars *e)
{
	char *str;
	e->len = ft_size_of_uintmax(nb, e);
	e->printchar = (e->zero && e->pointlen == -1) ? '0' : ' ';
	calc_printextra(e);
	str = ft_atoi_uintmax(nb, e);
	if(str[0] == '0' && e->type != POINTER)
	{
		e->printprefix = 0;
		e->printextra = 0;
	}
	e->printlen = (e->len >= e->pointlen) ? e->len : e->pointlen;
	if((e->printlen + e->printextra >= e->width || e->printchar == '0' || e->align) && e->printextra > 0)
		ft_printprefix(e);
	if(e->printlen + e->printextra < e->width && !e->align)
		ft_printspace(e->width - (e->printlen + e->printextra), e->printchar, e);
	if(e->printlen + e->printextra < e->width && !e->align && e->printchar == ' ' && e->printextra)
		ft_printprefix(e);
	if(e->len < e->pointlen)
		ft_printspace(e->pointlen - e->len, '0', e);
	if(!(e->pointlen != -1 && *str == '0'))
		e->totcount += ft_putstr_count(str);
	//ft_printvars(e);
	nb_post_flags(e);

}
