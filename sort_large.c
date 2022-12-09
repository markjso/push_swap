/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:47:54 by jmarks            #+#    #+#             */
/*   Updated: 2022/12/07 15:56:01 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_all_but_3(t_stack **a, t_stack **b)
{
	int	stack_tot;
	int	small;
	int	i;

	stack_tot = lstsize(*a);
	small = 0;
	i = 0;
	while (stack_tot > 6 && i < stack_tot && small < (stack_tot / 2))
	{
		if ((*a)->index <= stack_tot / 2)
		{
			ft_pb(a, b);
			small++;
		}
		else
			ft_ra(a);
		i++;
	}
	while (stack_tot - small > 3)
	{
		ft_pb(a, b);
		small++;
	}
}

void	sort_stack(t_stack **a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = lstsize(*a);
	lowest_pos = get_lowest_index_pos(a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			ft_rra(a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ft_ra(a);
			lowest_pos--;
		}
	}
}

void	sort(t_stack **a, t_stack **b)
{
	int	stack_tot;

	stack_tot = lstsize(*a);
	push_all_but_3(a, b);
	sort_3(a);
	while (*b)
	{
		get_target_pos(a, b);
		get_the_cost(a, b);
		do_cheapest_move(a, b);
	}
	if (!check_if_sorted(*a))
		sort_stack(a);
}
