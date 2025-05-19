/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opt_quintuple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:32:17 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/06 19:51:32 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_print_quintuple(int num)
{
	if (num == 51)
		ft_printf("pa\n");
	else if (num == 52)
		ft_printf("pa\nsa\n");
	else if (num == 53)
		ft_printf("ra\npa\nsa\nrra\n");
	else if (num == 54)
		ft_printf("rra\npa\nra\nra\n");
	else if (num == 55)
		ft_printf("pa\nra\n");
	return ;
}

void	op_optimize_five(t_head *stacks, int num)
{
	if (num == 51 || num == 52 || num == 55)
	{
		stacks->flag = push_a(stacks);
		if (num == 52)
			stacks->flag = swap_a(stacks);
		else if (num == 55)
			stacks->flag = rotate_a(stacks);
	}
	else if (num == 53)
	{
		stacks->flag = rotate_a(stacks);
		stacks->flag = push_a(stacks);
		stacks->flag = swap_a(stacks);
		stacks->flag = reverse_rotate_a(stacks);
	}
	else if (num == 54)
	{
		stacks->flag = reverse_rotate_a(stacks);
		stacks->flag = push_a(stacks);
		stacks->flag = rotate_a(stacks);
		stacks->flag = rotate_a(stacks);
	}
	op_print_quintuple(num);
	return ;
}

int	op_set_quintnum(int num, t_head *stacks)
{
	t_node	*current;

	if (stacks == NULL)
		return (0);
	current = stacks->top_a;
	if (num < current->rank)
		num = 51;
	else if (num < current->next->rank)
		num = 52;
	else if (num < current->next->next->rank)
		num = 53;
	else if (num < current->prev->rank)
		num = 54;
	else
		num = 55;
	return (num);
}
