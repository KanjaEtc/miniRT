/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:35:04 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/08 11:16:43 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
int main()
{
	int c = '3';
	if (ft_isdigit(c))
		printf("c'est un chiffre\n");
	else
		printf("c'est un autre caractere\n");
}*/
