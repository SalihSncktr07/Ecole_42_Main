/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:56:43 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/19 14:03:12 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Bağlı listenin uzunluğunu döndürür.
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

/* #include <stdio.h>

int main()
{
	t_list *node1,*node2,*node3, *node4;

	node1 = (t_list *)malloc(sizeof(t_list));
	node2 = (t_list *)malloc(sizeof(t_list));
	node3 = (t_list *)malloc(sizeof(t_list));
    node4 = (t_list *)malloc(sizeof(t_list));
    
	node1->next = node2;
	node2->next = node3;
    node3->next = node4;
	node4->next = NULL;
	printf("%d",ft_lstsize(node1));
} */