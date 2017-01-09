/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:47:43 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/09 15:15:00 by ewallner         ###   ########.fr       */
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


void	ft_printwchar(wchar_t c);
void	ft_parser(char *str);

#endif
