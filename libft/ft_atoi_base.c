/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:35:59 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/11 11:11:02 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>

int			ft_size_of_base(int nb, int base)
{
	int		i;

	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

//char		*ft_atoi_base(int nb, int base)


int		main(void)
{
	printf("This is me mama: %d", ft_size_of_base(12345, 2));
	return (0);
}
