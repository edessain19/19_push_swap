#include "../include/push_swap.h"

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
            write(1, "Error\n", 6);
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
    init_struct(&data, argc);
    if (parsing(&data, argc, argv) < 0)
        return (-1);
    // printf("debug = %i\n", data.debug);
    printf("len = %i\n", data.len);
    ft_print_tab(data.stack_a);
    read_cmd(&data);
    apply_cmd(&data);
    // check_order(&data);
    // ft_free(&data);
    return (0);
}