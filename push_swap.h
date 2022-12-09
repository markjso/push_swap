/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:26:00 by jmarks            #+#    #+#             */
/*   Updated: 2022/12/07 12:55:33 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/*checks*/
void	check_stack(t_stack **a, int argc, char **argv);
int		check_if_sorted(t_stack *a);

/*utils*/
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_error(char *str);
void	ft_free(t_stack **stack);
int		lstsize(t_stack *lst);
int		ft_atoi(char *str);

/*initialise*/
int		init_stack(t_stack **head, char **argv);
void	assign_index(t_stack *a, int argc);

/*actions*/
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*get_stack_before_bottom(t_stack *stack);
void	ft_sa(t_stack **a);
void	ft_ra(t_stack **a);
void	ft_rra(t_stack **a);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_sb(t_stack **b);
void	ft_rb(t_stack **b);
void	ft_rrb(t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);

/*sort*/
void	sort_3(t_stack **a);
void	sort_5(t_stack **a, t_stack **b, int argc);
void	sort(t_stack **a, t_stack **b);
void	push_all_but_3(t_stack **a, t_stack **b);
void	ft_small_pb(t_stack **a, t_stack **b);

/*postion*/
int		get_lowest_index_pos(t_stack **stack);
void	get_target_pos(t_stack **a, t_stack **b);

/*cost*/
void	get_the_cost(t_stack **a, t_stack **b);
void	do_cheapest_move(t_stack **a, t_stack **b);
void	push_all_from_b(t_stack **a, t_stack **b, int cost_a, int cost_b);

#endif
