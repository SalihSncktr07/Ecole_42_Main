/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:13:21 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/19 13:45:43 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* fonksiyona girilen parametre struct yapısının içeriğine eklenir.
bir sonraki bağlı liste olmadığı için struct yapısının
next pointerına NULL atanır.
yeni oluşturulan struct return edilir. */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/* #include <stdio.h>
int main()
{
    printf("%s",(char *)ft_lstnew("salih")->content);
}
 */