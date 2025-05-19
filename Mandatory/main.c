/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:20:21 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/02 20:46:09 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_head	stacks;

	check_val(argc, argv);
	init_stracts(&stacks, argc, argv);
	make_list(&stacks, argc, argv);
	push_swap(&stacks);
	return (0);
}
