/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:44:22 by edessain          #+#    #+#             */
/*   Updated: 2021/03/29 17:44:53 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		read_cmd(t_data *data)
{
	char	*line;

	line = "";
	data->instruction = "";
	while (get_next_line(0, &line))
	{
		data->instruction = ft_strjoin(data->instruction, line);
		data->instruction = ft_strjoin_free(data->instruction, " ");
		free(line);
		line = NULL;
	}
	data->tab_cmd = ft_split(data->instruction, ' ');
    // free(data->instruction);
	return (0);
}

int		apply_cmd(t_data *data)
{
	int		i;

	i = 0;
	while (data->tab_cmd[i])
	{
		if (check_cmd(data, i) < 0)
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	t_data	data;

	i = 0;
	init_struct(&data, argc);
	if (parsing(&data, argc, argv) < 0)
		return (-1);
	read_cmd(&data);
	apply_cmd(&data);
	check_order(&data);
    // ft_print_tab(data.stack_a, data.len_a);
    // ft_print_tab(data.stack_b, data.len_b);
	ft_free_all(&data);
	return (0);
}