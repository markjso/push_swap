/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:33:56 by jmarks            #+#    #+#             */
/*   Updated: 2022/12/07 11:43:40 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void print_list(t_stack *stack) {
    t_stack *current = stack;

    while (current != NULL) {
        printf("%d\n", current->nbr);
        current = current->next;
    }
}
*/
void	push_swap(t_stack **a, t_stack **b, int stack_tot)
{
	if (stack_tot == 2)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			ft_sa(a);
	}
	else if (stack_tot == 3)
		sort_3(a);
	else if (stack_tot == 4 || stack_tot == 5)
		sort_5(a, b, stack_tot);
	else if (stack_tot > 5)
		sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		stack_tot;

	init_stack(&a, argv + 1);
	stack_tot = lstsize(a);
	check_stack(&a, argc, argv);
	if (check_if_sorted(a))
		return (0);
	assign_index(a, stack_tot + 1);
	push_swap(&a, &b, stack_tot);
	ft_free(&a);
	return (0);
}
