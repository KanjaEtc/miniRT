/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:02:40 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/08 11:09:53 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*uc_s;

	uc_s = s;
	while (n--)
		*uc_s++ = 0;
}
/*
int main()
{
	char s[10] = "hfurowe";
	size_t n = 5;
	ft_bzero(s, n);
	//bzero(s, n);
	for (int i = 0 ; i < 10 ; i++)
		printf("%d\n", s[i]);
}*/
