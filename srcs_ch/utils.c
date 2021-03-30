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
    int     c;

	i = 0;
    c = ' ';
	ft_putstr_fd(cmd, 1);
	write(1, "stack a = ", 10);
	while (i < data->len_a)
	{
		ft_putnbr(data->stack_a[i]);
		ft_putchar(c);
		i++;
	}
	ft_putchar('\n');
	i = 0;
	write(1, "stack b = ", 10);
	while (i < data->len_b)
	{
        ft_putnbr(data->stack_b[i]);
		ft_putchar(c);
		i++;
	}
	ft_putchar('\n');
}

void    ft_free_all(t_data *data)
{
    free(data->stack_a);
    free(data->stack_b);
    free(data->value_chunck);
    ft_free_tab(data->tab_cmd);
}

void    ft_free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab && tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
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

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;
	if (s2 == NULL || s1 == NULL)
		return (NULL);
	if (!(dest = malloc((ft_strlen((char*)s1) +
		ft_strlen((char*)s2)) * sizeof(char*))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	free(s1);
	return (dest);
}