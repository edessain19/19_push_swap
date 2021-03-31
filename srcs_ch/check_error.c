/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:02:26 by edessain          #+#    #+#             */
/*   Updated: 2021/03/31 14:52:16 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/////// 3 0 2 1 4 ////////

int	ft_error(t_data *data)
{
	write(2, "Error\n", 6);
	ft_free_all(data);
	return (-1);
}

void	init_struct(t_data *data)
{
	data->instruction = NULL;
	data->tab_cmd = NULL;
	data->len = 0;
	data->debug = 0;
	data->len_a = 0;
	data->len_b = 0;
	data->chunck = 0;
	data->value_chunck = NULL;
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->tab_cmd = NULL;
	data->nb_max = 0;
}

int	check_parsing(t_data *data, int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc < 2)
		return (-1);
	if (!ft_strncmp(argv[1], "-v", 2))
	{
		data->debug = 1;
		i = 2;
	}
	return (i);
}

int	check_digit(int argc, char **argv, int i)
{
	int		j;

	j = 0;
	argc = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '-')
				j++;
			if (ft_isdigit(argv[i][j]))
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
