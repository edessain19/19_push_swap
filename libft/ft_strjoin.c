/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:12:32 by edessain          #+#    #+#             */
/*   Updated: 2021/03/31 14:06:42 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strjoin_2(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dest;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return ((char*)s2);
	dest = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (s1 && *s1)
		new[i++] = *s1++;
	while (s2 && *s2)
		new[i++] = *s2++;
	new[i] = '\0';
	return (new);
}
