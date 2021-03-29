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

int     save_value_chunck(t_data *data, int *tmp)
{
    int i;
    int j;
    int k;
    

    j = data->len_a / data->chunck;
    if (data->len_a % data->chunck)
        j++;
    printf("j = %i\n", j);
    i = 0;
    k = 1;
    data->value_chunck = malloc(sizeof(int) * (data->chunck - 1));
    if (data->value_chunck == NULL)
        return (-1);
    while (i < data->chunck - 1)
    {
        data->value_chunck[i] = tmp[(k * j) - 1];
        i++;
        k++;
    }
    ft_print_tab(data->value_chunck, data->chunck - 1);
    return (0);
}

int     quick_sort(t_data *data)
{
    int     *tmp;
    int     i;
    int     j;
    int     c;

    i = 0;
    j = 1;
    c = 0;
    tmp = malloc(sizeof(int) * data->len_a);
    if (tmp == NULL)
        return (-1);
    while (i < data->len_a)
    {
        tmp[i] = data->stack_a[i];
        i++;
    }
    i = 0;
    printf("len_a = %i\n", data->len_a);
    while (i < data->len_a)
    {
        while (j < data->len_a)
        {
            if (tmp[i] == tmp[j])
                return (-1);
            if (tmp[i] > tmp[j])
            {
                c = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = c;
            }
            j++;
        }
        i++;
        j = i + 1;
    }
    ft_print_tab(tmp, data->len_a);
    save_value_chunck(data, tmp);
    return (0);
}