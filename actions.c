/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:34:23 by jmarks            #+#    #+#             */
/*   Updated: 2022/12/05 09:58:54 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap the first two elements at the of stack A

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->nbr;
	stack->nbr = stack->next->nbr;
	stack->next->nbr = tmp;
}

void	ft_sa(t_stack **a)
{
	swap(*a);
	ft_putstr("sa\n");
}

//shift all elements up by 1. The first element becomes the last
void	ft_ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if ((*a)->next == NULL)
		return ;
	last = *a;
	tmp = last;
	*a = (*a)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
	last->next = NULL;
	ft_putstr("ra\n");
}

//reverse rotate - shift all elements down by 1. The last element becomes the first
void	ft_rra(t_stack **a)
{
	t_stack	*end;
	t_stack	*prev;
	t_stack	*tmp;

	end = get_stack_bottom(*a);
	prev = get_stack_before_bottom(*a);
	tmp = *a;
	*a = end;
	(*a)->next = tmp;
	prev->next = NULL;
	ft_putstr("rra\n");
}
/*
take the first element of stack A and put it at the top of stack B
void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a)
	{
		tmp = (*a)->next;
		if (b)
			(*a)->next = *b;
		else
			(*a)->next = NULL;
		*b = *a;
		*a = tmp;
		ft_putstr("pb\n");
	}
}
*/

static void push(t_stack **src, t_stack **dst)
{
	t_stack *tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}