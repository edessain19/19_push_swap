#include "../include/push_swap.h"

int     ft_batch_2(t_data *data)
{
    if (data->stack_a[0] > data->stack_a[1])
    {
        sa(data);
        write(1, "sa\n", 3);
    }
    return (1);
}

int     ft_batch_3(t_data *data)
{
    if (data->stack_a[0] < data->stack_a[1] && data->stack_a[1] < data->stack_a[2])
        return (1);
    else if (data->stack_a[0] > data->stack_a[1] && data->stack_a[1] < data->stack_a[2] &&
            data->stack_a[2] > data->stack_a[0])
    {
        sa(data);
        write(1, "sa\n", 3);
        return (1);
    }
    else if (data->stack_a[0] > data->stack_a[1] && data->stack_a[1] > data->stack_a[2] &&
            data->stack_a[2] < data->stack_a[0])
    {
        sa(data);
        rra(data);
        write(1, "sa\n", 3);
        write(1, "rra\n", 4);
        return (1);
    }
    else if (data->stack_a[0] > data->stack_a[1] && data->stack_a[1] < data->stack_a[2] &&
            data->stack_a[2] < data->stack_a[0])
    {
        ra(data);
        write(1, "ra\n", 3);
        return (1);
    }
    else if (data->stack_a[0] < data->stack_a[1] && data->stack_a[1] > data->stack_a[2] &&
            data->stack_a[2] > data->stack_a[0])
    {
        sa(data);
        ra(data);
        write(1, "sa\n", 3);
        write(1, "ra\n", 3);
        return (1);
    }
    else if (data->stack_a[0] < data->stack_a[1] && data->stack_a[1] > data->stack_a[2] &&
            data->stack_a[2] < data->stack_a[0])
    {
        rra(data);
        write(1, "rra\n", 4);
        return (1);
    }
    return (1);
}

int     ft_batch_4(t_data *data)
{
    if (data->stack_a[0] < data->stack_a[1] && data->stack_a[1] < data->stack_a[2] && data->stack_a[2] < data->stack_a[3])
        return (1);
    pb(data);
    write(1, "pb\n", 3);
    ft_batch_3(data);
    pa(data);
    write(1, "pa\n", 3);
    if (data->stack_a[0] < data->stack_a[1])
        return (1);
    else if (data->stack_a[0] < data->stack_a[2])
    {
        sa(data);
        write(1, "sa\n", 3);
    }
    else if (data->stack_a[0] < data->stack_a[3])
    {
        rra(data);
        sa(data);
        ra(data);
        ra(data);
        write(1, "rra\n", 4);
        write(1, "sa\n", 3);
        write(1, "ra\n", 3);
        write(1, "ra\n", 3);
    }
    else
    {
        ra(data);
        write(1, "ra\n", 3);
    }
    return (1);
}

int     ft_small_batch(t_data *data)
{
    int i;

    i = 0;
    if (data->len == 2)
        ft_batch_2(data);
    else if(data->len == 3)
        ft_batch_3(data);
    else if (data->len == 4)
        ft_batch_4(data);
    return (0);
}