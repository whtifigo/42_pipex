/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matda-co <matda-co@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:29:31 by matda-co          #+#    #+#             */
/*   Updated: 2024/10/25 10:39:53 by matda-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*n_str;

	n_str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (n_str == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		n_str[i] = (*f)(i, s[i]);
		i++;
	}
	n_str[i] = 0;
	return (n_str);
}
