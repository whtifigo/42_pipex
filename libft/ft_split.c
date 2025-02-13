/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matda-co <matda-co@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:40:20 by matda-co          #+#    #+#             */
/*   Updated: 2024/10/29 12:31:46 by matda-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordc(char const *s, char c)
{
	int	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

void	ft_free(char **r, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(r[i]);
		i++;
	}
	free(r);
}

static char	*ft_callword(char const **s, char c)
{
	char		*w;
	char const	*start;
	size_t		len;

	start = *s;
	len = 0;
	while (**s && **s != c)
	{
		(*s)++;
		len++;
	}
	w = ft_substr(start, 0, len);
	return (w);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	char		**r;

	r = (char **)malloc((ft_wordc(s, c) + 1) * sizeof(char *));
	i = 0;
	if (!s || !r)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			r[i] = ft_callword(&s, c);
			if (!r[i])
			{
				ft_free(r, i);
				return (NULL);
			}
			i++;
		}
	}
	r[i] = NULL;
	return (r);
}
