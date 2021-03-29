# include "../include/push_swap.h"

void    ft_push_b(t_data *data, int i, int bool)
{
    if (bool == 0)
    {
        while (i != 0)
        {
            rb(data);
            write(1, "rb\n", 3);
            i--;
        }
        pa(data);
        write(1, "pa\n", 3);
    }
    else
    {
        while (i < data->len_b)
        {
            rrb(data);
            write(1, "rrb\n", 4);
            i++;
        }
        pa(data);
        write(1, "pa\n", 3);
    }
}

int     find_max(t_data *data)
{
    int i;
    int nb_max;

    i = 1;
    nb_max = 0;
    while (i < data->len_b)
    {
        if (data->stack_b[nb_max] < data->stack_b[i])
            nb_max = i;
        i++;
    }
    return (nb_max);
}

int     sort_b(t_data *data)
{
    int nb_max;
    int i;

    i = data->len_b;
    nb_max = 0;
    while (i > 0)
    {
        nb_max = find_max(data);
        if (nb_max < (data->len_b / 2))
            ft_push_b(data, nb_max, 0);
        else
            ft_push_b(data, nb_max, 1);
        i--;
    }
    // ft_print_tab(data->stack_a, data->len_a);
    return (0);
}