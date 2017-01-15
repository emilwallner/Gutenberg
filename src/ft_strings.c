/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:31:03 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/15 17:33:03 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_print.h"
#include "stdio.h"

int		ft_putstr_count(char *str)
{
	if (!str)
		ft_putstr_count("(null)");
	else
		write(1, str, sizeof(str));
	return (sizeof(str));
}

void		ft_putstr_cut(char *str, int width, t_vars *e)
{
	int		i;

	i = 0;
	if (!str)
		ft_putstr_count("(null)");
	else
		while(str[i] != '\0' && i < width)
		{
			e->totcount += ft_putchar_count(str[i]);
			i++;
		}
}

void	strings(char *str, t_vars *e)
{
	int		len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if(len < e->pointlen)
		e->printlen = e->pointlen;
	else 
		e->printlen = len;
	if (e->width == -1 && e->align == FALSE && e->pointlen == -1)
		ft_putstr_cut(str, e->printlen, e);
	if (e->width == len && e->pointlen == -1)
		ft_putstr_cut(str, e->printlen, e);
	if (e->width > len && e->align == TRUE)
	{
		ft_putstr_cut(str, e->printlen, e);
		ft_printspace(e->width - e->printlen, ' ', e);
	}
	if (e->width > len && e->align == FALSE)
	{
		ft_printspace(e->width - e->printlen, ' ', e);
		ft_putstr_cut(str, e->printlen, e);
	}
}
