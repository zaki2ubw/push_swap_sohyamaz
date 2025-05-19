/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opt_triple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:09:04 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/06 18:57:29 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_print_triple(int num)
{
	if (num == 132)
		ft_printf("sa\nra\n");
	else if (num == 213)
		ft_printf("sa\n");
	else if (num == 231)
		ft_printf("rra\n");
	else if (num == 312)
		ft_printf("ra\n");
	else if (num == 321)
		ft_printf("sa\nrra\n");
	return ;
}

void	op_optimize_three(t_head *stacks, int num)
{
	int	cmd;

	if (stacks == NULL)
		return ;
	cmd = 0;
	if (num == 132)
	{
		stacks->flag = swap_a(stacks);
		stacks->flag = rotate_a(stacks);
	}
	else if (num == 213)
		stacks->flag = swap_a(stacks);
	else if (num == 231)
		stacks->flag = reverse_rotate_a(stacks);
	else if (num == 312)
		stacks->flag = rotate_a(stacks);
	else if (num == 321)
	{
		stacks->flag = swap_a(stacks);
		stacks->flag = reverse_rotate_a(stacks);
	}
	op_print_triple(num);
	return ;
}
