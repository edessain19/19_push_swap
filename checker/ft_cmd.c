#include "./include/checker.h"

int     ss(t_data *data)
{
    sa(data);
    sb(data);
    return (0);
}

int     sa(t_data *data)
{
    int     tmp;

    if (!data->stack_a[0] || !data->stack_a[1])
        return (0);
    tmp = data->stack_a[0];
    data->stack_a[0] = data->stack_a[1];
    data->stack_a[1] = tmp;
    if (data->debug == 1)
        ft_print_stack(data, "---sa---\n");
    return (0);
}

int     sb(t_data *data)
{
    int     tmp;

    if (!data->stack_b[0] || !data->stack_b[1])
        return (0);
    tmp = data->stack_b[0];
    data->stack_b[0] = data->stack_b[1];
    data->stack_b[1] = tmp;
    if (data->debug == 1)
        ft_print_stack(data, "---sb---\n");
    return (0);
}

int     pa(t_data *data)
{
    size_t i;

    i = data->len_a;
    if (!data->stack_b[0])
        return (0);
    while (i > 0)
    {
        data->stack_a[i] = data->stack_a[i - 1];
        i--;
    }
    data->stack_a[0] = data->stack_b[0];
    data->len_a++;
    i = 0;
    data->len_b--;
    while(i < data->len_b)
    {
        data->stack_b[i] = data->stack_b[i + 1];
        i++;
    }
    if (data->debug == 1)
        ft_print_stack(data, "---pa---\n");
    return (0);
}

int     pb(t_data *data)
{
    size_t i;

    i = data->len_b;
    if (!data->stack_a[0])
        return (0);
    while (i > 0)
    {
        data->stack_b[i] = data->stack_b[i - 1];
        i--;
    }
    data->stack_b[0] = data->stack_a[0];
    data->len_b++;
    i = 0;
    data->len_a--;
    while(i < data->len_a)
    {
        data->stack_a[i] = data->stack_a[i + 1];
        i++;
    }
    if (data->debug == 1)
        ft_print_stack(data, "---pb---\n");
    return (0);
}

int     rr(t_data *data)
{
    ra(data);
    rb(data);
    return (0);
}

int     ra(t_data *data)
{
    int i;
    int j;
    int tmp;

    i = 0;
    j = data->len_a;
    tmp = data->stack_a[i];
    while (i + 1 < j)
    {
        data->stack_a[i] = data->stack_a[i + 1];
        i++;
    }
    data->stack_a[i] = tmp;
    if (data->debug == 1)
        ft_print_stack(data, "---ra---\n");
    return (0);
}

int     rb(t_data *data)
{
    int i;
    int j;
    int tmp;

    i = 0;
    j = data->len_b;
    tmp = data->stack_b[i];
    while (i + 1 < j)
    {
        data->stack_b[i] = data->stack_b[i + 1];
        i++;
    }
    data->stack_b[i] = tmp;
    if (data->debug == 1)
        ft_print_stack(data, "---rb---\n");
    return (0);
}

int     rrr(t_data *data)
{
    rra(data);
    rrb(data);
    return (0);
}

int     rra(t_data *data)
{
    int i;
    int tmp;

    printf("len_a = %zu", data->len_a);
    i = data->len_a;
    tmp = data->stack_a[i - 1];
    while(i > 0)
    {
        data->stack_a[i] = data->stack_a[i - 1];
        i--;
    }
    data->stack_a[i] = tmp;
    if (data->debug == 1)
        ft_print_stack(data, "---rra---\n");
    return (0);
}

int     rrb(t_data *data)
{
    int i;
    int tmp;

    i = data->len_b;
    tmp = data->stack_b[i - 1];
    while(i > 0)
    {
        data->stack_b[i] = data->stack_b[i - 1];
        i--;
    }
    data->stack_b[i] = tmp;
    if (data->debug == 1)
        ft_print_stack(data, "---rrb---\n");
    return (0);
}