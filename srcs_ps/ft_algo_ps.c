# include "../include/push_swap.h"

void    send_to_chunck(t_data *data, int i, int bool)
{
    if (bool == 0)
    {
        while (i != 0)
        {
            ra(data);
            i--;
        }
        pa(data);
    }
    else
    {
        while (i < data->len_a + 1)
        {
            rra(data);
            i++;
        }
        pa(data);
    }
}

void    make_chunck(t_data *data, int i)
{
    while (i < data->len)
    {
        if (data->stack_a[i] < data->value_chunck[j])
        {
            if (i < data->len_a / 2)
                send_to_chunck(data, i, 0);
            else
                send_to_chunck(data, i, 1);
        }
        if ((data->stack_a[i] > data->value_chunck[data->chunck - j]) && (data->chunck - j != j))
        {
            if (i < data->len_a / 2)
            {
                while (i-- != 0)
                    ra(data);
                pa(data);
                rb(data);
            }
            else
            {
                while (i < data->len_a + 1)
                {
                    rra(data);
                    i++;
                }
                i = 0;
                pa(data);
                rb(data);
            }
        }
        i++;
    }
}

int     sort_in_chunck(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (j < data->chunck - 1)
    {
        void    make_chunck(data, i);
        j++;
        i = 0;
    }
}

int     algo_ps(t_data *data)
{
    sort_in_chunck(data);

    return (0);
}