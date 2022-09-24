/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:53:07 by eguler            #+#    #+#             */
/*   Updated: 2022/01/06 11:53:10 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c <= 122 && c >= 97)
		c -= 32;
	return (c);
}
/*
#include <stdio.h>
int main()
{
	int	alphabet;
	alphabet = 'k';
	printf("%c",ft_toupper(alphabet));
}
*/
