/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:50:53 by eguler            #+#    #+#             */
/*   Updated: 2022/01/18 17:23:32 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	int		j;
	size_t	s1_len;
	char	*dest;

	if (s1)
	{
		s1_len = ft_strlen(s1);
		i = 0;
		while (s1[i] != '\0' && ft_strchr(set, s1[i]))
			i++;
		while (s1_len > i && ft_strchr(set, s1[s1_len - 1]))
			s1_len--;
		dest = (char *)malloc(sizeof(char) * (s1_len - i + 1));
		if (!dest)
			return (NULL);
		j = 0;
		while (i < s1_len)
			dest[j++] = s1[i++];
		dest[j] = '\0';
		return (dest);
	}
	return (0);
}
/*
int main()
{
	char *s1 = "eyupguler";
	char *set = "ey";
	printf("%s", ft_strtrim(s1, set));
}
*/
