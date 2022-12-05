/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:44:51 by jmarks            #+#    #+#             */
/*   Updated: 2022/12/05 11:08:38 by jmarks           ###   ########.fr       */
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
			free(ptr);
			ft_error("stack not initialised\n");
		}
		i++;
	}
	return (0);
}

int	index_finder(t_stack *stack, int index, int x)
{
	int	i;

	i = -1;
	while (stack)
	{
		i++;
		if (x == stack->nbr)
			index = i;
		stack = stack->next;
	}
	return (index);
}
