/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:05:41 by eguler            #+#    #+#             */
/*   Updated: 2022/01/17 11:14:36 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;
	size_t	i;

	p = (char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
/*
int main()
{
	int a;
	char arr[] = "eyuasdp";

	a = 0;
	ft_bzero(arr, 3);
	while (a < 7)
	{
		write(1, &arr[a], 1);
		a++;
	}
}
*/
