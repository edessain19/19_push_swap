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
		sa(data);
	return (1);
}

int	ft_batch_3(t_data *data)
{
	if (check_order_stack(data) == 1)
		return (1);
	else if (data->stack_a[0] > data->stack_a[1] && data->stack_a[1]
		< data->stack_a[2] && data->stack_a[2] > data->stack_a[0])
	{
		sa(data);
		return (1);
	}
	else if (data->stack_a[0] > data->stack_a[1] && data->stack_a[1]
		> data->stack_a[2] && data->stack_a[2] < data->stack_a[0])
	{
		sa(data);
		rra(data);
		return (1);
	}
	else if (data->stack_a[0] > data->stack_a[1] && data->stack_a[1]
		< data->stack_a[2] && data->stack_a[2] < data->stack_a[0])
	{
		ra(data);
		return (1);
	}
	else if (data->stack_a[0] < data->stack_a[1] && data->stack_a[1]
		> data->stack_a[2] && data->stack_a[2] > data->stack_a[0])
	{
		sa(data);
		ra(data);
		return (1);
	}
	else if (data->stack_a[0] < data->stack_a[1] && data->stack_a[1]
		> data->stack_a[2] && data->stack_a[2] < data->stack_a[0])
	{
		rra(data);
		return (1);
	}
	return (1);
}

int	ft_batch_4(t_data *data)
{
	if (check_order_stack(data) == 1)
		return (1);
	pb(data);
	ft_batch_3(data);
	pa(data);
	if (data->stack_a[0] < data->stack_a[1])
		return (1);
	else if (data->stack_a[0] < data->stack_a[2])
		sa(data);
	else if (data->stack_a[0] < data->stack_a[3])
	{
		rra(data);
		sa(data);
		ra(data);
		ra(data);
	}
	else
		ra(data);
	return (1);
}

int	ft_batch_5(t_data *data)
{
	if (check_order_stack(data) == 1)
		return (1);
	pb(data);
	ft_batch_4(data);
	pa(data);
	if (data->stack_a[0] < data->stack_a[1])
		return (1);
	else if (data->stack_a[0] < data->stack_a[2])
		sa(data);
	else if (data->stack_a[0] < data->stack_a[3])
	{
		rra(data);
		sa(data);
		ra(data);
		ra(data);
	}
	else if (data->stack_a[0] < data->stack_a[4])
	{
		rra(data);
		rra(data);
		sa(data);
		ra(data);
		ra(data);
		ra(data);
	}
	else
		 ra(data);
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
