/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:36:28 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/08 11:29:46 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

int	ft_isprint(int c)
{
	return (c >= 32 && c < 127);
}
/*
int main()
{
	int c = 127;
	if (ft_isprint(c))
		printf("c'est un caractere imprimable\n");
	else
		printf("ce n'est pas un caractere imprimable\n");
}*/
