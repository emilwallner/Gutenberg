/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:41:15 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/09 15:15:12 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void	ft_printwchar_norm(wchar_t c, unsigned short *mask, unsigned char bit)
{
	bit = mask[3] | (c >> 18 & mask[5]);
	write(1, &bit, 1);
	bit = mask[0] | (c >> 12 & mask[4]);
	write(1, &bit, 1);
	bit = mask[0] | (c >> 6 & mask[4]);
	write(1, &bit, 1);
	bit = mask[0] | (c & mask[4]);
	write(1, &bit, 1);
}

void	ft_printwchar(wchar_t c)
{
	static unsigned short mask[] = {128, 192, 224, 240, 63, 7, 15};
	unsigned char	bit;

	if (c < 128)
	{
		write(1, &c, 1);
	}
	else if (c < 2048)
	{
		bit = (c >> 6) | mask[1];
		write(1, &bit, 1);
		bit = mask[0] | (c & mask[4]);
		write(1, &bit, 1);
	}
	else if (c < 65536)
	{
		bit = mask[2] | (c >> 12 & mask[6]);
		write(1, &bit, 1);
		bit = (mask[0] | (c >> 6 & mask[4]));
		write(1, &bit, 1);
		bit = (mask[0] | (c & mask[4]));
		write(1, &bit, 1);
	}
	else
		ft_printwchar_norm(c, mask, bit);
}
