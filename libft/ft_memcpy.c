/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matda-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:12:37 by matda-co          #+#    #+#             */
/*   Updated: 2024/10/22 17:36:20 by matda-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ds;
	const unsigned char	*ss;

	ds = (unsigned char *) dest;
	ss = (const unsigned char *) src;
	if (!dest && !src)
		return (0);
	while (n--)
	{
		*(ds++) = *(ss++);
	}
	return (dest);
}
