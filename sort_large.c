/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:47:54 by jmarks            #+#    #+#             */
/*   Updated: 2022/12/05 13:36:43 by jmarks           ###   ########.fr       */
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
	int	stack_tot;
	
	stack_tot = lstsize(*b);
	push_all_but_3(a, b);
	printf("finished push all but 3\n");
	sort_3(a);
	printf("finished sort 3\n");
	while (*b)
	{
		before_pb(a, b);
		printf("finished before pb\n");
		push_all_from_b(a, b, stack_tot);
		printf("finished push all from b\n");
	}
	if (!check_if_sorted(*a))
	printf("stack a is not sorteda\n");
	choose_rotate_a(a);
}
