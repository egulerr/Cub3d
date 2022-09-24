/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:57:31 by eguler            #+#    #+#             */
/*   Updated: 2022/01/18 18:11:03 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			f(i, s + i);
			i++;
		}
	}
}
/*
void	f(unsigned int a, char *b)
{
	int alpha;
	alpha = a;
	int i;
	i = 0;
	while (b[i] != '\0')
	{
		b[i] = b[i] + 1;
		i++;
	}
}

int main()
{
	char arr[] = "eyup";
	ft_striteri(arr, f);
	printf("%s", arr);
}
*/
