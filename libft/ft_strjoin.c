/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matda-co <matda-co@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:53:14 by matda-co          #+#    #+#             */
/*   Updated: 2024/10/28 14:21:20 by matda-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	int		i;
	char	*str;

	l = 0;
	if (!s1 || !s2)
		return (0);
	l = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	str = (char *)malloc(l * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i++] = *s1++;
	}
	while (*s2)
	{
		str[i++] = *s2++;
	}
	str[i] = '\0';
	return (str);
}
