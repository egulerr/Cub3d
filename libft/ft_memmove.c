/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:00:19 by eguler            #+#    #+#             */
/*   Updated: 2022/01/18 19:44:41 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	int	i;

	i = 0;
	if (!dest && !src)
		return (0);
	if ((size_t) dest - (size_t) src < len)
	{
		i = len - 1;
		while (i >= 0)
		{
			((char *)dest)[i] = ((const char *)src)[i];
			i--;
		}
	}
	else
	{
		while ((size_t)i < len)
		{
			((char *) dest)[i] = ((const char *) src)[i];
			i++;
		}
	}
	return (dest);
}
/*
int main()
{
	char dest[] = "heloiooo";
	char src[] = "eyu";
	ft_memmove(dest,src,3);
	printf("%s",dest);
	printf("\n");
	memmove(dest,src,3);
	printf("%s",dest);
}
*/
