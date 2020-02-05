/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:45:11 by cclaude           #+#    #+#             */
/*   Updated: 2019/10/18 16:03:52 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libutils.h"

static int	div_val(int n)
{
	int	div;

	div = 1000000000;
	if (n == 0)
		return (0);
	while (n / div < 1 && n != 0)
		div = div / 10;
	return (div);
}

static int	alloc_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (2);
	if (n == -2147483648)
		return (12);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size + 1);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		div;

	i = 0;
	if (!(s = malloc(sizeof(char) * alloc_size(n))))
		return (NULL);
	if (n == 0 || n == -2147483648)
		s = (n == 0 ? "0" : "-2147483648");
	if (n == 0 || n == -2147483648)
		return (s);
	if (n < 0)
		s[i++] = '-';
	if (n < 0)
		n = -n;
	div = div_val(n);
	while (div > 0)
	{
		s[i++] = n / div + '0';
		n = n % div;
		div = div / 10;
	}
	s[i] = '\0';
	return (s);
}
