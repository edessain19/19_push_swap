#include "../include/checker.h"

// int     checker(int **tab)
// {


//     return (0);
// }

int     main(int argc, char **argv)
{
    int     *tab;
    int     i;

    i = 0;
    if (argc < 2)
        return (-1);
    tab = malloc(sizeof(int) * argc);
    if (tab == NULL)
        return (-1);
    while (i < argc - 1)
    {
        tab[i] = ft_atoi(argv[i + 1]);
        i++;
        printf("tab[%i] = %i\n", i, tab[i]);
    }
    // checker(tab);
    return (0);
}