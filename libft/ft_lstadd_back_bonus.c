/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:12:41 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/08 15:36:54 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

/*int main()
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
    node0->next = node1;
    node1->next = NULL;
	node2->next = NULL;

	ft_lstadd_back(&node0, node2);

	t_list *tmp = node0;
	while (tmp)
	{
		printf("%d\n", *((int *)tmp->content));
		tmp = tmp->next;
	}
	free(node0->content);
	free(node0);
	free(node1->content);
	free(node1);
	free(node2->content);
	free(node2);
}*/
