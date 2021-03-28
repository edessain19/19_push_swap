#include "../include/push_swap.h"

int     check_order_stack(t_data *data)
{
    int i;

    i = 0;
    while (i < data->len_a - 1)
    {
        if (data->stack_a[i] > data->stack_a[i + 1])
            return (0);
        i++;
    }
    return (1);
}