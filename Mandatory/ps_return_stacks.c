/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_return_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:12:59 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/06 18:07:28 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rs_return_target(t_head *stacks)
{
	int	cmd;

	if (stacks == NULL)
		return ;
	cmd = 0;
	cmd = push_a(stacks);
	ps_select_print(cmd);
	return ;
}

void	rs_rotate_target(t_head *stacks, int move)
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
			cmd = reverse_rotate_b(stacks);
		else
			cmd = rotate_b(stacks);
		ps_select_print(cmd);
		count++;
	}
	return ;
}

int	rs_find_target(t_head *stacks)
{
	t_node	*current;
	int		move;
	int		listsize;

	if (stacks == NULL)
		return (0);
	move = 0;
	current = stacks->top_b;
	listsize = ut_count_nodes(stacks->top_b);
	move = ps_decide_direct(stacks, stacks->top_b);
	return (move);
}
