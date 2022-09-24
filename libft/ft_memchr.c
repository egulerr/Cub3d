/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:01:51 by eguler            #+#    #+#             */
/*   Updated: 2022/01/18 19:52:17 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char) c)
			return (&p[i]);
		i++;
	}
	return (NULL);
}
/*
int main()
{
	char s[] = "ayapgulrm";
	printf("%s\n",ft_memchr(s ,'r', 8));
	printf("%s",memchr(s, 'r', 8));
}
*/
