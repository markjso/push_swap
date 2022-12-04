/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:25:03 by jmarks            #+#    #+#             */
/*   Updated: 2022/11/22 12:52:23 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_for_b(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*temp;
	int		index;

	i = 0;
	index = 0;
	temp = *b;
	if (a)
	{
		while (temp)
		{
			index++;
			if (temp->next != NULL)
			{
				if ((*a)->nbr > temp->nbr && (*a)->nbr < temp->next->nbr)
					return (index);
			}
			temp = temp->next;
		}
	}
	return (index);
}

void	before_pb(t_stack **a, t_stack **b)
{
	ft_large_pa(a, b);
	//ft_ra(a);
}

int	largest_index(t_stack **stack, int x)
{
	t_stack	*tmp;
	int		max;
	int		i;

	tmp = *stack;
	max = -1;
	i = 0;
	while (tmp)
	{
		if (tmp->nbr > x)
		{
			x = tmp->nbr;
			max = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max);
}
void	ft_large_pa(t_stack **a, t_stack **b)
{
	int	index_large;
	int	stack_tot;

	index_large = largest_index(b, INT_MIN);
	stack_tot = lstsize(*b);
	if (index_large < stack_tot / 2)
	{
		while (index_large && *b)
		{
			ft_rb(b);
			index_large--;
		}
	}
	else
		while (index_large < stack_tot && *b)
		{
			ft_rrb(b);
			index_large++;
		}
	ft_pa(a, b);
}
