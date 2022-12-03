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
	choose_rotate_b(b);
	ft_pa(a, b);
}

void	choose_rotate_b(t_stack **b)
{
	int	index_small;
	int	stack_tot;

	index_small = smallest_index(b, 214767348);
	stack_tot = lstsize(*b);
	if (index_small < stack_tot / 2)
	{
		while (index_small && *b)
		{
			ft_rb(b);
			index_small--;
		}
	}
	else
		while (index_small < stack_tot && *b)
		{
			ft_rrb(b);
			index_small++;
		}
}
