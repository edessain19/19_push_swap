# include "../include/push_swap.h"

int     main(int argc, char **argv)
{
    t_data  data;
    int     i;

    i = 0;
    data.len = (argc);
    data.debug = 0;
    data.len_a = 0;
    data.len_b = 0;
    if (parsing(&data, argc, argv) < 0)
        return (-1);



    return (0);
}