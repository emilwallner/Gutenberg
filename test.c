/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:17:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/17 19:22:12 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_print.h"
#include <locale.h>

int main(void)
{

	setlocale (LC_ALL, "");
	wchar_t		*i;
	wchar_t		c;
	i = L"✰ 〶e●";
	ft_printf("%#08x|", 42);
	printf("\n\n\n");
	printf("%#08x|", 42);
	return 0;
}
