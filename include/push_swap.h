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
}                   t_data;

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


void ft_print_tab(char **tab);
void    ft_print_stack(t_data *data, char *cmd);




#endif