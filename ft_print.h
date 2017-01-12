/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:47:43 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/12 10:01:52 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H
# define TRUE 1
# define FALSE 0

/*
 * b = base;
 */


typedef struct	s_vars {
	int		minus;
	int		zero;
	int		plus;
	int		width;
	int		pointlen;
	int		percent;
	int		neg;
	int		f;
	int		flags;
	int		len;
	int		type;
	int		base;
	int		printminus;
	int		printlen;
	int		printplus;
	int		printspace;
	int		printprespace;
	int		printlastspace;
	int		printzero;
	int		printprefix;
	char	*print;
}				t_vars;


void	ft_parser(char *str);

#endif
