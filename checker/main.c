#include "./include/checker.h"

print_tab(int *tab)
{
    int i;

    i = 0;
    while (tab && tab[i])
    {
        printf()

    }

}

int     parsing(t_data *data, int argc, char **argv, int len)
{
    int i;

    i = 0;
    if (argc < 2)
        return (-1);
    data->stack_a = malloc(sizeof(int) * len);
    data->stack_b = malloc(sizeof(int) * len);
    if (data->stack_a == NULL || data->stack_b == NULL)
        return (-1);
    while (i < len)
    {
        if (i != 0 && ft_isdigit((int)argv[i]))
            return (-1);
        data->stack_a[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    ft_bzero(data->stack_b, len);
    return (0);
}

int     read_cmd(t_data *data)
{
    char *line;

    line = "";
    while (get_next_line(0, &line))
	{
		data->instruction = ft_strjoin(data->instruction, line);
		data->instruction = ft_strjoin(data->instruction, " ");
		free(line);
		line = NULL;
	}
    data->tab_cmd = ft_split(data->instruction, ' ');
    printf("line = %s\n", data->tab_cmd[0]);
    return (0);
}

// int     apply_cmd(t_data *data)
// {
//     int     i;

//     i = 0;


// }

int     main(int argc, char **argv)
{
    int     i;
    int     len;
    t_data  data;

    i = 0;
    len = argc - 1;
    if (parsing(&data, argc, argv, len) < 0)
        return (-1);
    read_cmd(&data);
    // apply_cmd(&data);

    return (0);
}