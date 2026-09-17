/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:10:25 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/10 06:44:47 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*uc_s;

	uc_s = s;
	while (n--)
		*uc_s++ = 0;
}*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb)
	{
		if (size > SIZE_MAX / nmemb)
			return (NULL);
	}
	if (size)
	{
		if (nmemb > SIZE_MAX / size)
			return (NULL);
	}
	result = malloc(size * nmemb);
	if (!result)
		return (NULL);
	ft_bzero(result, nmemb * size);
	return (result);
}
/*
int main()
{
	size_t nmemb = 5;
	size_t size = 3;
	void *ft_output = ft_calloc(nmemb, size);
	void *calloc_output = calloc(nmemb, size);
	if (ft_output)
	{
		for (size_t i = 0 ; i < nmemb ; i++)
			printf("%d\n", ((unsigned char *)ft_output)[i]);
	}
	else
		printf("null");
	if (calloc_output)
	{
		for (size_t i = 0 ; i < nmemb ; i++)
			printf("%d\n", ((unsigned char *)calloc_output)[i]);
	}
	else
		printf("null");
	free(ft_output);
	free(calloc_output);
}*/
