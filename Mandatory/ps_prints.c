/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:16:49 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/06 18:44:00 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_print_special(int cmd)
{
	if (cmd == 201)
		ft_printf("ss\n");
	else if (cmd == 2001)
		ft_printf("rr\n");
	else if (cmd == 20001)
		ft_printf("rrr\n");
	return ;
}

void	ps_print_cmd(int cmd)
{
	if (cmd == 0)
		return ;
	else if (cmd == 10)
		ft_printf("pa\n");
	else if (cmd == 11)
		ft_printf("pb\n");
	else if (cmd == 100)
		ft_printf("sa\n");
	else if (cmd == 101)
		ft_printf("sb\n");
	else if (cmd == 1000)
		ft_printf("ra\n");
	else if (cmd == 1001)
		ft_printf("rb\n");
	else if (cmd == 10000)
		ft_printf("rra\n");
	else if (cmd == 10001)
		ft_printf("rrb\n");
	else
		ps_print_special(cmd);
	return ;
}

void	ps_select_print(int cmd)
{
	static int	last;
	static int	print;
	int			check;

	check = 0;
	check = print + last;
	if (check == 201 || check == 2001 || check == 20001)
	{
		ps_print_cmd(check);
		print = 0;
		last = cmd;
		return ;
	}
	ps_print_cmd(print);
	print = last;
	last = cmd;
	return ;
}
