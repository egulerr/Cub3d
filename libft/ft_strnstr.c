/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:55:45 by eguler            #+#    #+#             */
/*   Updated: 2022/01/19 12:14:16 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && i + j < len)
		{
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char haystack[] = "Salih burak coskun";
	char needle[] = "h";
	printf("%s\n", ft_strnstr(haystack, needle, 5));
	printf("%s", strnstr(haystack, needle, 5));
}
*/
