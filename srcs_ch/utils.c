#include "../include/push_swap.h"

void	ft_print_stack(t_data *data, char *cmd)
{
	int		i;

	i = 0;
	ft_putstr_fd(cmd, 1);
	write(1, "stack a = ", 10);
	while (i < data->len_a)
	{
		ft_putnbr_fd(data->stack_a[i], 1);
		write(i, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	i = 0;
	write(1, "stack b = ", 10);
	while (i < data->len_b)
	{
        ft_putnbr_fd(data->stack_b[i], 1);
		write(i, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

// void    ft_free(t_data *data)
// {
//     free(data->stack_a);
//     free(data->stack_b);
// }

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