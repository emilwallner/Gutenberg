/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 19:24:30 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/13 12:30:05 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_print.h"
#include <stdio.h>

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
	ft_strdel(&temp);
	return (value);
}

int		ft_flagconv(int *i, char *str)
{
	int		value;

	if (str[*i] == 'h' && str[*i + 1] == 'h')
		value = 1;
	else if (str[*i] == 'h')
		value = 2;
	else if (str[*i] == 'l' && str[*i] != 'l')
		value = 3;
	else if (str[*i] == 'l')
		value = 4;
	else if (str[*i] == 'j')
		value = 5;
	else
		value = 6;
	if(value == 1 || value == 3)
		*i = *i + 2;
	else
		*i = *i + 1;
	return (value);
}

int		ft_increse(int *i, int val)
{
	*i = *i + 1;
	return (val + 1);
}

void	ft_removespace(char *str, int *i, t_vars *e)
{
	while (str[*i] == ' ')
		*i = *i + 1;
	e->printspace = TRUE;
}

void	ft_removeplus(char *str, int *i, t_vars *e)
{
	while (str[*i] == '+')
		*i = *i + 1;
	e->plus = TRUE;
}

void	ft_initialize_e(t_vars *e, int *i)
{
	*i = *i + 1;
	e->align = 0;
	e->zero = 0;
	e->plus = 0;
	e->width = -1;
	e->pointlen = -1;
	e->percent = 0;
	e->neg = 0;
	e->f = -1;
	e->flags = 0;
	e->len = 0;
	e->type = 0;
	e->base = 10;
	e->printchar = 'E';
	e->printminus = 0;
	e->printlen = 0;
	e->printplus = 0;
	e->printspace = 0;
	e->printprespace = 0;
	e->printlastspace = 0;
	e->printzero = 0;
	e->printprefix = 0;
}

int		ft_findtype(char *str, int *i)
{
	int		k;
	char	*types;

	k = 0;
	types = "idDsScC%pUOXxou";
	while (types[k] != '\0')
	{
		if (types[k] == str[*i])
			return (k);
		k++;
	}
	return (0);
}

void	ft_printvars(t_vars *e)
{
	printf("e->align: %d\n", e->align);
	printf("e->zero: %d\n", e->zero);
	printf("e->plus: %d\n", e->plus);
	printf("e->width: %d\n", e->width);
	printf("e->pointlen: %d\n", e->pointlen);
	printf("e->percent: %d\n", e->percent);
	printf("e->neg: %d\n", e->neg);
	printf("e->f: %d\n", e->f);
	printf("e->flags: %d\n", e->flags);
	printf("e->len: %d\n", e->len);
	printf("e->type: %d\n", e->type);
	printf("e->base: %d\n", e->base);
	printf("e->printchar: %d\n", e->printchar);
	printf("e->printminus: %d\n", e->printminus);
	printf("e->printlen: %d\n", e->printlen);
	printf("e->printplus: %d\n", e->printplus);
	printf("e->printspace: %d\n", e->printspace);
	printf("e->printprespace: %d\n", e->printprespace);
	printf("e->printlastspace: %d\n", e->printlastspace);
	printf("e->printzero: %d\n", e->printzero);
	printf("e->printprefix: %d\n", e->printprefix);
	
	printf("New var>>>\n\n\n");
}

t_vars		ft_printtype(char *str, int *i)
{
	t_vars e;
	
	ft_initialize_e(&e, i);
	if	(str[*i] == ' ')
		ft_removespace(str, i, &e);
	if (str[*i] == '-') 
		e.align = ft_increse(i, e.align);
	if (str[*i] == '+')
		ft_removeplus(str, i, &e);
	if	(str[*i] == ' ')
		ft_removespace(str, i, &e);
	if (str[*i] == '0' && str[*i - 1] == '%')
		e.zero = ft_increse(i, e.zero);
	if (ft_isdigit(str[*i]) == TRUE)
		e.width = ft_calcwidth(i, str);
	if (str[*i] == '.')
	{
		*i = *i + 1;
		e.pointlen = ft_calcwidth(i, str);
	}
	if (str[*i] == '#')
		e.printprefix = ft_increse(i, e.printprefix);
	if (str[*i] == 'h' || str[*i] == 'j' || str[*i] == 'z' || str[*i] == 'l')
		e.flags = ft_flagconv(i, str);
	e.type = ft_findtype(str, i);
	return (e);
}

t_vars		ft_parser(char *str)
{
	int i;
	t_vars e;

	i = -1;
	while (str[++i] != '\0')
	{
		if(str[i] != '%')
			ft_putchar(str[i]);
		else
			e = ft_printtype(str, &i);
	}
	return (e);
}
