# include "../include/push_swap.h"

int     get_nbr_chunck(int size)
{
    if (size < 99)
        return (4);
    else if (size < 495)
        return (6);
    else
        return (11);
}

int     main(int argc, char **argv)
{
    t_data  data;
    int     i;

    i = 0;
    init_struct(&data, argc);
    if (parsing(&data, argc, argv) < 0)
        return (-1);
    data.chunck = get_nbr_chunck(data.len);
    quick_sort(&data);
    if (data.len <= 5)
        ft_small_batch(&data);
    else
        algo_ps(&data);
    return (0);
}