/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:44:51 by jmarks            #+#    #+#             */
/*   Updated: 2022/12/07 12:07:29 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(t_stack **head, int x)
{
	t_stack	*ptr;
	t_stack	*tmp;

	ptr = NULL;
	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (ptr == NULL)
		return (NULL);
	ptr->nbr = x;
	ptr->next = NULL;
	if (*head == NULL)
		*head = ptr;
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ptr;
	}
	return (ptr);
}

int	init_stack(t_stack **head, char **argv)
{
	int		i;
	t_stack	*ptr;

	i = 0;
	while (argv[i])
	{
		ptr = new_node(head, ft_atoi(argv[i]));
		if (ptr == NULL)
		{
			i--;
			while (--i >= 0)
				free(ptr->next);
			ft_free(&ptr);
			ft_error("stack not initialised\n");
		}
		i++;
	}
	return (0);
}

void	assign_index(t_stack *a, int stack_tot)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		nbr;

	while (--stack_tot > 0)
	{
		ptr = a;
		nbr = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->nbr == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->nbr > nbr && ptr->index == 0)
			{
				nbr = ptr->nbr;
				highest = ptr;
				ptr = a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_tot;
	}
}
