/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 19:24:30 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/06 00:18:05 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_print.h"

void	ft_printspace(int i, int zero)
{
	while (i-- > 0)
	{
		if(zero == TRUE)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
}

void	ft_puttype(char *str, int len)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_printorder(t_vars *e)
{
	if (e->printorder == TRUE)
	{
		ft_puttype(e->print, e->len);
		ft_printspace(e->space, e->zero);
	}
	else
	{
		ft_printspace(e->space, e->zero);
		ft_puttype(e->print, e->len);
	}
}

int		ft_calcwidth(int *i, char *str)
{
	size_t		len;
	char	*temp;
	int		value;

	len = 0;
	while(ft_isdigit(str[*i]) == TRUE)
	{
		*i = *i + 1;
		len++;
	}
	temp = ft_strnew(len);
	ft_strncpy(temp, str + *i - len, len);
	value = ft_atoi(temp);
	//ft_strdel(&temp);
	return (value);
}

int		ft_flagconv(int *i, char *str)
{
	if (str[*i] == 'h' && str[*i + 1] == 'h')
		return (1);
	else if (str[*i] == 'h')
		return (2);
	else if (str[*i] == 'l' && str[*i] != 'l')
		return (3);
	else if (str[*i] == 'l')
		return (4);
	else if (str[*i] == 'j')
		return (5);
	else
		return (6);
}

int		ft_increse(int *i, int val)
{
	*i = *i + 1;
	return (val + 1);
}

void	ft_parser(char *str)
{
	int i;
	int end;
	t_vars e;

	i = -1;
	end = TRUE;
	while (str[++i] != '\0' && end == FALSE)
	{
		if(str[i] != '%')
			ft_putchar(str[i++]);
		else if(str[i] == '%' && str[i + 1] == '%')
			ft_putchar(str[i++]);
		else
		{
			if(str[++i] == '-') 
				e.minut = ft_increse(&i, e.minus);
			if (str[i] == '+') 
				e.plus = ft_increse(&i, e.plus);
			if(str[i] == '0' && str[i - 1] == '%')
				e.zero = ft_increse(&i, e.zero)
					if(ft_isalpha(str[i++]) == TRUE)
						e.width = ft_calcwidth(&i, str);
			if(str[i] == '.')
			{
				i++;
				e.pointlen = ft_calcwidth(&i, str);
			}
			if(str[i] == 'h' || str[i] == 'j' || str[i] == 'z' || str[i] == 'l')
				e.flags = ft_flagconv(&i, str);
			ft_printorder(str[i], &e);
		}
	}
}
