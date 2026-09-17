/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:37:56 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/08 15:59:31 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int main()
{
	int *content0 = malloc(sizeof(int));
    *content0 = 2;
    int *content1 = malloc(sizeof(int));
    *content1 = 3;
    int *content2 = malloc(sizeof(int));
    *content2 = 4;
    t_list *node0 = malloc(sizeof(t_list));
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    node0->content = content0;
    node1->content = content1;
    node2->content = content2;
	node0->next = NULL;
    node1->next = NULL;
    node2->next = NULL;
	t_list *head = NULL;

	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node0);

	t_list *tmp = head;
    while (tmp)
    {
        printf("%d\n", *((int *)tmp->content));
        tmp = tmp->next;
    }
	tmp = head;
	while (tmp)
{
    t_list *next = tmp->next;
    free(tmp->content);
    free(tmp);
    tmp = next;
}
	free(node2->content);
	free(node2);
	free(node1->content);
	free(node1);
	free(node0->content);
	free(node0);
}*/
