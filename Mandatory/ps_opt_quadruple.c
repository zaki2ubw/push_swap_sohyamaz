/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opt_quadruple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:51:44 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/05 20:00:57 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_print_quadruple(int num)
{
	if (num == 41)
		ft_printf("pa\n");
	else if (num == 42)
		ft_printf("pa\nsa\n");
	else if (num == 43)
		ft_printf("rra\npa\nra\nra\n");
	else if (num == 44)
		ft_printf("pa\nra\n");
	return ;
}

void	op_optimize_four(t_head *stacks, int num)
{
	if (stacks == NULL)
		return ;
	if (num == 41)
		stacks->flag = push_a(stacks);
	else if (num == 42)
	{
		stacks->flag = push_a(stacks);
		stacks->flag = swap_a(stacks);
	}
	else if (num == 43)
	{
		stacks->flag = reverse_rotate_a(stacks);
		stacks->flag = push_a(stacks);
		stacks->flag = rotate_a(stacks);
		stacks->flag = rotate_a(stacks);
	}
	else if (num == 44)
	{
		stacks->flag = push_a(stacks);
		stacks->flag = rotate_a(stacks);
	}
	op_print_quadruple(num);
	return ;
}

int	op_set_quadnum(int num, t_head *stacks)
{
	t_node	*current;

	if (stacks == NULL)
		return (0);
	current = stacks->top_a;
	if (num < current->rank)
		num = 41;
	else if (num < current->next->rank)
		num = 42;
	else if (num < current->prev->rank)
		num = 43;
	else
		num = 44;
	return (num);
}
