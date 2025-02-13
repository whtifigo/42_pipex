/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matda-co <matda-co@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:00:25 by matda-co          #+#    #+#             */
/*   Updated: 2024/10/25 13:26:19 by matda-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			r;

	i = 0;
	r = (char) c;
	while (s[i])
	{
		if (s[i] == r)
			return ((char *) s + i);
		i++;
	}
	if (r == '\0')
		return ((char *) s + i);
	if (s[i] == '\0')
		return (0);
	return ((char *) s);
}
