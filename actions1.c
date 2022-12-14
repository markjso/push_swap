/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:59:28 by jmarks            #+#    #+#             */
/*   Updated: 2022/12/05 09:59:47 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//swap the first two elements at the top of stack B
void	ft_sb(t_stack **b)
{
	swap(*b);
	ft_putstr("sb\n");
}

//shift all elements up by 1. The first element becomes the last
void	ft_rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if ((*b)->next == NULL)
		return ;
	last = *b;
	tmp = last;
	*b = (*b)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
	last->next = NULL;
	ft_putstr("rb\n");
}

/*reverse rotate - shift all elements down by 1. The last element
 * becomes the first*/
void	ft_rrb(t_stack **b)
{
	t_stack	*end;
	t_stack	*prev;
	t_stack	*tmp;

	end = get_stack_bottom(*b);
	prev = get_stack_before_bottom(*b);
	tmp = *b;
	*b = end;
	(*b)->next = tmp;
	prev->next = NULL;
	ft_putstr("rrb\n");
}

//take the first element of stack B and put it at the top of stack A
void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b)
	{
		tmp = (*b)->next;
		if (*a)
			(*b)->next = *a;
		else
			(*b)->next = NULL;
		*a = *b;
		*b = tmp;
		ft_putstr("pa\n");
	}
}
