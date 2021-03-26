#include "../include/push_swap.h"

void    ft_free(t_data *data)
{
    free(data->stack_a);
    free(data->stack_b);
}

int     check_parsing(t_data *data, int argc, char **argv)
{
    int     i;
    
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

int     ft_parse_string(t_data *data, int argc, char **argv, int i)
{
    char    *tab;

    tab = ft_split(argv[i + 1], " ");
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

int     parsing(t_data *data, int argc, char **argv)
{
    int i;
    int j;

    j = 0;
    data->stack_a = malloc(sizeof(int) * data->len);
    data->stack_b = malloc(sizeof(int) * data->len);
    if (data->stack_a == NULL || data->stack_b == NULL)
        return (-1);
    i = check_parsing(data, argc, argv);
    if (i == -1)
        return (-1);
    if (argv[i + 1][ft_strlen(argv[i + 1]) == 0])
        return (ft_parse_string(data, argc, argv, i));
    if (check_digit(argc, argv, i))
        return (-1);
    while (i < data->len)
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