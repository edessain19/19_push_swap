#include "../include/push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n <= 9 && n >= 0)
		ft_putchar(n + 48);
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
	}
}

void	ft_print_stack(t_data *data, char *cmd)
{
	int		i;
	int		c;

	i = 0;
	c = ' ';
	ft_putstr_fd(cmd, 2);
	write(2, "stack a = ", 10);
	while (i < data->len_a)
	{
		ft_putnbr_fd(data->stack_a[i], 2);
		ft_putchar_fd(c, 2);
		i++;
	}
	ft_putchar_fd('\n', 2);
	i = 0;
	write(2, "stack b = ", 10);
	while (i < data->len_b)
	{
		ft_putnbr_fd(data->stack_b[i], 2);
		ft_putchar_fd(c, 2);
		i++;
	}
	ft_putchar('\n');
}

void	ft_print_tab(int *tab, int len)
{
	int		i;

	i = 0;
	printf("-----------\n");
	while (i < len)
	{
		printf("tab[%i] = %i\n", i, tab[i]);
		i++;
	}
	printf("-----------\n");
}
