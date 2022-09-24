/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:58:16 by eguler            #+#    #+#             */
/*   Updated: 2022/01/18 19:48:10 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	p;

	i = 0;
	p = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == p)
			return ((char *)&s[i]);
		i++;
	}
	if (p == s[i])
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
/*
#include <stdio.h>
int main()
{
	char s[] = "salih burak";
	printf("%s", ft_strchr(s, 'b'));
}
*/
