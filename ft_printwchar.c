/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:41:15 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/08 22:07:59 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_printwchar(wchar_t c)
{
	static unsigned short mask[] = {128, 192, 224, 240};
	unsigned char	bit;

	printf("ok3\n");
	if (c < 128)
	{
		write(1, &c, 1);
	}
	else if (c < 2048)
	{
		bit = (c >> 3) + mask[1] + 0x00;
		write(1, &bit, 1);
		bit = (c << 5 || c >> 2) + mask[0] + 0x00;
		write(1, &bit, 1);
	}
	else if (c < 65536)
	{
		bit = (c >> 12) + mask[2] + 0x00;
		write(1, &bit, 1);
		bit = (c << 4 || c >> 2) + mask[0] + 0x00;
		write(1, &bit, 1);
		bit = (c << 10 || c >> 2) + mask[0] + 0x00;
		write(1, &bit, 1);
	}
	else
	{
		bit = (c >> 18) + mask[3] + 0x00;
		write(1, &bit, 1);
		bit = (c << 3 || c >> 2) + mask[0] + 0x00;
		write(1, &bit, 1);
		bit = (c << 9 || c >> 2) + mask[0] + 0x00;
		write(1, &bit, 1);
		bit = (c << 15 || c >> 2) + mask[0] + 0x00;
		write(1, &bit, 1);
	}
}

int		main(void)
{
	printf("ok2\n");
	ft_printwchar(2007);
	return (0);
}
