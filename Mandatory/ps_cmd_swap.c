/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cmd_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:35:56 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/06 18:36:50 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_head *stacks)
{
	t_node	*target;
	int		cmd;
	int		listsize;

	if (stacks == NULL)
		return (0);
	listsize = 0;
	listsize = ut_count_nodes(stacks->top_a);
	cmd = 100;
	if (listsize <= 1)
		return (0);
	target = stacks->top_a;
	target->next->prev = target->prev;
	target->prev->next = target->next;
	stacks->top_a = target->next;
	target->prev = stacks->top_a;
	target->next = stacks->top_a->next;
	stacks->top_a->next->prev = target;
	stacks->top_a->next = target;
	return (cmd);
}

int	swap_b(t_head *stacks)
{
	t_node	*target;
	int		cmd;
	int		listsize;

	if (stacks == NULL)
		return (0);
	listsize = 0;
	listsize = ut_count_nodes(stacks->top_b);
	cmd = 101;
	if (listsize <= 1)
		return (0);
	target = stacks->top_b;
	target->next->prev = target->prev;
	target->prev->next = target->next;
	stacks->top_b = target->next;
	target->prev = stacks->top_b;
	target->next = stacks->top_b->next;
	stacks->top_b->next->prev = target;
	stacks->top_b->next = target;
	return (cmd);
}
