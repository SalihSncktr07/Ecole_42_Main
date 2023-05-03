/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:15:42 by spirnaz           #+#    #+#             */
/*   Updated: 2023/05/03 14:15:43 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_ra(t_stacks *stack, int print)
{
	register int	tmp;
	register int	index;

	if (stack->size_a == 0 || stack->size_a == 1)
	{
		if (print == 1)
			ft_printf("Nothing done. Very few numbers in Stack A.\n");
		return ;
	}
	index = 0;
	tmp = stack->a[index];
	index++;
	while (index < stack->size_a)
	{
		stack->a[index - 1] = stack->a[index];
		index++;
	}
	stack->a[index - 1] = tmp;
	if (print == 0)
		ft_printf("ra\n");
}

void
	ft_rb(t_stacks *stack, int print)
{
	register int	tmp;
	register int	index;

	if (stack->size_b == 0 || stack->size_b == 1)
	{
		if (print == 1)
			ft_printf("Nothing done. Very few numbers in Stack B.\n");
		return ;
	}
	index = 0;
	tmp = stack->b[index];
	index++;
	while (index < stack->size_b)
	{
		stack->b[index - 1] = stack->b[index];
		index++;
	}
	stack->b[index - 1] = tmp;
	if (print == 0)
		ft_printf("rb\n");
}

void
	ft_rr(t_stacks *stack, int print)
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
	index = 0;
	tmp = stack->a[index];
	while (++index < stack->size_a)
		stack->a[index - 1] = stack->a[index];
	stack->a[index - 1] = tmp;
	index = 0;
	tmp = stack->b[index];
	while (++index < stack->size_b)
		stack->b[index - 1] = stack->b[index];
	stack->b[index - 1] = tmp;
	if (print == 0)
		ft_printf("rr\n");
}
