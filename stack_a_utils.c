/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:47:54 by jmarks            #+#    #+#             */
/*   Updated: 2022/11/22 12:24:26 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	search_a(t_stack *a, int max)
{
	while (a)
	{
		if (a->nbr <= max)
		return (1);
		a = a->next;
	}
	return (0);
}
/*
static int	ra_stack(t_stack **a, int index)
{
	int	i;
	int	stack_tot;

	i = index;
	stack_tot = lstsize(*a);
	while (index)
	{
		ft_ra(a);
		index--;
	}
	return (i);
}

static int	rra_stack(t_stack **a, int index)
{
	int	i;
	int	stack_tot;
	stack_tot = lstsize(*a);
	index = stack_tot - index;
	i = index;
	while (index)
	{
		ft_rra(a);
		index--;
	}
	return (i);
}
*/
void	choose_rotate_a(t_stack **a)
{
	int	index_small;
	int	stack_tot;

	index_small = smallest_index(a, 214767348);
	stack_tot = lstsize(*a);
	if (index_small < stack_tot / 2)
	{
		while (index_small && *a)
		{
			ft_ra(a);
			index_small--;
		}
	}
	else
		while (index_small < stack_tot && *a)
		{
			ft_rra(a);
			index_small++;
		}
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
		while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == '\r')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
			i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
			i++;
	}
	return (res * sign);
}