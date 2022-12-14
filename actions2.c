/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:52:10 by jmarks            #+#    #+#             */
/*   Updated: 2022/12/05 10:52:14 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap the first two elements at the of stack A & B at the same time
void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a);
	ft_sb(b);
	ft_putstr("ss\n");
}

/*shift all elements up by 1 on both stacks. The first element 
 * becomes the last*/
void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a);
	ft_rb(b);
	ft_putstr("rr\n");
}

/*reverse rotate - shift all elements down by 1 on both stacks. 
 * The last element becomes the first*/
void	ft_rrr(t_stack **a, t_stack**b)
{
	ft_rra(a);
	ft_rrb(b);
	ft_putstr("rrr\n");
}

t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*get_stack_before_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
