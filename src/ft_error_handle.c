/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 21:01:49 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/15 15:46:14 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include <stdlib.h>

void		ft_exit(t_vars *e)
{
	free(&e);
	ft_putstr("<<< (╯°□°）╯︵ ┻━┻ \n (ヘ･_･)ヘ┳━┳ \n Usage: man 3 printf");
	exit(-1);
}

void		ft_error_handle(t_vars *e)
{
	if(e->printspace == TRUE && e->plus == TRUE)
		ft_exit(e);
	if(e->type == POINTER && (e->plus == TRUE || e->flags != FALSE || e->zero \
				== TRUE || e->printspace == TRUE))
			ft_exit(e);
	if(e->zero == TRUE && e->printprefix == TRUE)
		ft_exit(e);
	if(e->printprefix == TRUE && (e->type < 8 || e->type == 9 || e->type == 14))
		ft_exit(e);
	if(e->type == POINTER && e->pointlen > 0)
		ft_exit(e);
	if((e->type == POINTER || e->type == UHEX || e->type == HEX || e->type == OCTAL \
			|| e->type == UOCTAL) && e->plus == 1)
		ft_exit(e);


	if(e->printspace == TRUE && (e->type >= 3 && e->type <= 7))
		ft_exit(e);
}
