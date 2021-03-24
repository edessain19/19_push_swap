#include "./include/checker.h"

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
    data->tab_instr = ft_split(data->instruction, ' ');
    return (0);
}

// int     apply_cmd(t_data *data)
// {
//     int     i;

//     i = 0;


// }

int     main(int argc, char **argv)
{
    int     *tab;
    int     i;
    int     len;
    t_data  data;

    i = 0;
    len = argc - 1;
    if (argc < 2)
        return (-1);
    tab = malloc(sizeof(int) * len);
    if (tab == NULL)
        return (-1);
    while (i < len)
    {
        if (!ft_isdigit(argv[i]))
            return (-1);
        tab[i] = ft_atoi(argv[i + 1]);
        printf("tab[%i] = %i\n", i, tab[i]);
        i++;
    }
    read_cmd(&data);
    apply_cmd(&data);

    return (0);
}