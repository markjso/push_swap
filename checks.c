/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:00:18 by jmarks            #+#    #+#             */
/*   Updated: 2022/12/05 10:20:41 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char *argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if ((argv[i] < '0' || argv[i] > '9') && argv[i] != '-'
			&& argv[i] != 32)
		{
			ft_error("some arguments are not integers\n");
		}
	}
	return (0);
}

int	check_dup_and_min_max(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->nbr > INT_MAX - 1 || tmp->nbr < INT_MIN + 1)
				ft_error("some arguments are bigger than an integer\n");
			else if (tmp->nbr == a->nbr)
				ft_error("there are duplicate arguments\n");
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

int	check_if_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	check_stack(t_stack **a, int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (argv[i] && i != 0)
	{
		check_int(argv[i]);
		i--;
	}
	check_dup_and_min_max(*a);
}
