#include "../include/push_swap.h"

int     check_cmd(t_data *data, int i)
{
    if (!ft_strncmp(data->tab_cmd[i], "ss", 3))
        ss(data);
    else if (!ft_strncmp(data->tab_cmd[i], "sa", 3))
        sa(data);
    else if (!ft_strncmp(data->tab_cmd[i], "sb", 3))
        sb(data);
    else if (!ft_strncmp(data->tab_cmd[i], "pa", 3))
        pa(data);
    else if (!ft_strncmp(data->tab_cmd[i], "pb", 3))
        pb(data);
    else if (!ft_strncmp(data->tab_cmd[i], "ra", 3))
        ra(data);
    else if (!ft_strncmp(data->tab_cmd[i], "rb", 3))
        rb(data);
    else if (!ft_strncmp(data->tab_cmd[i], "rr", 3))
        rr(data);
    else if (!ft_strncmp(data->tab_cmd[i], "rra", 4))
        rra(data);
    else if (!ft_strncmp(data->tab_cmd[i], "rrb", 4))
        rrb(data);
    else if (!ft_strncmp(data->tab_cmd[i], "rrr", 4))
        rrr(data);
    else
        return (-1);
    return (0);
}

int     check_order(t_data *data)
{
    int i;

    i = 0;
    while (i < data->len_a - 1)
    {
        if (data->stack_a[i] > data->stack_a[i + 1])
        {
            write(1, "KO\n", 3);
            return (0);
        }
        i++;
    }
    write(1, "OK\n", 3);
    return (0);
}


void ft_print_tab(char **tab)
{
    int i;

    i = 0;
    printf("-----------\n");
    while (tab[i])
    {
        printf("tab[%i] = %s\n", i, tab[i]);
        i++;
    }
    printf("-----------\n");
}