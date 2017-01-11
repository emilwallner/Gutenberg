/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:35:59 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/11 13:56:24 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>

int		ft_size_of_base(int nb, int base)
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

char		*ft_atoi_base(int nb, int base)
{
	char	*sixteen;
	int			i;
	int			len;
	char		*dest;

	i = 0;
	sixteen = "0123456789ABCDEF";
	len = ft_size_of_base(nb, base);
	dest = malloc(sizeof(char) * (len + 1));
	len = len - 1;
	while(nb)
	{
		dest[len] = sixteen[nb % base];
	//	printf("this is dad: %c\n", dest[len]);
		nb /= base;
		len--;
	}
	dest[len] = '\0';
	return (dest);
}

int		main(int argc, char **argv)
{
	(void)argc;
	printf("This is me mama: %s", ft_atoi_base(ft_atoi(argv[1]), ft_atoi(argv[2])));
	return (0);
}
