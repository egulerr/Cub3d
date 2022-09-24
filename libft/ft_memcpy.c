/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:00:47 by eguler            #+#    #+#             */
/*   Updated: 2022/01/18 19:44:16 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	char	*kaynak;
	char	*hedef;
	size_t	i;

	kaynak = (char *)dst;
	hedef = (char *)src;
	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		kaynak[i] = hedef[i];
		i++;
	}
	return (kaynak);
}
/*
int main()
{
	char src[] = "aysee";
	char dst[] = "ald";

	printf("%s\n", ft_memcpy(dst, src, 3));
	printf("%s\n", memcpy(dst,src,3));
}
*/
