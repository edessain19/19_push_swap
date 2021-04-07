/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:20:11 by edessain          #+#    #+#             */
/*   Updated: 2021/03/31 18:41:35 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	bring_above(t_data *data)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i < data->len_a)
	{
		if (data->stack_a[i] < data->stack_a[index])
			index = i;
		i++;
	}
	while (index > 0)
	{
		ra(data);
		write(1, "ra\n", 3);
		index--;
	}
	pb(data);
	write(1, "pb\n", 3);
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

int	get_nbr_chunck(int size)
{
	if (size < 5)
		return (1);
	else if (size < 12)
		return (3);
	else if (size < 99)
		return (5);
	else if (size < 495)
		return (9);
	else
		return (16);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	init_struct(&data);
	if (argc < 2)
		return (0);
	if (parsing(&data, argc, argv, 0) < 0)
		return (ft_error(&data));
	data.chunck = get_nbr_chunck(data.len);
	if (quick_sort(&data, 1) < 0)
		return (ft_error(&data));
	if (data.len <= 5)
		ft_small_batch(&data);
	else
		algo_ps(&data);
	ft_free_all(&data);
	return (0);
}
