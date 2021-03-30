/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:21:16 by edessain          #+#    #+#             */
/*   Updated: 2021/03/30 17:27:50 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	send_to_chunck(t_data *data, int i, int bool)
{
	if (bool == 0)
	{
		while (i != 0)
		{
			ra(data);
			write(1, "ra\n", 3);
			i--;
		}
		pb(data);
		write(1, "pb\n", 3);
	}
	else
	{
		while (i < data->len_a)
		{
			rra(data);
			write(1, "rra\n", 4);
			i++;
		}
		pb(data);
		write(1, "pb\n", 3);
	}
}

int	sort_in_chunck(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j <= data->chunck)
	{
		while (i <= data->len_a)
		{
			if ((j != data->chunck && data->stack_a[i]
					<= data->value_chunck[j]) || (j == data->chunck
					&& data->stack_a[i] < data->value_chunck[j]))
			{
				if (i <= data->len_a / 2)
					send_to_chunck(data, i, 0);
				else
					send_to_chunck(data, i, 1);
				i = -1;
			}
			else if (j + 1 <= data->chunck
				&& (data->stack_a[i] < data->value_chunck[j + 1]))
			{
				if (i <= data->len_a / 2)
					send_to_chunck(data, i, 0);
				else
					send_to_chunck(data, i, 1);
				rb(data);
				write(1, "rb\n", 3);
				i = -1;
			}
			i++;
		}
		i = 0;
		j += 2;
	}
	return (0);
}

int	algo_ps(t_data *data)
{
	sort_in_chunck(data);
	sort_b(data);
	return (0);
}
