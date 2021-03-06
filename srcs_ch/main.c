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

int	check_space(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == ' ')
			return (-1);
		i++;
	}
	return (0);
}

int	read_cmd(t_data *data)
{
	char	*line;

	line = "";
	data->instruction = ft_strdup("");
	while (get_next_line(0, &line))
	{
		data->instruction = ft_strjoin_free(data->instruction, line);
		if (check_space(line) < 0 || data->instruction == NULL)
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
	while (data->tab_cmd && data->tab_cmd[i])
	{
		if (check_cmd(data, i) < 0)
			return (-1);
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
	if (argc < 2)
		return (0);
	if (parsing(&data, argc, argv, 0) < 0)
		return (ft_error(&data));
	if (quick_sort(&data, 0) < 0)
		return (ft_error(&data));
	if (read_cmd(&data) < 0)
		return (ft_error(&data));
	if (apply_cmd(&data) < 0)
		return (ft_error(&data));
	check_order(&data);
	ft_free_all(&data);
	return (0);
}
