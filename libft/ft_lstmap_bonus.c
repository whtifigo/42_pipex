/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matda-co <matda-co@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:47:10 by matda-co          #+#    #+#             */
/*   Updated: 2024/11/06 14:47:15 by matda-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*obj;
	void	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		obj = ft_lstnew(tmp);
		if (!obj)
		{
			ft_lstclear(&newlst, del);
			del(tmp);
			return (NULL);
		}
		ft_lstadd_back(&newlst, obj);
		lst = lst->next;
	}
	return (newlst);
}
