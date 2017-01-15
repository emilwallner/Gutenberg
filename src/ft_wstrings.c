/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:09:25 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/15 22:21:09 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_print.h"
#include "stdio.h"

int		wstrings_size(wchar_t *str, int i, t_vars *e)
{
	int		len;
	int		totlen;
	int		charlen;

	charlen = 0;
	totlen = 0;
	len = 0;
	if (i == -1)
	{
		while (str[len])
		{
			totlen += (wchars_size(str[len], e));
			len++;
		}
	}
	else
	{
		while (str[len] && totlen + charlen < i)
		{
			charlen = wchars_size(str[len], e);
			if ((charlen + totlen) < i)
				totlen += charlen;
			len++;
		}
	}
	return (totlen);
}

void		ft_putwstr_cut(wchar_t *str, int i, t_vars *e)
{
	int		len;
	int		totlen;
	int		charlen;

	totlen = 0;
	charlen = 0;
	len = 0;
	while(str[len] != '\0' && totlen + charlen < i)
	{
		charlen = (wchars_size(str[len], e));
		if(totlen + charlen < i)
		{
			ft_printwchar(str[len]);
			totlen += charlen;
		}
		len++;
	}
}


void	wstrings(wchar_t *str, t_vars *e)
{
	//int		len;

	e->printlen = wstrings_size(str, e->pointlen, e);
	if (e->width < e->printlen)
		ft_putwstr_cut(str, e->printlen, e);
	if (e->width > e->printlen && e->align == TRUE)
	{
		ft_putwstr_cut(str, e->printlen, e);
		ft_printspace(e->width - e->printlen, ' ', e);
	}
	if (e->width > e->printlen && e->align == FALSE)
	{
		ft_printspace(e->width - e->printlen, ' ', e);
		ft_putwstr_cut(str, e->printlen, e);
	}
	e->totcount += e->printlen;
}
