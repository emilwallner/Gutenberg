/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:35:59 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/15 01:06:08 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include "ft_print.h"




int		ft_size_of_intmax(intmax_t nb, t_vars *e)
{
	int		i;

	if (e->type == OCTAL || e->type == UOCTAL)
		e->base = 8;
	else if (e->type == HEX || e->type == UHEX || e->type == POINTER)
		e->base = 16;
	else 
		e->base = 10;
	i = 0;
	if ((nb < 0) && (e->type == INTEGER || e->type == DECIMAL))
	{
		e->neg = 1;
		nb = -nb;
	}
	while (nb)
	{
		nb /= e->base;
		i++;
	}
	return(i);
}

int		ft_size_of_uintmax(uintmax_t nb, t_vars *e)
{
	int		i;

	if (e->type == OCTAL || e->type == UOCTAL)
		e->base = 8;
	else if (e->type == HEX || e->type == UHEX || e->type == POINTER)
		e->base = 16;
	else 
		e->base = 10;
	i = 0;
	while (nb)
	{
		nb /= e->base;
		i++;
	}
	return (i);
}
/*
 * Hexa + and -
 * Oct + and - 
 */

void	ft_printspace(int i, char c)
{
	while (i-- > 0)
		ft_putchar(c);
}

void	ft_printprefix(int i)
{
	if (i == UOCTAL || i == OCTAL)
		ft_putchar('0');
	else if (i == HEX)
		ft_putstr("0x");
	else if (i == UHEX)
		ft_putstr("0X");
	else 
		ft_putstr("0x7fff");
}

void	nb_pre_flags(t_vars *e)
{
	if (e->printspace == TRUE)
		ft_putchar(' ');
	if (e->type == POINTER)
		e->printprefix = 1;
	if (e->base == 10 && e->plus == TRUE && e->neg == FALSE)
	{
		e->printsign = '+';
		e->printextra = 1;
	}
	if (e->base == 10 && e->neg == TRUE)
	{
		e->printsign = '-';
		e->printextra = 1;
	}
	if ((e->type == OCTAL || e->type == UOCTAL) && e->printprefix == 1)
		e->printextra = 1;
	else if ((e->type == HEX || e->type == UHEX) && e->printprefix == 1)
		e->printextra = 2;
	else if (e->type == POINTER)
		e->printextra = 6;
	if (e->pointlen > e->len)
		e->printlen = e->pointlen;
	else
		e->printlen = e->len;
	e->printchar = (e->zero) ? '0' : ' ';
	if (e->type > 2 && (e->type != 14 && e->type != 9))
	{
		if (e->printprefix == TRUE && e->zero == TRUE)
			ft_printprefix(e->type);
		if (e->align == FALSE && (e->width > (e->printlen + e->printextra)))
			ft_printspace((e->width - (e->printlen + e->printextra)), e->printchar);
		if (e->printprefix == TRUE && e->zero == FALSE)
			ft_printprefix(e->type);
	}
	if (e->type < 3 || e->type == 14 || e->type == 9)
	{
		if ((e->width > e->printlen + e->printextra) && e->printextra == TRUE && e->zero == TRUE && e->pointlen == -1)
		ft_putchar(e->printsign);
		if (e->align == FALSE && (e->width > (e->printlen + e->printextra)) && e->pointlen == -1)
			ft_printspace((e->width - (e->printlen + e->printextra)), e->printchar);
		if (e->align == FALSE && (e->width > (e->printlen + e->printextra)) && e->pointlen != -1)
			ft_printspace((e->width - (e->printlen + e->printextra)), ' ');
		if ((e->printlen + e->printextra < e->width ) && e->printextra == TRUE && e->pointlen != -1)
			ft_putchar(e->printsign);
		if ((e->printlen + e->printextra < e->width ) && e->printextra == TRUE && e->pointlen == -1 && e->zero == FALSE)
			ft_putchar(e->printsign);
		if ((e->printlen + e->printextra >= e->width) && e->printextra == TRUE)
			ft_putchar(e->printsign);
	}
	if (e->pointlen > e->len + e->printextra)
		ft_printspace((e->pointlen - e->len), '0');
	if (e->type == UHEX || e->type == HEX || e->type == POINTER)
		e->base = 16;
	if (e->type == OCTAL || e->type == UOCTAL)
		e->base = 8;
}

void	nb_post_flags(t_vars *e)
{
	if (e->width > e->printlen + e->printextra && e->align == TRUE)
		ft_printspace((e->width - (e->printlen + e->printextra)), ' ');
}

char		*ft_atoi_uintmax(uintmax_t nb, t_vars *e)
{
	char	*sixteen;
	int			i;
	int			len;
	char		*dest;

	i = 0;
	if (e->type == UHEX || e->type == UOCTAL)
		sixteen = "0123456789ABCDEF";
	else
		sixteen = "0123456789abcdef";
	dest = malloc(sizeof(char) * (e->len + 1));
	dest[e->len] = '\0';
	len = e->len;
	while(nb)
	{
		dest[--len] = sixteen[nb % e->base];
		nb /= e->base;
	}
	return (dest);
}

char		*ft_atoi_intmax(intmax_t nb, t_vars *e)
{
	char	*sixteen;
	int			i;
	int			len;
	char		*dest;

	i = 0;
	if (e->type == UHEX || e->type == UOCTAL)
		sixteen = "0123456789ABCDEF";
	else
		sixteen = "0123456789abcdef";
	dest = malloc(sizeof(char) * (e->len + 1));
	dest[e->len] = '\0';
	len = e->len;
	if(nb < 0)
		nb = -nb;
	while(nb)
	{
		dest[--len] = sixteen[nb % e->base];
		nb /= e->base;
	}
	return (dest);
}

void	n(intmax_t nb, t_vars *e)
{
	char *str;
	//if(e->type == PERCENT)

	e->len = ft_size_of_intmax(nb, e);
	nb_pre_flags(e);
	str = ft_atoi_intmax(nb, e);
	ft_putstr(str);
	nb_post_flags(e);
}

void u(uintmax_t nb, t_vars *e)
{
	char *str;

	e->len = ft_size_of_uintmax(nb, e);
	nb_pre_flags(e);
	str = ft_atoi_uintmax(nb, e);
	ft_putstr(str);
	nb_post_flags(e);
}
