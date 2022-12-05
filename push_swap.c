/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:33:56 by jmarks            #+#    #+#             */
/*   Updated: 2022/12/05 11:01:50 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b, int argc)
{
	if (argc == 3)
	{
		if ((*a)->nbr > (*a)->next->nbr)
	ft_sa(a);
	}
	else if (argc == 4)
	sort_3(a);
	else if (argc > 4 && argc <= 6)
	sort_5(a, b, argc);
    else if (argc >=7)
    sort(a, b);
}

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	
	b = NULL;
	init_stack(&a, argv + 1);
	check_stack(&a, argc, argv);
	if (check_if_sorted(a))
		return (0);
	push_swap(&a, &b, argc);
	//ft_free(&a);
	//ft_free(&b);
	return (0);
}
