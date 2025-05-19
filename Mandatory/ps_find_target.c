/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_target.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:03:45 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/06 18:54:11 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	oc_push_target(t_head *stacks, int chank, int range)
{
	int	border;
	int	cmd;

	if (stacks == NULL)
		return ;
	border = 0;
	cmd = 0;
	stacks->flag = 0;
	border = chank - (range - range / 2);
	if (stacks->top_a->rank <= border)
		stacks->flag = 1;
	ps_push_target(stacks);
	if (stacks->flag == 1)
	{
		cmd = rotate_b(stacks);
		ps_select_print(cmd);
	}
	return ;
}

void	ps_push_target(t_head *stacks)
{
	int	cmd;

	if (stacks == NULL)
		return ;
	cmd = 0;
	cmd = push_b(stacks);
	ps_select_print(cmd);
	return ;
}

int	oc_count_operate(t_head *stacks, t_node *current, int move, int border)
{
	t_node	*reverse;
	int		operate;

	if (stacks == NULL || current == NULL)
		return (0);
	reverse = stacks->top_a;
	operate = 0;
	while (reverse != current)
	{
		reverse = reverse->prev;
		operate++;
	}
	if (move < operate)
		operate = move;
	if (current->rank <= border)
		operate++;
	return (operate);
}

int	oc_compare_operate(t_head *stacks, int target, int operate, int rank)
{
	if (stacks == NULL)
		return (0);
	if (target > operate)
	{
		stacks->target = rank;
		target = operate;
	}
	return (target);
}

int	oc_find_target(t_head *stacks, int chank, int listsize, int range)
{
	t_node	*current;
	int		operate;
	int		move;
	int		target;
	int		border;

	if (stacks == NULL || listsize == 1)
		return (0);
	move = 0;
	target = INT_MAX;
	current = stacks->top_a;
	while (move < listsize)
	{
		if (current->rank <= chank)
		{
			stacks->flag = 1;
			operate = 0;
			border = chank - (range - range / 2);
			operate = oc_count_operate(stacks, current, move, border);
			target = oc_compare_operate(stacks, target, operate, current->rank);
		}
		current = current->next;
		move++;
	}
	return (stacks->flag);
}
