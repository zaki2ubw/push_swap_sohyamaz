/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:02:29 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/06 18:44:50 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ut_error_exit(void)
{
	ft_printf("ERROR\n");
	exit(EXIT_FAILURE);
}

void	fa_free_list(t_node *list)
{
	t_node	*target;

	if (list == NULL)
		return ;
	target = list;
	while ((target->next != NULL) && (target->next != list))
		target = target->next;
	while (target->prev != list)
	{
		target = target->prev;
		free(target->next);
	}
	target = target->prev;
	free(target->next);
	free(target);
}

void	ut_free_all(t_head *stacks)
{
	if (stacks == NULL)
		return ;
	if (stacks->top_a != NULL)
		fa_free_list(stacks->top_a);
	else if (stacks->top_b != NULL)
		fa_free_list(stacks->top_b);
	return ;
}
