#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


int     main(int argc, char **argv);


/*
** srcs
*/

char			*ft_itoa(int n);
char		*ft_strjoin(char const *s1, char const *s2);
char	    *ft_strdup(const char *s1);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
int		ft_isdigit(int c);



#endif