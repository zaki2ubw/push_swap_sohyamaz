/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_optimization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:33:56 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/05 20:02:15 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_double_case(t_head *stacks)
{
	t_node	*top;
	t_node	*bottom;
	int		cmd;

	if (stacks == NULL)
		return ;
	cmd = 0;
	top = stacks->top_a;
	bottom = stacks->top_a->prev;
	if (top->rank > bottom->rank)
	{
		cmd = swap_a(stacks);
		ft_printf("sa\n");
	}
	return ;
}

void	op_triple_case(t_head *stacks)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	int		num;

	if (stacks == NULL)
		return ;
	num = 0;
	first = stacks->top_a;
	second = stacks->top_a->next;
	third = stacks->top_a->prev;
	if (first->rank < second->rank && second->rank < third->rank)
		return ;
	else if (first->rank < second->rank && first->rank < third->rank)
		num = 132;
	else if (first->rank > second->rank && first->rank < third->rank)
		num = 213;
	else if (first->rank < second->rank && first->rank > third->rank)
		num = 231;
	else if (first->rank > second->rank && second->rank < third->rank)
		num = 312;
	else if (first->rank > second->rank && second->rank > third->rank)
		num = 321;
	op_optimize_three(stacks, num);
	return ;
}

void	op_quadruple_case(t_head *stacks)
{
	t_node	*current;
	int		num;

	if (stacks == NULL)
		return ;
	current = stacks->top_a;
	if (current->rank < current->next->rank \
		&& current->next->rank < current->next->next->rank \
		&& current->next->next->rank < current->prev->rank)
		return ;
	stacks->flag = push_b(stacks);
	ft_printf("pb\n");
	op_triple_case(stacks);
	num = stacks->top_b->rank;
	num = op_set_quadnum(num, stacks);
	op_optimize_four(stacks, num);
	return ;
}

void	op_quintuple_case(t_head *stacks)
{
	t_node	*current;
	int		num;

	if (stacks == NULL)
		return ;
	current = stacks->top_a;
	if (current->rank == 1 && current->next->rank == 2 \
		&& current->prev->rank == 5 && current->prev->prev->rank == 4)
		return ;
	stacks->flag = push_b(stacks);
	ft_printf("pb\n");
	op_quadruple_case(stacks);
	current = stacks->top_a;
	num = stacks->top_b->rank;
	num = op_set_quintnum(num, stacks);
	op_optimize_five(stacks, num);
	return ;
}

void	ps_optimized_cmd(int argc, t_head *stacks)
{
	if (stacks == NULL)
		return ;
	else if (argc == 1)
		return ;
	else if (argc == 2)
		return ;
	else if (argc == 3)
		op_double_case(stacks);
	else if (argc == 4)
		op_triple_case(stacks);
	else if (argc == 5)
		op_quadruple_case(stacks);
	else if (argc == 6)
		op_quintuple_case(stacks);
	return ;
}
