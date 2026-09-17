/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:44:52 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/08 14:24:07 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int main()
{
	int value0 = 0;
    int value1 = 2;
    int value2 = 4;
    void *content0 = &value0;
    void *content1 = &value1;
    void *content2 = &value2;
    t_list *node0 = malloc(sizeof(t_list));
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    node0->content = content0;
    node1->content = content1;
    node2->content = content2;
    node0->next = node1;
    node1->next = node2;
    node2->next = NULL;

	t_list *last = ft_lstlast(node0);
	printf("%d\n", *(int *)(last->content));
	free(node0);
	free(node1);
	free(node2);
}*/
