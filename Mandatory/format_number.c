/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:55:55 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/04/13 17:32:20 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_dec(int *len, long long args)
{
	char	dec;
	char	minus;

	minus = '-';
	dec = '0';
	if (args == 0)
	{
		*len = *len + write(1, &dec, 1);
		return ;
	}
	if (args < 0)
	{
		*len = *len + write(1, &minus, 1);
		args = -args;
	}
	if (args >= 10)
	{
		put_dec(len, args / 10);
	}
	dec = args % 10 + '0';
	*len = *len + write(1, &dec, 1);
	return ;
}

void	put_hex(int *len, unsigned long long args, char typec)
{
	if (args == 0)
	{
		*len = *len + write(1, &LOWHEX[0], 1);
		return ;
	}
	if (args >= 16)
		put_hex(len, args / 16, typec);
	if (typec == 'p' || typec == 'x')
		*len = *len + write(1, &LOWHEX[args % 16], 1);
	else if (typec == 'X')
		*len = *len + write(1, &UPHEX[args % 16], 1);
	return ;
}

void	setdec(int *len, long long args)
{
	put_dec(len, args);
	return ;
}

void	sethex(int *len, unsigned long long args, char typec)
{
	if (typec == 'p')
	{
		if (args == 0)
		{
			*len = *len + write(1, "(nil)", 5);
			return ;
		}
		*len = *len + write(1, "0x", 2);
	}
	put_hex(len, args, typec);
	return ;
}
