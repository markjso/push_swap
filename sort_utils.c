/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:29:48 by jmarks            #+#    #+#             */
/*   Updated: 2022/11/21 15:45:27 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_index(t_stack **stack, int x)
{
	t_stack	*tmp;
	int		min;
	int		i;

	tmp = *stack;
	min = -1;
	i = 0;
	while (tmp)
	{
		if (tmp->nbr < x)
		{
			x = tmp->nbr;
			min = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min);
}

void	ft_small_pb(t_stack **a, t_stack **b)
{
	int	index_small;
	int	stack_tot;

	index_small = smallest_index(a, 214767348);
	stack_tot = lstsize(*a);
	if (index_small == 1)
	{
		ft_sa(a);
		ft_pb(a, b);
	}
	if (index_small < stack_tot / 2)
	{
		while (index_small && *a)
		{
			ft_ra(a);
			index_small--;
		}
	}
	else
		while (index_small < stack_tot && *a)
		{
			ft_rra(a);
			index_small++;
		}
		ft_pb(a, b);
}

int	ft_min(t_stack *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (stack->nbr < i)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}

int	ft_max(t_stack *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (stack->nbr > i)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}
