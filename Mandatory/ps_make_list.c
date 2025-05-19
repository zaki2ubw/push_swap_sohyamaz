/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:25:54 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/07 19:41:45 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ml_add_val(char *origin)
{
	long	val;

	if (origin == NULL)
		return (0);
	val = 0;
	val = ut_atoi(origin);
	return (val);
}

int	ml_set_rank(int target, long val, int argc, char **argv)
{
	int		i;
	long	c;
	int		rank;

	if (argv == NULL)
		return (0);
	i = 1;
	c = 0;
	rank = 1;
	while (i < argc)
	{
		c = ut_atoi(argv[i]);
		if (i != target && val == c)
			return (0);
		else if (val > c)
			rank++;
		i++;
	}
	return (rank);
}

int	ml_add_node(t_head *stacks, int argc, char **argv)
{
	t_node	*current;
	int		count;

	count = 2;
	current = stacks->top_a;
	while (count < argc)
	{
		current->next = ut_create_node(count, argv[count], argc, argv);
		if (current->next == NULL)
		{
			ut_free_all(stacks);
			return (1);
		}
		current->next->prev = current;
		current = current->next;
		count++;
	}
	current->next = stacks->top_a;
	stacks->top_a->prev = current;
	return (0);
}

void	make_list(t_head *stacks, int argc, char **argv)
{
	int		check;

	if (stacks == NULL || argv == NULL)
		ut_error_exit();
	check = 0;
	check = ml_add_node(stacks, argc, argv);
	if (check == 1)
		ut_error_exit();
	if (argc <= 6)
	{
		ps_optimized_cmd(argc, stacks);
		ut_free_all(stacks);
		exit(EXIT_SUCCESS);
	}
	return ;
}
