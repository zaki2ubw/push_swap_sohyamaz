/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:01:21 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/06 18:54:34 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//debug_func
//void	ps_print_list(t_head *stacks)
//{
//	t_node	*current;
//	int		count;
//
//	if (stacks == NULL)
//		return ;
//	count = 0;
//	current = stacks->top_a;
//	ft_printf("%d:%d\n", current->rank, current->val);
//	current = current->next;
//	while (current != stacks->top_a)
//	{
//		ft_printf("%d:%d\n", current->rank, current->val);
//		current = current->next;
//		count++;
//	}
//	return ;
//}

int	oc_set_range(t_head *stacks)
{
	int	range;

	if (stacks == NULL)
		return (0);
	range = ut_count_nodes(stacks->top_a);
	if (range < 100)
		range = 20;
	else
		range = 40;
	return (range);
}

void	ps_operate_stack(t_head *stacks)
{
	int	chank;
	int	repeat;
	int	range;

	if (stacks == NULL)
		return ;
	chank = 1;
	repeat = 0;
	range = oc_set_range(stacks);
	while (stacks->top_a != NULL)
	{
		repeat = ps_operate_chank(stacks, chank, range);
		if (repeat == 0)
			chank++;
	}
	return ;
}

int	ps_operate_chank(t_head *stacks, int chank, int range)
{
	int		move;
	int		listsize;
	int		repeat;
	t_node	*current;

	if (stacks == NULL)
		return (INT_MIN);
	current = stacks->top_a;
	move = 0;
	listsize = 0;
	repeat = 0;
	listsize = ut_count_nodes(stacks->top_a);
	chank = chank * range;
	stacks->flag = 0;
	repeat = oc_find_target(stacks, chank, listsize, range);
	if ((repeat == 0) && listsize > 1)
		return (repeat);
	move = oc_check_rotate(stacks, listsize);
	oc_set_target(stacks, move);
	oc_push_target(stacks, chank, range);
	return (repeat);
}

void	ps_return_stack(t_head *stacks)
{
	int		cmd;
	int		move;

	if (stacks == NULL)
		return ;
	cmd = 0;
	move = 0;
	stacks->target = ut_count_nodes(stacks->top_b);
	while (stacks->top_b != NULL)
	{
		stacks->flag = 0;
		move = rs_find_target(stacks);
		rs_rotate_target(stacks, move);
		rs_return_target(stacks);
		--stacks->target;
	}
	rs_return_target(stacks);
	rs_return_target(stacks);
	return ;
}

void	push_swap(t_head *stacks)
{
	if (stacks == NULL)
		return ;
	ps_push_firstnode(stacks);
	ps_operate_stack(stacks);
	ps_return_stack(stacks);
	ut_free_all(stacks);
	return ;
}
