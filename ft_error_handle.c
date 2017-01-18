/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 21:01:49 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/18 23:09:50 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include <stdlib.h>

int		ft_error_handle(t_vars *e)
{
	if(e->type == -1)
		return(TRUE);
	if(e->type >= 3 && e->type <= 6 && e->zero)
		return(TRUE);
	if(e->type == POINTER && e->flags > 0)
		return(TRUE);
	if(e->type == POINTER && e->pointlen != -1)
		return(TRUE);
	/*
	if(e->printspace == TRUE && e->plus == TRUE)
		exit(-1);
	if(e->type == POINTER && (e->plus == TRUE || e->flags != FALSE || e->zero \
				== TRUE || e->printspace == TRUE))
		exit(-1);
	if(e->zero == TRUE && e->printprefix == TRUE)
		exit(-1);
	if(e->printprefix == TRUE && (e->type < 8 || e->type == 9 || e->type == 14))
		exit(-1);
	if(e->type == POINTER && e->pointlen > 0)
		exit(-1);
	if((e->type == POINTER || e->type == UHEX || e->type == HEX || e->type == OCTAL \
			|| e->type == UOCTAL) && e->plus == 1)
		exit(-1);
	if(e->printspace == TRUE && (e->type >= 3 && e->type <= 6))
		exit(-1);
	*/
	return (FALSE);
}
