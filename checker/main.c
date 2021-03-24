#include "../include/checker.h"

int     checker(int *tab)
{
    

    return (0);
}

int     main(int argc, char **argv)
{
    int     *tab;
    int     i;
    int     len;

    i = 0;
    len = argc - 1;
    if (argc < 2)
        return (-1);
    tab = malloc(sizeof(int) * len);
    if (tab == NULL)
        return (-1);
    while (i < len)
    {
        tab[i] = ft_atoi(argv[i + 1]);
        printf("tab[%i] = %i\n", i, tab[i]);
        i++;
    }
    checker(tab);
    
    return (0);
}