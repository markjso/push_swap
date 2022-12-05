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
void	ft_sa(t_stack **a)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	(*a)->next = tmp;
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

/*reverse rotate - shift all elements down by 1. The last element
 * becomes the first*/
void	ft_rra(t_stack **a)
{
	t_stack	*curr;
	t_stack	*prev;

	curr = *a;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	curr->next = *a;
	prev->next = NULL;
	*a = curr;
	ft_putstr("rra\n");
}

//take the first element of stack A and put it at the top of stack B
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
