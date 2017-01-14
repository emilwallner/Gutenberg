/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:47:43 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/14 21:19:42 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include <stdarg.h>

#ifndef FT_PRINT_H
# define FT_PRINT_H
# define TRUE 1
# define FALSE 0

/*
 * b = base;
 */

# define INTEGER 0
# define DECIMAL 1
# define UDECIMAL 2
# define STRING 3
# define WSTRING 4
# define CHAR 5
# define WCHAR 6
# define PERCENT 7
# define POINTER 8
# define UUNSIGNED 9
# define UOCTAL 10
# define UHEX 11
# define HEX 12
# define OCTAL 13
# define UNSIGNED 14

typedef struct	s_vars {
	int		align;
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
	char	printchar;
	char	printsign;
	int		printextra;
	int		printminus;
	int		printlen;
	int		printplus;
	int		printspace;
	int		printprespace;
	int		printlastspace;
	int		printzero;
	int		printprefix;
}				t_vars;

void		ft_initialize_e(t_vars *e);
int			ft_size_of_intmax(intmax_t nb, t_vars *e);
//void		sn(char *str, t_vars *e);
//void		sc(char	 c, t_vars *e);
//void		su(wchar_t c, t_vars *e);
//void		sw(wchar_t *str, t_vars *e);
void		u(uintmax_t nb, t_vars *e);
void		n(intmax_t nb, t_vars *e);
void		typeformat(t_vars *e);
void		ftprint(va_list ap, t_vars *e);
t_vars		ft_parser(char *str);
void		ft_printvars(t_vars *e);

#endif
