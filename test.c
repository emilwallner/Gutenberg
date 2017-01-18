/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:17:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/18 14:46:46 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_print.h"
#include <locale.h>
#include <limits.h>

int main(void)
{

	setlocale (LC_ALL, "");
	wchar_t		*i;
//	int		test_simple_mix;
	wchar_t		c;
	i = L"✰ 〶e●";
	int		first;
	int		second;
	ft_printf("%lu\n", -42);
	//ft_printf("@moulitest: % Zooo", -429496729);
	printf("\n\n\n");
	printf("%lu\n", -42);
	return 0;
}
