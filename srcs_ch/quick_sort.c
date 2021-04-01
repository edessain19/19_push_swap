/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:55:09 by edessain          #+#    #+#             */
/*   Updated: 2021/03/30 16:15:46 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_order_stack(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->len_a - 1)
	{
		if (data->stack_a[i] > data->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	save_value_chunck(t_data *data, int *tmp)
{
	int		i;
	int		j;
	int		k;

	if (tmp == NULL)
		return (-1);
	j = data->len_a / data->chunck;
	if (data->len_a % data->chunck)
		j++;
	i = 0;
	k = 1;
	data->value_chunck = malloc(sizeof(int) * (data->chunck));
	if (data->value_chunck == NULL)
		return (-1);
	while (i < data->chunck - 1)
	{
		data->value_chunck[i] = tmp[(k * j) - 1];
		i++;
		k++;
	}
	data->value_chunck[i] = tmp[data->len_a - 1];
	return (1);
}

int	*sort_tmp(t_data *data, int *tmp)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	j = 1;
	c = 0;
	while (i < data->len_a)
	{
		while (j < data->len_a)
		{
			if (tmp[i] == tmp[j])
				return (NULL);
			if (tmp[i] > tmp[j])
			{
				c = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = c;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (tmp);
}

int	quick_sort(t_data *data, int x)
{
	int		*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(int) * data->len_a);
	if (tmp == NULL)
		return (-1);
	while (i < data->len_a)
	{
		tmp[i] = data->stack_a[i];
		i++;
	}
	i = 0;
	tmp = sort_tmp(data, tmp);
	if (x == 1)
	{
		if (save_value_chunck(data, tmp) < 0)
		{
			free(tmp);
			return (-1);
		}
	}
	free(tmp);
	return (0);
}
