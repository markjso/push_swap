/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:34:23 by jmarks            #+#    #+#             */
/*   Updated: 2022/11/21 14:20:59 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//swap the first two elements at the top of stack B
void	ft_sb(t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	(*b)->next = tmp;
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
	t_stack	*curr;
	t_stack	*prev;

	curr = *b;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	curr->next = *b;
	prev->next = NULL;
	*b = curr;
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
