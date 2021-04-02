#include "../include/push_swap.h"

void	ft_free_all(t_data *data)
{
	free(data->stack_a);
	free(data->stack_b);
	free(data->value_chunck);
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->value_chunck = NULL;
	ft_free_tab(data->tab_cmd);
}

void	ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
