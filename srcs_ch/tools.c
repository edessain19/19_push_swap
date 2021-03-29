/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:02:26 by edessain          #+#    #+#             */
/*   Updated: 2021/03/29 18:02:43 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void    ft_free(t_data *data)
// {
//     free(data->stack_a);
//     free(data->stack_b);
// }

void	init_struct(t_data *data, int i)
{
	i = 1;
	data->instruction = NULL;
	data->tab_cmd = NULL;
	data->len = 0;
	data->debug = 0;
	data->len_a = 0;
	data->len_b = 0;
	data->chunck = 0;
	data->value_chunck = NULL;
	data->nb_max = 0;
}

int		check_parsing(t_data *data, int argc, char **argv)
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

int		ft_parse_string(t_data *data, int argc, char **argv, int i)
{
	char	**tab;

	tab = ft_split(argv[i], ' ');
	while (tab[data->len])
		data->len++;
	data->stack_a = malloc(sizeof(int) * data->len - 1);
	data->stack_b = malloc(sizeof(int) * data->len - 1);
	if (data->stack_a == NULL || data->stack_b == NULL)
		return (-1);
	if (check_digit(argc, tab, 0))
		return (-1);
	i = 0;
	while (i < data->len)
	{
		data->stack_a[i] = ft_atoi(tab[i]);
		i++;
		data->len_a++;
	}
	ft_bzero(data->stack_b, data->len);
	return (0);
}

int		parsing(t_data *data, int argc, char **argv)
{
	int		i;
	int		j;

	j = 0;
	i = check_parsing(data, argc, argv);
	if (i == -1)
		return (-1);
	while (argv[i][j])
	{
		if (argv[i][j] == ' ')
			return (ft_parse_string(data, argc, argv, i));
		j++;
	}
	data->len = argc - i;
	data->stack_a = malloc(sizeof(int) * data->len - 1);
	data->stack_b = malloc(sizeof(int) * data->len - 1);
	if (data->stack_a == NULL || data->stack_b == NULL)
		return (-1);
	j = 0;
	if (check_digit(argc, argv, i))
		return (-1);
	while (j < data->len)
	{
		data->stack_a[j] = ft_atoi(argv[i]);
		i++;
		j++;
		data->len_a++;
	}
	ft_bzero(data->stack_b, data->len);
	return (0);
}

int		check_digit(int argc, char **argv, int i)
{
	int		j;

	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	ft_print_tab(int *tab, int len)
{
	int		i;

	i = 0;
	printf("-----------\n");
	while (i < len)
	{
		printf("tab[%i] = %i\n", i, tab[i]);
		i++;
	}
	printf("-----------\n");
}
