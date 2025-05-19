/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_stracts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:17:24 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/07 19:46:07 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*is_add_firstnode(int argc, char **argv)
{
	t_node	*firstnode;

	if (argv == NULL)
		return (NULL);
	firstnode = ut_create_node(1, argv[1], argc, argv);
	if (firstnode == NULL)
		return (NULL);
	return (firstnode);
}

void	init_stracts(t_head *stacks, int argc, char **argv)
{
	if (stacks == NULL || argv == NULL)
		ut_error_exit();
	else if (argc == 2)
		exit(EXIT_SUCCESS);
	stacks->top_a = is_add_firstnode(argc, argv);
	if (stacks->top_a == NULL)
		ut_error_exit();
	stacks->top_b = NULL;
	stacks->target = 0;
	stacks->flag = 0;
	return ;
}
