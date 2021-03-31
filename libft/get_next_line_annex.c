/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:14:50 by edessain          #+#    #+#             */
/*   Updated: 2021/03/31 12:18:08 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	ft_free_g(char **string, int nb)
{
	if (*string)
	{
		free(*string);
		*string = NULL;
	}
	return (nb);
}

char	*ft_strchr_g(const char *str, int c)
{
	int			i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i] + 1);
		i++;
	}
	if (c == 0)
		return ((char *)&str[i] + 1);
	return (NULL);
}

char	*ft_strndup_g(const char *str, const char c)
{
	int			i;
	int			j;
	char		*src;

	i = 0;
	j = 0;
	if (str == NULL)
		return (ft_strndup_g("", '\0'));
	while (str[j] != c)
		j++;
	src = malloc((j + 1) * sizeof(*src));
	if (src == NULL)
		return (NULL);
	while (str[i] != '\0' && str[i] != c)
	{
		src[i] = str[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}
