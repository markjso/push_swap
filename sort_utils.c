/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:29:48 by jmarks            #+#    #+#             */
/*   Updated: 2022/12/07 15:59:29 by jmarks           ###   ########.fr       */
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

	index_small = smallest_index(a, INT_MAX);
	stack_tot = lstsize(*a);
	if (index_small < stack_tot / 2)
	{
		while (index_small && *a)
		{
			ft_ra(a);
			index_small--;
		}
	}
	else
	{
		while (index_small < stack_tot && *a)
		{
			ft_rra(a);
			index_small++;
		}
	}
	ft_pb(a, b);
}

void	ft_free(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free (*stack);
		*stack = tmp;
	}
}
