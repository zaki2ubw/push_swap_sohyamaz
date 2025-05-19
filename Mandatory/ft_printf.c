/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:08:42 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/04/13 17:31:40 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_format(char typec, va_list args, int *len)
{
	if (typec == 'c')
		setchar(len, va_arg(args, int));
	else if (typec == 's')
		setstr(len, va_arg(args, char *));
	else if (typec == 'd' || typec == 'i')
		setdec(len, (long long)va_arg(args, int));
	else if (typec == 'u')
		setdec(len, (long long)va_arg(args, unsigned int));
	else if (typec == 'p')
		sethex(len, (unsigned long long)va_arg(args, void *), typec);
	else if (typec == 'x' || typec == 'X')
		sethex(len, (unsigned long long)va_arg(args, unsigned int), typec);
	else if (typec == '%')
		setchar(len, '%');
	return ;
}

void	init_variable(int *val1, int *val2, char *val3)
{
	*val1 = 0;
	*val2 = 0;
	*val3 = 0;
	return ;
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		ind;
	char	typec;
	va_list	args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	init_variable(&len, &ind, &typec);
	while (format[ind] != '\0')
	{
		if (format[ind] == '%')
		{
			ind++;
			typec = format[ind];
			set_format(typec, args, &len);
		}
		else
			len = len + write(1, &format[ind], 1);
		ind++;
	}
	va_end(args);
	return (len);
}
