/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:36:20 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/06 10:33:42 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int			main(void)
{
	char	*ops = "It's working.";
	int		nbr = 42;
	char	*p = NULL;
	printf("\033[1;35mBASICS\n\n");
	printf("\033[0m1. This is a line.\n");
	printf("2. This is a string: %s<<<\n", "Yes, it is.");
	printf("3. This is a string var: %s<<<\n", ops);
	printf("4. This is a number: %d.\n", 42);
	printf("5. This is a number var: %d.\n", nbr);
	printf("6. This is a string: %s, and a number %d\n\n", ops, nbr);

	printf("\033[1;35m.Max and -Min\n\n");
	printf("\033[0m1. This is max 5 for 10 chars: %.5s<<<\n", "1234567890");
	printf("2. This is min 10 for 5 chars: %-10s<<<\n", "12345");
	printf("3. This is min 10 and max 5 for 10 chars: %-10.5s<<<\n", "1234567890");
	printf("4. This is min 10 and max 5 for 5 chars: %-10.5s<<<\n", "12345");
	printf("5. This is 5 and max 10 for 5 chars: %5.10s<<<\n", "12345");
	printf("6. This is 5 and max 10 for 5 chars: %5.10s<<<\n", "12345");
	printf("7. This is 10 and max 5 for 10 chars: %10.5s<<<\n", "1234567890");
	printf("8. This is 5 and max 10 for 10 chars: %5.10s<<<\n\n", "1234567890");

	printf("\033[1;35m.The different types:\n\n");
	printf("\033[0m1. This is s: %s<<<\n", "This is a string");
	printf("This is int with flags: %.5d<<<\n", 123456789);
	printf("This is a pointer address: %p<<<\n", p);
	printf("This is a pointer address:%    -  d<<<\n", -42);
	return (0);
}
