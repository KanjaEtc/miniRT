/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:32:11 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/08 17:07:32 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	del(void *content)
{
	free(content);
}

void	*f(void *content)
{
	int	*new_content;

	new_content = malloc(sizeof(int));
	if (!new_content)
		return (NULL);
	*new_content = *(int *)content *= 2;
	return (new_content);
}*/

/*void	ft_lstadd_back(t_list **lst, t_list *new);*/

/*void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		new->next = *lst;
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			if (new_content)
				del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
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
    node1->next = node2;
    node2->next = NULL;

	t_list *output = ft_lstmap(node0, &f, &del);
	t_list *tmp = output;
	while (tmp)
	{
		printf("%d\n", *((int *)tmp->content));
		tmp = tmp->next;
	}
	while (output)
	{
		tmp = output->next;
		free(output->content);
		free(output);
		output = tmp;
	}
	free(node2->content);
	free(node2);
	free(node1->content);
	free(node1);
	free(node0->content);
	free(node0);
	free(output);
}*/
