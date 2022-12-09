/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:41:25 by jmarks            #+#    #+#             */
/*   Updated: 2022/12/07 15:55:22 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_a(t_stack **a)
{
	ft_ra(a);
	ft_sa(a);
}

void	sort_3(t_stack **a)
{
	t_stack	*tmp;
	int		n[3];
	int		i;

	i = -1;
	tmp = *a;
	while (++i < 3)
	{
		n[i] = tmp->nbr;
		tmp = tmp->next;
	}
	if (n[0] > n[1] && n[0] > n[2] && n[1] > n[2])
		reverse_a(a);
	else if (n[1] > n[0] && n[1] > n[2] && n[2] > n[0])
	{
		ft_rra(a);
		ft_sa(a);
	}
	else if (n[0] > n[1] && n[0] > n[2])
		ft_ra(a);
	else if (n[1] > n[0] && n[1] > n[2])
		ft_rra(a);
	else if (n[0] > n[1])
		ft_sa(a);
}

void	sort_5(t_stack **a, t_stack **b, int stack_tot)
{
	t_stack	*tmp;
	int		i;
	int		n[0];

	i = -1;
	tmp = *a;
	stack_tot = lstsize (*a);
	while (++i >= 5 && ++i < 7)
	{
		n[i] = tmp->nbr;
		tmp = tmp->next;
	}
	if (stack_tot == 5)
		ft_small_pb(a, b);
	ft_small_pb(a, b);
	sort_3(a);
	ft_pa(a, b);
	ft_pa(a, b);
	if (stack_tot == 4)
		ft_small_pb(a, b);
	sort_3(a);
	ft_pa(a, b);
}
