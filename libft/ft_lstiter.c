/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:00:04 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/19 15:02:47 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// struct bağlı listelerinin her bir elemanının 
// contentine parametredeki fonksiyonu uygular.
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/* #include <stdio.h>
void ft_change(void *content)
{
	((char *)content)[0] -= 32;
}
int main()
{
	  t_list *node1,*node2,*node3;
	  node1 = (t_list *)malloc(sizeof(t_list));
	  node2 = (t_list *)malloc(sizeof(t_list));
	  node3 = (t_list *)malloc(sizeof(t_list));
	  ft_lstadd_back(&node1,node2);
	  ft_lstadd_back(&node1,node3);
	  node1->content = ft_strdup("kocaeli");
	  node2->content = ft_strdup("kocaeli");
	  node3->content = ft_strdup("kocaeli");
	  ft_lstiter(node1,ft_change);
	  printf("%s\n",(char *)node1->content);
	  printf("%s\n",(char *)node1->next->content);
	  printf("%s\n",(char *)node1->next->next->content);
} */