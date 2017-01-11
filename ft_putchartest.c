

#include <unistd.h>
#include <stdio.h>
#include <wchar.h>

void	ft_putchar(wint_t c)
{
	write(1, &c, sizeof(c));
}

int		main(void)
{
	printf("This is me: %lc\n", (wint_t)123456);
	printf("break\n\n\n");
	ft_putchar((wint_t)123456);
	return (0);
}
