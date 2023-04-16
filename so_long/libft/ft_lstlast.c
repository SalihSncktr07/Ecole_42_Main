/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:03:37 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/19 14:07:31 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// lst struct yapısının bağlı olduğu son struct yapısını döndürür.
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/* #include <stdio.h>

int main()
{
    t_list *node1,*node2,*node3;
	
    node1 = (t_list *)malloc(sizeof(t_list));
	node2 = (t_list *)malloc(sizeof(t_list));
	node3 = (t_list *)malloc(sizeof(t_list));
	
    node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	node3->content = "42 Kocaeli";
    
    printf("%s",(char *)ft_lstlast(node1)->content);
} */