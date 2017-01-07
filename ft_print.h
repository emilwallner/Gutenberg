/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:47:43 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/07 19:45:39 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H
# define TRUE 1
# define FALSE 0

typedef struct	s_vars {
	int		minus;
	int		zero;
	int		plus;
	int		width;
	int		pointlen;
	int		percent;
	int		space;
	int		hash;
	int		flags;
	int		len;
	int		type;
	int		f;
	char	*print;
}				t_vars;

typedef struct s_types {
	const char*			s;
	wchar_t				S;
	unsigned int		p;
	int					d;
	signed long			D;
	unsigned int		o;
	unsigned long int	O;
	unsigned int		u;
	unsigned int		x;
	unsigned long		lx;
	unsigned int		X;
	int					c;
	unsigned long int	C;
}				t_types;


void	ft_parser(char *str);

#endif
