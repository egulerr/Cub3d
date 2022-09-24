/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:56:27 by eguler            #+#    #+#             */
/*   Updated: 2022/01/18 19:50:45 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n - 1)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int main()
{
	char	s1[] = "eyupsalih";
	char	s2[] = "eyupsaliH";

	printf("%d\n", ft_strncmp(s1, s2, 9));
	printf("%d", strncmp(s1, s2, 9));
}
*/
