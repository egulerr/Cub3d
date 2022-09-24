/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:57:20 by eguler            #+#    #+#             */
/*   Updated: 2022/01/18 19:46:16 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	i = ft_strlen(dst);
	k = 0;
	while (src[k] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[k];
		k++;
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[k]));
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char dst[] = "eyup";
	char src[] = "guler";

	printf("%lu", ft_strlcat(dst, src, 4));
	printf("%s", dst);
	//printf("%lu", strlcat(dst,src,5));
	//printf("%s",dst);
}
*/
