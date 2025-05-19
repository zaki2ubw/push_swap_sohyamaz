/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:32:01 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/06 19:08:38 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ut_count_nodes(t_node *top)
{
	int		count;
	t_node	*current;

	if (top == NULL)
		return (0);
	count = 1;
	current = top;
	if (current->prev == top && current->next == top)
		return (count);
	while (current->next != top)
	{
		current = current->next;
		count++;
	}
	return (count);
}

t_node	*ut_create_node(int target, char *str, int argc, char **argv)
{
	t_node	*ret;

	if (str == NULL || argv == NULL)
		return (NULL);
	ret = ut_calloc(1, sizeof(t_node));
	if (ret == NULL)
		return (NULL);
	ret->next = ret;
	ret->prev = ret;
	ret->val = ml_add_val(str);
	ret->rank = ml_set_rank(target, ret->val, argc, argv);
	if (ret->rank == 0)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

int	ut_issigned(char c)
{
	if (c == '-')
		return (1);
	return (0);
}

long	ut_atoi(char *str)
{
	int		i;
	int		flag;
	long	val;

	i = 0;
	flag = 0;
	val = 0;
	if (str == NULL)
		return (0);
	flag = ut_issigned(str[i]);
	if (flag == 1)
	{
		if (str[i] != '-')
			flag = 0;
		i++;
	}
	while (str[i] != '\0')
	{
		val = (val * 10) + (str[i] - '0');
		i++;
	}
	if (flag == 1)
		val = -val;
	return (val);
}
