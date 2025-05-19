/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cmd_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:07:54 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/06 19:40:45 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*cut_node(t_head *stacks, int cmd)
{
	t_node	*target;

	if (stacks == NULL)
		return (NULL);
	if (cmd == 10)
		target = stacks->top_b;
	else
		target = stacks->top_a;
	if (target->next == stacks->top_a)
		stacks->top_a = NULL;
	else if (target->next == stacks->top_b)
		stacks->top_b = NULL;
	else
	{
		target->next->prev = target->prev;
		target->prev->next = target->next;
		if (cmd == 10)
			stacks->top_b = stacks->top_b->next;
		else
			stacks->top_a = stacks->top_a->next;
	}
	return (target);
}

void	put_node_a(t_head *stacks, t_node *target)
{
	if (stacks == NULL)
		return ;
	if (stacks->top_a == NULL)
	{
		stacks->top_a = target;
		target->next = target;
		target->prev = target;
		return ;
	}
	target->next = stacks->top_a;
	target->prev = stacks->top_a->prev;
	stacks->top_a->prev->next = target;
	stacks->top_a->prev = target;
	stacks->top_a = target;
	return ;
}

void	put_node_b(t_head *stacks, t_node *target)
{
	if (stacks == NULL)
		return ;
	if (stacks->top_b == NULL)
	{
		stacks->top_b = target;
		target->next = target;
		target->prev = target;
		return ;
	}
	target->next = stacks->top_b;
	target->prev = stacks->top_b->prev;
	stacks->top_b->prev->next = target;
	stacks->top_b->prev = target;
	stacks->top_b = target;
	return ;
}

int	push_a(t_head *stacks)
{
	t_node	*target;
	int		cmd;

	if (stacks == NULL || stacks->top_b == NULL)
		return (0);
	cmd = 10;
	target = cut_node(stacks, cmd);
	put_node_a(stacks, target);
	return (cmd);
}

int	push_b(t_head *stacks)
{
	t_node	*target;
	int		cmd;

	if (stacks == NULL || stacks->top_a == NULL)
		return (0);
	cmd = 11;
	target = cut_node(stacks, cmd);
	put_node_b(stacks, target);
	return (cmd);
}
