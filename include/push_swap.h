#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_data
{
	char	*instruction;
	char	**tab_cmd;
	int		*stack_a;
	int		*stack_b;
	int		len;
	int		len_a;
	int		len_b;
	int		debug;
	int		chunck;
	int		*value_chunck;
	int		nb_max;
}				t_data;

/*
** ********************** Checker ********************************************
*/

int		main(int argc, char **argv);
int		read_cmd(t_data *data);
int		apply_cmd(t_data *data);
int		check_cmd(t_data *data, int i);
int		check_order(t_data *data);

/*
** ********************** Push Swap ******************************************
*/

int		algo_ps(t_data *data);
int		get_nbr_chunck(int size);

/*
** algo ps
*/

int		algo_ps(t_data *data);
int		sort_in_chunck(t_data *data);
void	send_to_chunck(t_data *data, int i, int bool);
int		sort_b(t_data *data);
int		find_max(t_data *data);
void	ft_push_b(t_data *data, int i, int bool);

/*
** tools.c
*/

int		check_digit(int argc, char **argv, int i);
int		parsing(t_data *data, int argc, char **argv, int j);
int		check_parsing(t_data *data, int argc, char **argv);
int		ft_parse_string(t_data *data, int argc, char **argv, int i);
void	ft_free_all(t_data *data);
void	ft_free_tab(char **tab);
void	init_struct(t_data *data);

/*
** Commande
*/

int		ss(t_data *data);
int		sa(t_data *data);
int		sb(t_data *data);
int		pa(t_data *data);
int		pb(t_data *data);
int		rr(t_data *data);
int		ra(t_data *data);
int		rb(t_data *data);
int		rrr(t_data *data);
int		rra(t_data *data);
int		rrb(t_data *data);

/*
** **********************Checker*********************************************
*/

int		ft_small_batch(t_data *data);
int		ft_batch_4(t_data *data);
int		ft_bath_3(t_data *data);
int		ft_batch_2(t_data *data);

/*
** check_list.c
*/

int		check_order_stack(t_data *data);
int		quick_sort(t_data *data);
int		save_value_chunck(t_data *data, int *tmp);
void	ft_print_tab(int *tab, int len);
void	ft_print_stack(t_data *data, char *cmd);
void	ft_putnbr(int n);
void	ft_putchar(char c);
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_error(t_data *data);

#endif
