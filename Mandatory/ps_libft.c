/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:16:46 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/06 18:41:48 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ut_strlen(char *str)
{
	int	c;

	c = 0;
	if (str == NULL)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

void	ut_bzero(void *s, size_t n)
{
	unsigned char	*p;

	if (s == NULL)
		return ;
	p = (unsigned char *)s;
	while (n != 0)
	{
		*p = 0;
		n--;
		p++;
	}
	return ;
}

void	*ut_calloc(size_t nmemb, size_t size)
{
	unsigned char	*buf;

	if (size == 0 || nmemb == 0)
	{
		buf = (unsigned char *)malloc(1);
		if (buf == NULL)
		{
			return (NULL);
		}
		return (buf);
	}
	if (size != 0 && nmemb != 0 && nmemb > SIZE_MAX / size)
	{
		return (NULL);
	}
	buf = (unsigned char *)malloc(size * nmemb);
	if (buf == NULL)
	{
		return (NULL);
	}
	ut_bzero(buf, (size * nmemb));
	return (buf);
}
