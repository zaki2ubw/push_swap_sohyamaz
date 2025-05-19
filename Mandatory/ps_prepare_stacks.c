/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_prepare_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:27:01 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/06 19:08:01 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	oc_set_target(t_head *stacks, int move)
{
	int	count;
	int	cmd;

	if (stacks == NULL)
		return ;
	count = 0;
	cmd = 0;
	while (count < move)
	{
		if (stacks->flag == 1)
			cmd = reverse_rotate_a(stacks);
		else
			cmd = rotate_a(stacks);
		ps_select_print(cmd);
		count++;
	}
	return ;
}

int	oc_check_rotate(t_head *stacks, int listsize)
{
	int		move;

	if (stacks == NULL)
		return (0);
	move = 0;
	if (listsize == 1)
		return (move);
	stacks->flag = 0;
	move = ps_decide_direct(stacks, stacks->top_a);
	return (move);
}

int	ps_count_move(t_head *stacks, t_node *top, int direct)
{
	t_node	*current;
	int		move;

	if (stacks == NULL || top == NULL)
		return (0);
	current = top;
	move = 0;
	while (current->rank != stacks->target)
	{
		if (direct == 0)
			current = current->prev;
		else
			current = current->next;
		move++;
	}
	return (move);
}

int	ps_decide_direct(t_head *stacks, t_node *top)
{
	int	back;
	int	front;

	if (stacks == NULL || top == NULL)
		return (0);
	back = 0;
	front = 1;
	back = ps_count_move(stacks, top, back);
	front = ps_count_move(stacks, top, front);
	if (front > back)
	{
		stacks->flag = 1;
		return (back);
	}
	return (front);
}

void	ps_push_firstnode(t_head *stacks)
{
	int	listsize;
	int	cmd;

	if (stacks == NULL)
		return ;
	cmd = 0;
	listsize = 0;
	listsize = ut_count_nodes(stacks->top_a);
	ps_push_target(stacks);
	if (listsize > 2)
	{
		ps_push_target(stacks);
		if (stacks->top_b->rank < stacks->top_b->next->rank)
		{
			cmd = rotate_b(stacks);
			ps_select_print(cmd);
		}
	}
	return ;
}
