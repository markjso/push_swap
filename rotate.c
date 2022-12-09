/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:59:28 by jmarks            #+#    #+#             */
/*   Updated: 2022/12/09 18:16:37 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//shift all elements up by 1. The first element becomes the last
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	ft_ra(t_stack **a)
{
	rotate(a);
	ft_putstr("ra\n");
}

void	ft_rb(t_stack **b)
{
	rotate(b);
	ft_putstr("rb\n");
}

void	ft_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n");
}
