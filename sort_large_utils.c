/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:26:46 by jmarks            #+#    #+#             */
/*   Updated: 2022/12/05 11:33:56 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_index(t_stack *stack, int max)
{
	int	index;
	int	i;

	index = 0;
	i = -1;
	while (stack)
	{
		++i;
		if (stack->nbr <= max)
		{
			return (i);
		}
		stack = stack->next;
	}
	return (i);
}

static int	rb_stack(t_stack **a, t_stack **b, int index, int i)
{
	while (index > 0)
	{
		ft_rb(b);
		index--;
		i++;
	}
	if (index == 0)
	{
		ft_pa(a, b);
		i++;
	}
	return (i);
}

static int	rrb_stack(t_stack **a, t_stack **b, int index, int stack_tot)
{
	int	i;
	int	max;

	max = ft_max(*b);
	i = 0;
	while (stack_tot > index)
	{
		ft_rrb(b);
		index++;
		i++;
	}
	if ((*b)->nbr == max)
	{
		ft_pa(a, b);
	}
	return (i);
}

int	push_all_from_b(t_stack **a, t_stack **b, int stack_tot)
{
	int	i;
	int	half;
	int	index;
	int	max;

	i = 0;
	while (*b)
	{
		stack_tot = lstsize(*b);
		half = stack_tot / 2;
		index = 0;
		max = ft_max(*b);
		index = index_finder(*b, index, max);
		if (index <= half)
			i += rb_stack(a, b, index, i);
		if (index > half)
			i += rrb_stack(a, b, index, stack_tot);
	}
	return (i);
}
