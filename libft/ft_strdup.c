/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:58:06 by eguler            #+#    #+#             */
/*   Updated: 2022/01/18 20:16:57 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + 1;
	new = (char *)malloc(sizeof(char) * len);
	if (!new)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*
int main()
{
	char *p = "e124246";

	printf("%s\n", ft_strdup(p));
	printf("%s", strdup(p));
}
*/
