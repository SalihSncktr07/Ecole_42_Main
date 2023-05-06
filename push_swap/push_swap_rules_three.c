/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:15:39 by spirnaz           #+#    #+#             */
/*   Updated: 2023/05/03 14:15:40 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_rra(t_stacks *stack, int print)
{
	register int	tmp;
	register int	index;

	if (stack->size_a == 0 || stack->size_a == 1)
	{
		if (print == 1)
			ft_printf("Nothing done. Very few numbers in Stack A.\n");
		return ;
	}
	index = stack->size_a - 1;
	tmp = stack->a[index];
	while (index)
	{
		stack->a[index] = stack->a[index - 1];
		index--;
	}
	stack->a[index] = tmp;
	if (print == 0)
		ft_printf("rra\n");
}

void
	ft_rrb(t_stacks *stack, int print)
{
	register int	tmp;
	register int	index;

	if (stack->size_b == 0 || stack->size_b == 1)
	{
		if (print == 1)
			ft_printf("Nothing done. Very few numbers in Stack B.\n");
		return ;
	}
	index = stack->size_b - 1;
	tmp = stack->b[index];
	while (index)
	{
		stack->b[index] = stack->b[index - 1];
		index--;
	}
	stack->b[index] = tmp;
	if (print == 0)
		ft_printf("rrb\n");
}

void
	ft_rrr(t_stacks *stack, int print)
{
	register int	tmp;
	register int	index;

	if (stack->size_a == 0 || stack->size_a == 1
		|| (stack->size_b == 0 || stack->size_b == 1))
	{
		if (print == 1)
			ft_printf("Nothing done. Very few numbers in stacks.\n");
		return ;
	}
	index = stack->size_a - 1;
	tmp = stack->a[index];
	while (index)
	{
		stack->a[index] = stack->a[index - 1];
		index--;
	}
	stack->a[index] = tmp;
	index = stack->size_b - 1;
	tmp = stack->b[index];
	while (index--)
		stack->b[index] = stack->b[index - 1];
	stack->b[index] = tmp;
	if (print == 0)
		ft_printf("rrr\n");
}
