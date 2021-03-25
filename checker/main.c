#include "./include/checker.h"

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

int     parsing(t_data *data, int argc, char **argv)
{
    size_t i;
    size_t j;

    i = 1;
    j = 0;
    if (argc < 2)
        return (-1);
    if (!ft_strncmp(argv[1], "-v", 2))
    {
        data->debug = 1;
        i = 2;
    }
    if (check_digit(argc, argv, i))
        return (-1);
    data->stack_a = malloc(sizeof(int) * data->len);
    data->stack_b = malloc(sizeof(int) * data->len);
    if (data->stack_a == NULL || data->stack_b == NULL)
        return (-1);
    while (i < data->len)
    {
        data->stack_a[j] = ft_atoi(argv[i]);
        i++;
        j++;
        data->len_a++;
    }
    // printf("stack[0] = %i et stack[1] = %i\n", data->stack_a[0], data->stack_a[1]);
    ft_bzero(data->stack_b, data->len);
    return (0);
}

int     read_cmd(t_data *data)
{
    char *line;

    line = "";
    data->instruction = "";
    while (get_next_line(0, &line))
	{
		data->instruction = ft_strjoin(data->instruction, line);
		data->instruction = ft_strjoin(data->instruction, " ");
		free(line);
		line = NULL;
	}
    data->tab_cmd = ft_split(data->instruction, ' ');
    // ft_print_tab(data->tab_cmd);
    // printf("line = %s\n", data->tab_cmd[0]);
    return (0);
}

int     apply_cmd(t_data *data)
{
    int     i;

    i = 0;
    while (data->tab_cmd[i])
    {
        if (check_cmd(data, i) < 0)
        {
            write(1, "Error\nInstruction invalide!\n", 28);
            return (-1);
        }
        i++;
    }
    return (0);
}

int     main(int argc, char **argv)
{
    int     i;
    t_data  data;

    i = 0;
    data.len = (argc);
    data.debug = 0;
    data.len_a = 0;
    data.len_b = 0;
    if (parsing(&data, argc, argv) < 0)
        return (-1);
    // printf("debug = %i\n", data.debug);
    read_cmd(&data);
    apply_cmd(&data);

    return (0);
}