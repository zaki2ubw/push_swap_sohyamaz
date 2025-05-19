/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:57:37 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/07 19:47:37 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cv_isnumber(char c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}

int	cv_check_number(char *str)
{
	int	count;
	int	len;
	int	num;
	int	sign;

	if (str == NULL)
		return (0);
	count = 0;
	len = ut_strlen(str);
	while (count < len)
	{
		num = cv_isnumber(str[count]);
		sign = ut_issigned(str[count]);
		if (num == 0)
			return (0);
		else if (len == 1 && sign == 1)
			return (0);
		else if (count > 0 && sign == 1)
			return (0);
		count++;
	}
	return (1);
}

void	check_val(int argc, char **argv)
{
	int		i;
	int		n;
	long	val;

	i = 1;
	val = 0;
	if (argv == NULL)
		ut_error_exit();
	else if (argc == 1)
		exit(EXIT_SUCCESS);
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			ut_error_exit();
		n = cv_check_number(argv[i]);
		if (n == 0)
			ut_error_exit();
		val = ut_atoi(argv[i]);
		if (val > INT_MAX || val < INT_MIN)
			ut_error_exit();
		i++;
	}
	return ;
}
