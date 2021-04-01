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

int	get_nbr_chunck(int size)
{
	if (size < 10)
		return (2);
	if (size < 99)
		return (4);
	else if (size < 495)
		return (8);
	else
		return (16);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	init_struct(&data);
	if (parsing(&data, argc, argv, 0) < 0)
		return (ft_error(&data));
	data.chunck = get_nbr_chunck(data.len);
	if (quick_sort(&data, 1) < 0)
		return (ft_error(&data));
	// printf("data.chunck = %i\n", data.chunck);
	// ft_print_tab(data.value_chunck, data.chunck);
	if (data.len <= 5)
		ft_small_batch(&data);
	else
		algo_ps(&data);
	// ft_print_tab(data.stack_a, data.len_a);
	ft_free_all(&data);
	return (0);
}
