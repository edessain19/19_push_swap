#ifndef CHECKER_H
# define CHECKER_H

# include "../utils/libft/include/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_data
{
    char    *instruction;
    char    **tab_instr;
}                   t_data;

int     main(int argc, char **argv);
int     read_cmd(t_data *data);
int     apply_cmd(t_data *data);




#endif