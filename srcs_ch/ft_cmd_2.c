/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:48:46 by edessain          #+#    #+#             */
/*   Updated: 2021/03/29 17:54:53 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		rr(t_data *data)
{
	ra(data);
	rb(data);
	return (0);
}

int		ra(t_data *data)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = data->len_a;
	tmp = data->stack_a[i];
	while (i + 1 < j)
	{
		data->stack_a[i] = data->stack_a[i + 1];
		i++;
	}
	data->stack_a[i] = tmp;
	if (data->debug == 1)
		ft_print_stack(data, "---ra---\n");
	return (0);
}

int		rb(t_data *data)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = data->len_b;
	tmp = data->stack_b[i];
	while (i + 1 < j)
	{
		data->stack_b[i] = data->stack_b[i + 1];
		i++;
	}
	data->stack_b[i] = tmp;
	if (data->debug == 1)
		ft_print_stack(data, "---rb---\n");
	return (0);
}

int		rrr(t_data *data)
{
	rra(data);
	rrb(data);
	return (0);
}

int		rra(t_data *data)
{
	int		i;
	int		tmp;

	i = data->len_a;
	tmp = data->stack_a[i - 1];
	while(i > 0)
	{
		data->stack_a[i] = data->stack_a[i - 1];
		i--;
	}
	data->stack_a[i] = tmp;
	if (data->debug == 1)
		ft_print_stack(data, "---rra---\n");
	return (0);
}