/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:51:46 by eguler            #+#    #+#             */
/*   Updated: 2022/01/18 19:12:35 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
}
