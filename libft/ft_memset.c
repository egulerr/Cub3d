/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:58:49 by eguler            #+#    #+#             */
/*   Updated: 2022/01/17 11:08:27 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*p;

	p = (char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = c;
		i++;
	}
	return (p);
}
/*
#include <stdio.h>
int main()
{
	char arr[] = "eyupgulerke";
	printf("%s", ft_memset(arr, 'x', 3));
}
*/
