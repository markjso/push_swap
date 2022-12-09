/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:34:23 by jmarks            #+#    #+#             */
/*   Updated: 2022/12/09 18:12:13 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp_value;
	int	tmp_index;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp_value = stack->nbr;
	tmp_index = stack->index;
	stack->nbr = stack->next->nbr;
	stack->index = stack->next->index;
	stack->next->nbr = tmp_value;
	stack->next->index = tmp_index;
}

//swap the first two elements at the of stack A
void	ft_sa(t_stack **a)
{
	swap(*a);
	ft_putstr("sa\n");
}

//swap the first two elements at the of stack B
void	ft_sb(t_stack **b)
{
	swap(*b);
	ft_putstr("sb\n");
}

//swap the first two elements at the of stack A & B at the same time
void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a);
	ft_sb(b);
	ft_putstr("ss\n");
}
