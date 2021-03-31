/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 08:53:48 by edessain          #+#    #+#             */
/*   Updated: 2021/03/31 12:42:49 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define BUFFER_SIZE 32

void				ft_bzero(void *b, size_t len);
size_t				ft_strlen(const char *s);
int					ft_isdigit(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
long long			ft_atoi(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strjoin_2(char const *s1, char const *s2);
char				**ft_split(char const *str, char sep);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int nb, int fd);
int					get_next_line(int fd, char **line);
char				*ft_strndup_g(const char *str, const char c);

#endif
