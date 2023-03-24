#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int i = 0;
	while(begin_list != NULL)
	{
		begin_list = begin_list -> next;
		i++;
	}
	return (i);
}

// #include "ft_list.h"

// int	ft_list_size(t_list *begin_list)
// {
// 	if (begin_list == 0)
// 		return (0);
// 	else
// 		return (1 + ft_list_size(begin_list->next));
}
