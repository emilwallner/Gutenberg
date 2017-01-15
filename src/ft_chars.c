/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:21:10 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/15 16:21:05 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_print.h"

int		ft_putchar_count(char c)
{
	write(1, &c, 1);
	return (1);
}


void	chars(char c, t_vars *e)
{
	if(e->width != -1 && e->align == FALSE)
		ft_printspace(e->width - 1, ' ', e);
	ft_putchar_count(c);
	if(e->width != -1 && e->align == TRUE)
		ft_printspace(e->width - 1, ' ', e);
}

void	percent(t_vars *e)
{
	chars('%', e);
}

