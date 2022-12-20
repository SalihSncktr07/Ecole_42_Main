/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:47:06 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/19 13:56:06 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// lst structının bağlı olduğu listelerin başına ekler
// lst structı ve new structı listenin başlangıcını işaret eder.
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/* #include <stdio.h>

int main(void)
{
	t_list *node1;
	t_list *node2;

node1 = ft_lstnew("42");
node2 = ft_lstnew(" Kocaeli");	

ft_lstadd_front(&node2, node1);	

	printf("%s",(char *)node1->content);
	printf("%s",(char *)node1->next->content);
	return (0);
} */