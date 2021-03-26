#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_data
{
    char    *instruction;
    char    **tab_cmd;
    int     *stack_a;
    int     *stack_b;
    int     len;
    int     len_a;
    int     len_b;
    int     debug;
    int     chunck;
}                   t_data;

/*
** **********************Checker***************************************************
*/

int     main(int argc, char **argv);
int     read_cmd(t_data *data);
int     apply_cmd(t_data *data);
int     check_cmd(t_data *data, int i);
int     check_order(t_data *data);

/*
** tools.c
*/

int		check_digit(int argc, char **argv, int i);
int     parsing(t_data *data, int argc, char **argv);
int     check_parsing(t_data *data, int argc, char **argv);
int     ft_parse_string(t_data *data, int argc, char **argv, int i);
void    ft_free(t_data *data);
void    init_struct(t_data *data, int i);


/*
** Commande
*/

int     ss(t_data *data);
int     sa(t_data *data);
int     sb(t_data *data);
int     pa(t_data *data);
int     pb(t_data *data);
int     rr(t_data *data);
int     ra(t_data *data);
int     rb(t_data *data);
int     rrr(t_data *data);
int     rra(t_data *data);
int     rrb(t_data *data);

/*
** **********************Checker***************************************************
*/

int     ft_small_batch(t_data *data);
int     ft_batch_4(t_data *data);
int     ft_bath_3(t_data *data);
int     ft_batch_2(t_data *data);












void    ft_print_tab(int *tab, int len);
void    ft_print_stack(t_data *data, char *cmd);




#endif