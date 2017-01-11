/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:35:59 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/11 23:54:06 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>
#include "ft_print.h"




void		ft_size_of_intmax(intmax_t nb, t_vars *e)
{
	int		i;

	if (e->type == 7 || e->type == 8)
		e->base = 8;
	else if (e->type == 11 || e->type == 12)
		e->base = 16;
	else 
		e->base = 10;
	i = 0;
	while (nb)
	{
		nb /= e->base;
		i++;
	}
	e->len = i;
}

void		ft_size_of_uintmax(uintmax_t nb, t_vars *e)
{
	int		i;

	if (e->type == 7 || e->type == 8)
		e->base = 8;
	else if (e->type == 11 || e->type == 12)
		e->base = 16;
	else 
		e->base = 10;
	i = 0;
	while (nb)
	{
		nb /= e->base;
		i++;
	}
	e->len = i;
}
/*
 * Hexa + and -
 * Oct + and - 
 */

void	printzero(int i)
{
	while (i-- > 0)
		ft_putchar('0');
}

void	nbflags(t_vars *e)
{
	int		maxlen;

	maxlen = (e->width > e->pointlen) ? e->width : e->pointlen;
	if (e->space == TRUE)
		ft_putchar(' ');
	if (e->base == 10 && e->plus == 1)
		ft_putchar('+');
	if (e->base == 10 && e->minus == 1)
		ft_putchar('-');
	if (e->len > maxlen)
		printzero(maxlen - e->len);
}

char	*n(intmax_t nb, t_vars *e)
{
	char *str;
	ft_size_of_intmax(nb, e);
	nbflags(e);
	return (str);
}

char	*u(uintmax_t nb, t_vars *e)
{
	char *str;
	ft_size_of_uintmax(nb, e);
	return (str);
}

char		*ft_atoi_uintmax(uintmax_t nb, t_vars *e)
{
	char	*sixteen;
	int			i;
	int			len;
	char		*dest;

	i = 0;
	if (e->type == 'X' || e->type == 'O')
		sixteen = "0123456789ABCDEF";
	else
		sixteen = "0123456789abcdef";
	dest = malloc(sizeof(char) * (e->len + 1));
	dest[e->len] = '\0';
	while(nb)
	{
		dest[--e->len] = sixteen[nb % e->base];
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
	sixteen = "0123456789ABCDEF";
	dest = malloc(sizeof(char) * (e->len + 1));
	dest[e->len] = '\0';
	while(nb)
	{
		dest[--e->len] = sixteen[nb % e->base];
		nb /= e->base;
	}
	return (dest);
}

