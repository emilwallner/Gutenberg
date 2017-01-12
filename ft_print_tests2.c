/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:36:20 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/12 15:44:06 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_print.h"
#include "./libft/libft.h"
#include <stdio.h>
#include	<wchar.h>
#include <locale.h>

int			main(void)
{
	setlocale (LC_ALL, "");
	char	*ops = "It's working.";
	int		nbr = 42;
	char	*p = NULL;
	long int i = 2343223645324;
	printf("This is a Hed normal>>>%20p|\n\n\n", &nbr);
	printf("This is no number:%d\n", 0);
	printf("This is no number: >>>% 10d<<<\n", 0);
	printf("This is a test: >>>%U<<<\n", 4294967296);
	
/*
	printf("This is a Hex minus>>>%+.5d\n", (unsigned int)123456789);
	printf("This is a Hex minus>>>%+.5hhd\n", (unsigned char)123456789);
	printf("This is a Hex minus>>>%+.5hd\n", (unsigned short)123456789);
	printf("This is a Hex minus>>>%+.5ld\n", (unsigned long)123456789);
	printf("This is a Hex minus>>>%+.5lld\n", (unsigned long long)123456789);
	printf("This is a Hex minus>>>%+.5zd\n\n\n", (size_t)123456789);
	
	printf("This is a Hex minus>>>%+9d\n", 123456789);
	printf("This is a Hex minus>>>%+10d\n\n\n", 123456789);
	printf("This is a Hex minus>>>%+11d\n\n\n", 123456789);
	
	printf("This is a Hex minus>>>%9d\n", -123456789);
	printf("This is a Hex minus>>>%+10d\n\n\n", -123456789);
	printf("This is a Hex minus>>>%+11d\n\n\n", -123456789);
	
	printf("This is a Hex minus>>>%-d\n", -123456789);
	printf("This is a Hex minus>>>%d\n", -123456789);
	printf("This is a Hex minus>>>%20d|\n", -123456789);
	printf("This is a Hex minus>>>%+20d|\n", 11111);
	printf("This is a Hex minus>>>%+20.20d|\n", -222222);
	printf("This is a Hex minus>>>%+20.10d|\n", -33333);
	printf("This is a Hex minus>>>%.20d|\n", -123456789);
	printf("This is a Hex minus>>>%.5d\n", (unsigned int)-123456789);
	printf("This is a Hex minus>>>%.5hhd\n", (unsigned char)-123456789);
	printf("This is a Hex minus>>>%.5hd\n", (unsigned short)-123456789);
	printf("This is a Hex minus>>>%.5ld\n", (unsigned long)-123456789);
	printf("This is a Hex minus>>>%.5lld\n\n\n", (unsigned long long)-123456789);
	
	printf("This is a Hex minus>>>%5.9d\n", -123456789);
	printf("This is a Hex plus>>>%5.9d\n", (unsigned int)-123456789);
	printf("This is a Hex plus>>>%5.9hhd\n", (unsigned char)-123456789);
	printf("This is a Hex minus>>>%-5.9d\n", (unsigned int)-123456789);
	printf("This is a Hex minus>>>%-5.9hhd\n", (unsigned char)-123456789);
	printf("This is a Hex minus>>>%5.9hd\n", (unsigned short)-123456789);
	printf("This is a Hex minus>>>%5.9ld\n\n\n", (unsigned long)-123456789);
	
	
	printf("This is a Hex minus>>>%5.9x\n", -123456789);
	printf("This is a Hex plus>>>%5.9hx\n", (unsigned short)-123456789);
	printf("This is a Hex plus>>>%5.9hhx\n", (unsigned char)-123456789);
	printf("This is a Hex minus>>>%-5.9lx\n", (unsigned long)-123456789);
	printf("This is a Hex minus>>>%-5.9hhx\n", (unsigned char)-123456789);
	printf("This is a Hex minus>>>%5.9hx\n", (unsigned short)-123456789);
	printf("This is a Hex minus>>>%5.9lx\n\n\n", (unsigned long)-123456789);
	
	
	printf("This is a Hex minus>>>%#11.9x\n", -123456789);
	printf("This is a Hex plus>>>%#12.9hx\n", (unsigned short)-123456789);
	printf("This is a Hex plus>>>%#5.9hhx\n", (unsigned char)-123456789);
	printf("This is a Hex minus>>>%#-5.9lx\n", (unsigned long)-123456789);
	printf("This is a Hex minus>>>%#-5.9hhx\n", (unsigned char)-123456789);
	printf("This is a Hex minus>>>%#5.9hx\n", (unsigned short)-123456789);
	printf("This is a Hex minus>>>%#5.9lx\n\n\n", (unsigned long)-123456789);

	
	printf("This is a Hex minus>>>%#5.9o\n", -123456789);
	printf("This is a Hex plus>>>%#5.9ho\n", (unsigned short)-123456789);
	printf("This is a Hex plus>>>%#5.9hho\n", (unsigned char)-123456789);
	printf("This is a Hex minus>>>%#-5.9lo\n", (unsigned long)-123456789);
	printf("This is a Hex minus>>>%#-5.9hho\n", (unsigned char)-123456789);
	printf("This is a Hex minus>>>%#5.9ho\n", (unsigned short)-123456789);
	printf("This is a Hex minus>>>%#5.9lo\n", (unsigned long)-123456789);

	
	printf("This is a String minus>>>%10.5s\n", "12345");
	printf("This is a String minus>>>%10.5s\n", "12345");
	printf("This is a Hex minus>>>%5.10s\n", "12345");
	printf("This is a Hex minus>>>%-5.10s\n", "12345");
	printf("This is a Hex minus>>>%5.3s\n", "12345");
	printf("This is a Hex minus>>>%-5.3s\n", "12345");
	printf("This is a Hex minus>>>%3.3s\n", "12345");
	printf("This is a Hex minus>>>%-3.3s\n", "12345");
	printf("This is a Hex minus>>>%3.0d\n", 12345);
	printf("This is a Hex minus>>>%-3.0s\n\n\n", "12345");
	
	
	printf("This is a Hex minus>>>%3c\n", 'c');
	printf("This is a Hex minus>>>%3c\n\n\n", 'c');

	printf("This is a Hex minus>>>%C\n", L'س');
	printf ("| return:%S | \n", L"تمكنبس");
	printf ("| return:%ls | \n", L"تمكنبسâ");
	
	*/
	
	
	
	
	
	
	
	
	return (0);
}
