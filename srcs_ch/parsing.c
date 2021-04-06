/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:02:26 by edessain          #+#    #+#             */
/*   Updated: 2021/03/31 14:52:16 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_atoi_ps(const char *str, t_data *data)
{
	int					i;
	int					sign;
	unsigned long int	value;

	i = 0;
	sign = 1;
	value = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (value < 2147483660 && str[i] >= '0' && str[i] <= '9')
	{
		value = ((value * 10) + (str[i] - 48));
		i++;
	}
	if ((value > 2147483647 && sign == 1) || (value > 2147483648 && sign == -1))
		data->size++;
	return (value * sign);
}

int	malloc_stack(t_data *data, int argc, char **argv, int i)
{
	data->stack_a = malloc(sizeof(int) * data->len);
	data->stack_b = malloc(sizeof(int) * data->len);
	if (data->stack_a == NULL || data->stack_b == NULL)
		return (-1);
	if (check_digit(argc, argv, i) < 0)
		return (-1);
	ft_bzero(data->stack_b, data->len);
	return (0);
}

int	ft_parse_string(t_data *data, int argc, char **argv, int i)
{
	char	**tab;

	tab = ft_split(argv[i], ' ');
	while (tab[data->len])
		data->len++;
	if (malloc_stack(data, argc, tab, 0) < 0)
	{
		ft_free_tab(tab);
		return (-1);
	}
	i = 0;
	while (i < data->len)
	{
		data->stack_a[i] = ft_atoi_ps(tab[i], data);
		i++;
		data->len_a++;
	}
	if (data->size != 0)
		return (-1);
	ft_free_tab(tab);
	return (0);
}

int	parsing(t_data *data, int argc, char **argv, int j)
{
	int	i;

	i = check_parsing(data, argc, argv);
	if (i == -1)
		return (-1);
	while (argv[i][j])
	{
		if (argv[i][j] == ' ')
			return (ft_parse_string(data, argc, argv, i));
		j++;
	}
	data->len = argc - i;
	if (malloc_stack(data, argc, argv, i) < 0)
		return (-1);
	j = -1;
	while (++j < data->len)
	{
		data->stack_a[j] = ft_atoi_ps(argv[i], data);
		i++;
		data->len_a++;
	}
	if (data->size != 0)
		return (-1);
	return (0);
}
