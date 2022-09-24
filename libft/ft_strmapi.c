/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:39:26 by eguler            #+#    #+#             */
/*   Updated: 2022/01/18 19:14:55 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*dest;

	if (s)
	{
		len = ft_strlen(s);
		dest = (char *)malloc(sizeof(char) * (len + 1));
		if (!dest)
			return (NULL);
		i = 0;
		while (i < len)
		{
			dest[i] = f(i, s[i]);
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (0);
}
/*
char	f(unsigned int a, char b)
{
	unsigned int alpha;
	alpha = a;
	return (b - 32);
}

int main()
{
	char *arr = "eyupguler";
	printf("%s", ft_strmapi(arr, f));
}
*/
