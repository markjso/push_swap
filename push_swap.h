/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:26:00 by jmarks            #+#    #+#             */
/*   Updated: 2022/12/05 10:27:44 by jmarks           ###   ########.fr       */
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
	struct s_stack	*next;
}	t_stack;

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_error(char *str);
void	ft_free(t_stack **stack);
int		lstsize(t_stack *lst);
void	ft_sa(t_stack **a);
void	ft_ra(t_stack **a);
void	ft_rra(t_stack **a);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_sb(t_stack **b);
void	ft_rb(t_stack **b);
void	ft_rrb(t_stack **b);
void	sort(t_stack **a, t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
int		ft_min(t_stack *stack);
int		ft_max(t_stack *stack);
void	sort_3(t_stack **a);
void	sort_5(t_stack **a, t_stack **b, int argc);
int		sort_large(t_stack **a, t_stack **b, int i);
void 	check_stack(t_stack **a, int argc, char **argv);
int		check_if_sorted(t_stack *a);
int		ft_atoi(char *str);
int		ft_check(char *argv);
int 	smallest_index(t_stack **stack, int x);
void	ft_small_pb(t_stack **a, t_stack **b);
void	ft_large_pa(t_stack **a, t_stack **b);
void	push_all_but_3(t_stack **a, t_stack **b);
int		init_stack(t_stack **head, char **argv);
int		index_finder(t_stack *stack, int index, int x);
int		index_for_b(t_stack **a, t_stack **b);
int		stack_index(t_stack *stack, int max);
int		search_a(t_stack *a, int max);
void	before_pb(t_stack **a, t_stack **b);
void	choose_rotate_a(t_stack **a);
void	choose_rotate_b(t_stack **a);
int		push_all_from_b(t_stack **a, t_stack **b, int stack_tot);

#endif
