/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:47:54 by jmarks            #+#    #+#             */
/*   Updated: 2022/11/21 17:33:42 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*
int	get_b_min_or_max(t_stack **a, t_stack **b, int index)
{
	long	b_max;
	long	b_min;
	int		b_min_index;
	int		i;

	i = 0;
	b_max = ft_max(*b);
	b_min = ft_min(*b);
	b_min_index = index_finder(*b, index, b_min);
	if ((*a)->nbr < b_min || (*a)->nbr > b_max)
	{
		i += choose_rotate_b(b, b_min_index);
		ft_pb(a, b);
		i += 1;
	}
	return (i);
}
*/
void	push_all_but_3(t_stack **a, t_stack **b)
{
	int	stack_tot;
	int	small;
	int	i;

	stack_tot = lstsize(*a);
	small = 0;
	i = 0;
	while (stack_tot > 6 && i < stack_tot && small < stack_tot / 2)
	{
		if ((*a)->nbr <= stack_tot / 2)
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

void	sort(t_stack **a, t_stack **b)
{
	push_all_but_3(a, b);
	sort_3(a);
	while (*b)
	{
		before_pb(a, b);
	}
	//if (!check_if_sorted(*a))
	//choose_rotate_a(a);

}/*
int	sort_chunk(t_stack **a, t_stack **b, int index, int chunk)
{
	int stack_tot;
	int	max;
	int	i;

	stack_tot = lstsize(*a);
	max = stack_tot / 5;
	i = 0;
	while (search_a(*a, chunk) == 1)
	{
		index = stack_index(*a, max);
		if ((*a) && !((*a)->nbr <= chunk))
		ft_small_pb(a, b);
		if ((*a) && (*a)->nbr <= chunk)
		{
			ft_pb(a, b);
			i++;
		}
		if (lstsize(*b) > 1 && (*a) && (*a)->nbr <= chunk)
		i += before_pb(a, b);
	}
	return (i);
}

int	sort_large(t_stack **a, t_stack **b, int i)
{	
	int	max;
	int	stack_tot;
	int	j;
	int	chunk;
	int	index;

	j = 0;
	stack_tot = lstsize(*a);
	while (*a)
	{
		++j;
		max = stack_tot / 5;
		chunk = max * j;
		index = stack_index(*a, max); // find the index of the lowest nbr in the chunk
		if (search_a(*a, chunk) == 1)
		i += sort_chunk(a, b, index, chunk);
	}
	if (!*a)
	i += push_all_from_b(a, b, stack_tot);
	if (check_if_sorted(*a) == 1)
	{
		ft_putstr("the list is not sorted\n");
	}
	return (i);
}
*/