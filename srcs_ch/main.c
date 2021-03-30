/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:44:22 by edessain          #+#    #+#             */
/*   Updated: 2021/03/30 16:07:55 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	read_cmd(t_data *data)
{
	char	*line;

	line = "";
	data->instruction = ft_strdup("");
	while (get_next_line(0, &line))
	{
		data->instruction = ft_strjoin_free(data->instruction, line);
		if (data->instruction == NULL)
			return (-1);
		data->instruction = ft_strjoin_free(data->instruction, " ");
		if (data->instruction == NULL)
			return (-1);
		free(line);
		line = NULL;
	}
	free(line);
	data->tab_cmd = ft_split(data->instruction, ' ');
	if (!(data->tab_cmd))
	{
		free(data->instruction);
		return (-1);
	}
	free(data->instruction);
	return (0);
}

int	apply_cmd(t_data *data)
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

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;

	i = 0;
	init_struct(&data);
	if (parsing(&data, argc, argv) < 0)
		return (-1);
	if (read_cmd(&data) < 0)
		return (-1);
	if (apply_cmd(&data) < 0)
		return (-1);
	check_order(&data);
	ft_free_all(&data);
	return (0);
}
