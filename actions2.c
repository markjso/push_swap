/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:34:23 by jmarks            #+#    #+#             */
/*   Updated: 2022/11/15 15:10:26 by jmarks           ###   ########.fr       */
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
