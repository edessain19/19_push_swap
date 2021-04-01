/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_batch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:13:59 by edessain          #+#    #+#             */
/*   Updated: 2021/03/30 17:19:54 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_batch_2(t_data *data)
{
	if (data->stack_a[0] > data->stack_a[1])
		write(1, "sa\n", 3);
	return (1);
}

int	ft_batch_3(t_data *data)
{
	if (check_order_stack(data) == 1)
		return (1);
	else if (data->stack_a[0] > data->stack_a[1] && data->stack_a[1]
		< data->stack_a[2] && data->stack_a[2] > data->stack_a[0])
	{
		write(1, "sa\n", 3);
		return (1);
	}
	else if (data->stack_a[0] > data->stack_a[1] && data->stack_a[1]
		> data->stack_a[2] && data->stack_a[2] < data->stack_a[0])
	{
		write(1, "sa\n", 3);
		write(1, "rra\n", 4);
		return (1);
	}
	else if (data->stack_a[0] > data->stack_a[1] && data->stack_a[1]
		< data->stack_a[2] && data->stack_a[2] < data->stack_a[0])
	{
		write(1, "ra\n", 3);
		return (1);
	}
	else if (data->stack_a[0] < data->stack_a[1] && data->stack_a[1]
		> data->stack_a[2] && data->stack_a[2] > data->stack_a[0])
	{
		write(1, "sa\n", 3);
		write(1, "ra\n", 3);
		return (1);
	}
	else if (data->stack_a[0] < data->stack_a[1] && data->stack_a[1]
		> data->stack_a[2] && data->stack_a[2] < data->stack_a[0])
	{
		write(1, "rra\n", 4);
		return (1);
	}
	return (1);
}

int	ft_batch_4(t_data *data)
{
	if (check_order_stack(data) == 1)
		return (1);
	write(1, "pb\n", 3);
	ft_batch_3(data);
	write(1, "pa\n", 3);
	if (data->stack_a[0] < data->stack_a[1])
		return (1);
	else if (data->stack_a[0] < data->stack_a[2])
		write(1, "sa\n", 3);
	else if (data->stack_a[0] < data->stack_a[3])
	{
		write(1, "rra\n", 4);
		write(1, "sa\n", 3);
		write(1, "ra\n", 3);
		write(1, "ra\n", 3);
	}
	else
		write(1, "ra\n", 3);
	return (1);
}

int	ft_batch_5(t_data *data)
{
	if (check_order_stack(data) == 1)
		return (1);
	write(1, "pb\n", 3);
	ft_batch_4(data);
	write(1, "pa\n", 3);
	if (data->stack_a[0] < data->stack_a[1])
		return (1);
	else if (data->stack_a[0] < data->stack_a[2])
		write(1, "sa\n", 3);
	else if (data->stack_a[0] < data->stack_a[3])
	{
		write(1, "rra\n", 4);
		write(1, "sa\n", 3);
		write(1, "ra\n", 3);
		write(1, "ra\n", 3);
	}
	else if (data->stack_a[0] < data->stack_a[4])
	{
		write(1, "rra\n", 4);
		write(1, "rra\n", 4);
		write(1, "sa\n", 3);
		write(1, "ra\n", 3);
		write(1, "ra\n", 3);
		write(1, "ra\n", 3);
	}
	else
		 write(1, "ra\n", 3);
	return (0);
}

int	ft_small_batch(t_data *data)
{
	int		i;

	i = 0;
	if (data->len == 2)
		ft_batch_2(data);
	else if (data->len == 3)
		ft_batch_3(data);
	else if (data->len == 4)
		ft_batch_4(data);
	else if (data->len == 5)
		ft_batch_5(data);
	return (0);
}
