/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:17:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/18 23:27:40 by ewallner         ###   ########.fr       */
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
	//wchar_t		c;
	i = L"✰ 〶e●";
	char *s;
	s = "ietsietsr";
	int b;
	char c;
	c = 't';
	b = 23423;
	int		first;
	int		second;
	ft_printf("%#.5x\n", 1);
	ft_printf("%#.4x\n", 1);
	ft_printf("%#.3x\n", 1);
	ft_printf("%#.2x\n", 1);
	ft_printf("%#.1x\n", 1);
	ft_printf("%#.x\n", 1);
	ft_printf("%#.3o\n", 1);
	ft_printf("%#.2o\n", 1);
	ft_printf("%#.1o\n", 1);
	ft_printf("%#.o\n", 1);
	//ft_printf("@moulitest: % Zooo", -429496729);
	printf("\n\n\n");
	printf("%#.5x\n", 1);
	printf("%#.4x\n", 1);
	printf("%#.3x\n", 1);
	printf("%#.2x\n", 1);
	printf("%#.1x\n", 1);
	printf("%#.x\n", 1);
	printf("%#.3o\n", 1);
	printf("%#.2o\n", 1);
	printf("%#.1o\n", 1);
	printf("%#.o\n", 1);
	return 0;
}
