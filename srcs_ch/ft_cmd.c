/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:48:46 by edessain          #+#    #+#             */
/*   Updated: 2021/03/30 15:29:23 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ss(t_data *data)
{
	sa(data);
	sb(data);
	return (0);
}

int	sa(t_data *data)
{
	int		tmp;

	if (data->len_a < 2)
		return (0);
	tmp = data->stack_a[0];
	data->stack_a[0] = data->stack_a[1];
	data->stack_a[1] = tmp;
	if (data->debug == 1)
		ft_print_stack(data, "---sa---\n");
	return (0);
}

int	sb(t_data *data)
{
	int		tmp;

	if (data->len_b < 2)
		return (0);
	tmp = data->stack_b[0];
	data->stack_b[0] = data->stack_b[1];
	data->stack_b[1] = tmp;
	if (data->debug == 1)
		ft_print_stack(data, "---sb---\n");
	return (0);
}

int	pa(t_data *data)
{
	int		i;

	i = data->len_a;
	if (data->len_b < 1)
		return (0);
	while (i > 0)
	{
		data->stack_a[i] = data->stack_a[i - 1];
		i--;
	}
	data->stack_a[0] = data->stack_b[0];
	data->len_a++;
	i = 0;
	data->len_b--;
	while (i < data->len_b)
	{
		data->stack_b[i] = data->stack_b[i + 1];
		i++;
	}
	if (data->debug == 1)
		ft_print_stack(data, "---pa---\n");
	return (0);
}

int	pb(t_data *data)
{
	int		i;

	i = data->len_b;
	if (data->len_a < 1)
		return (0);
	while (i > 0)
	{
		data->stack_b[i] = data->stack_b[i - 1];
		i--;
	}
	data->stack_b[0] = data->stack_a[0];
	data->len_b++;
	i = 0;
	data->len_a--;
	while (i < data->len_a)
	{
		data->stack_a[i] = data->stack_a[i + 1];
		i++;
	}
	if (data->debug == 1)
		ft_print_stack(data, "---pb---\n");
	return (0);
}

int	rrb(t_data *data)
{
	int		i;
	int		tmp;

	i = data->len_b;
	tmp = data->stack_b[i - 1];
	if (data->len_b < 2)
		return (0);
	while (i > 0)
	{
		data->stack_b[i] = data->stack_b[i - 1];
		i--;
	}
	data->stack_b[i] = tmp;
	if (data->debug == 1)
		ft_print_stack(data, "---rrb---\n");
	return (0);
}
