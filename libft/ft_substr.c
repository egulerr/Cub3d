/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:53:54 by eguler            #+#    #+#             */
/*   Updated: 2022/01/18 17:14:08 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;
	size_t	end;

	if (s)
	{
		end = 0;
		size = ft_strlen(s);
		if (start < size)
			end = size - start;
		if (end > len)
			end = len;
		str = (char *)malloc(sizeof(char) * end + 1);
		if (!str)
			return (NULL);
		i = 0;
		while (i < end)
			str[i++] = s[start++];
		str[i] = '\0';
		return (str);
	}
	return (0);
}
/*
int main()
{
	char arr[] = "eyupgulercan";
	printf("%zu\n", ft_strlen(arr));
	printf("%s\n",ft_substr(arr, 2, 5 ));
	printf("%zu",ft_strlen((const char *)(ft_substr(arr, 2, 10 ))));
}
*/
