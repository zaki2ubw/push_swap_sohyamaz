/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cmd_rotates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:00:31 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/06 18:40:13 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(t_head *stacks)
{
	int		cmd;
	t_node	*target;

	if (stacks == NULL)
		return (0);
	cmd = 1000;
	target = stacks->top_a;
	if (target->next == stacks->top_a)
		return (0);
	stacks->top_a = target->next;
	return (cmd);
}

int	rotate_b(t_head *stacks)
{
	int		cmd;
	t_node	*target;

	if (stacks == NULL)
		return (0);
	cmd = 1001;
	target = stacks->top_b;
	if (target->next == stacks->top_b)
		return (0);
	stacks->top_b = target->next;
	return (cmd);
}

int	reverse_rotate_a(t_head *stacks)
{
	int		cmd;
	t_node	*target;

	if (stacks == NULL)
		return (0);
	cmd = 10000;
	target = stacks->top_a;
	if (target->prev == stacks->top_a)
		return (0);
	stacks->top_a = target->prev;
	return (cmd);
}

int	reverse_rotate_b(t_head *stacks)
{
	int		cmd;
	t_node	*target;

	if (stacks == NULL)
		return (0);
	cmd = 10001;
	target = stacks->top_b;
	if (target->prev == stacks->top_a)
		return (0);
	stacks->top_b = target->prev;
	return (cmd);
}
