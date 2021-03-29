# include "../include/push_swap.h"

void    send_to_chunck(t_data *data, int i, int bool)
{
    if (bool == 0)
    {
        while (i != 0)
        {
            ra(data);
            write(1, "ra\n", 3);
            i--;
        }
        pb(data);
        write(1, "pb\n", 3);
    }
    else
    {
        while (i < data->len_a)
        {
            rra(data);
            write(1, "rra\n", 4);
            i++;
        }
        pb(data);
        write(1, "pb\n", 3);
    }
}

int     sort_in_chunck(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (j < data->chunck)
    {
        while (i <= data->len_a)
        {
            if (data->stack_a[i] < data->value_chunck[j])
            {
                if (i <= data->len_a / 2)
                    send_to_chunck(data, i, 0);
                else
                    send_to_chunck(data, i, 1);
                i = -1;
            }
            i++;
        }
        i = 0;
        j++;
    }
    return (0);
}

int     algo_ps(t_data *data)
{
    sort_in_chunck(data);
    sort_b(data);
    // ft_print_tab(data->stack_a, data->len_a);
    // ft_print_tab(data->stack_b, data->len_b);

    return (0);
}