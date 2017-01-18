/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:07:03 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/18 10:03:20 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "ft_print.h"




int		ft_size_of_intmax(intmax_t nb, t_vars *e)
{
	int		i;

	i = 0;
	if(nb == 0)
		return (0);
	if (nb < 0)
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

	if(nb == 0)
		return (0);
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

char		*ft_atoi_uintmax(uintmax_t nb, t_vars *e)
{
	char	*sixteen;
	int			i;
	int			len;
	char		*dest;

	i = 0;
	if(nb == 0)
		return("0");
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
	
	if (nb < -9223372036854775807)
		return ("9223372036854775808");
	i = 0;
	if(nb == 0)
		return ("0");
	sixteen = "0123456789";
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
