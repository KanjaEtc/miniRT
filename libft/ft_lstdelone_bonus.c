/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:20:24 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/10 08:38:42 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	del(void *content)
{
	free(content);
}*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*int main()
{
    int *content = malloc(sizeof(int));
	*content = 1;
    t_list *node = malloc(sizeof(t_list));
    node->content = content;
    node->next = NULL;
	
	ft_lstdelone(node, &del);
}*/
