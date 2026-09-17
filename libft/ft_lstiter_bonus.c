/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:28:55 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/08 15:54:23 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	f(void *content)
{
	*(int *)content *= 3;
}*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
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
    node0->next = node1;
    node1->next = node2;
	node2->next = NULL;

	ft_lstiter(node0, &f);
	
	t_list *tmp = malloc(sizeof(t_list));
	tmp = node0;
	while (tmp)
	{
		printf("%d\n", *((int *)tmp->content));
		tmp = tmp->next;
	}
}*/
