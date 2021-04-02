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
	{
		sa(data);
		write(1, "sa\n", 3);
	}
	return (1);
}

int	ft_batch_3_bis(t_data *data)
{
	if (data->stack_a[0] > data->stack_a[1] && data->stack_a[1] < data->stack_a[2]
		&& data->stack_a[2] < data->stack_a[0])
	{
		ra(data);
		write(1, "ra\n", 3);
		return (1);
	}
	else if (data->stack_a[0] < data->stack_a[1] && data->stack_a[1] > data->stack_a[2]
		&& data->stack_a[2] > data->stack_a[0])
	{
		sa(data);
		ra(data);
		write(1, "sa\n", 3);
		write(1, "ra\n", 3);
		return (1);
	}
	else if (data->stack_a[0] < data->stack_a[1] && data->stack_a[1] > data->stack_a[2]
		&& data->stack_a[2] < data->stack_a[0])
	{
		rra(data);
		write(1, "rra\n", 4);
		return (1);
	}
	return (1);
}

int	ft_batch_3(t_data *data)
{
	if (data->stack_a[0] < data->stack_a[1] && data->stack_a[1] < data->stack_a[2])
		return (1);
	else if (data->stack_a[0] > data->stack_a[1] && data->stack_a[1] < data->stack_a[2]
		&& data->stack_a[2] > data->stack_a[0])
	{
		sa(data);
		write(1, "sa\n", 3);
		return (1);
	}
	else if (data->stack_a[0] > data->stack_a[1] && data->stack_a[1] > data->stack_a[2]
		&& data->stack_a[2] < data->stack_a[0])
	{
		sa(data);
		rra(data);
		write(1, "sa\n", 3);
		write(1, "rra\n", 4);
		return (1);
	}
	ft_batch_3_bis(data);
	return (1);
}

int	ft_batch_4(t_data *data)
{
	pb(data);
	write(1, "pb\n", 3);
	ft_batch_3(data);
	pa(data);
	write(1, "pa\n", 3);
	if (data->stack_a[0] > data->stack_a[1])
	{
		sa(data);
		write(1, "sa\n", 3);
		pb(data);
		write(1, "pb\n", 3);
		ft_batch_3(data);
		pa(data);
		write(1, "pa\n", 3);
		return (1);
	}
	return (1);
}

int	ft_batch_5(t_data *data)
{
	bring_above(data);
	pb(data);
	write(1, "pb\n", 3);
	bring_above(data);
	pb(data);
	write(1, "pb\n", 3);
	ft_batch_3(data);
	pa(data);
	write(1, "pa\n", 3);
	if (data->stack_a[0] > data->stack_a[1])
	{
		sa(data);
		write(1, "sa\n", 3);
		pb(data);
		write(1, "pb\n", 3);
		ft_batch_3(data);
		pa(data);
		write(1, "pa\n", 3);
	}
	pa(data);
	write(1, "pa\n", 3);
	if (data->stack_a[0] > data->stack_a[1])
		ft_batch_4(data);
	return (1);
}
