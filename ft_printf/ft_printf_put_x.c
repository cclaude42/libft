/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:21:24 by cclaude           #+#    #+#             */
/*   Updated: 2019/11/02 17:21:18 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int		ft_puthex_prewid(unsigned int n, struct s_flgs flags, int cap)
{
	int		printed;
	int		count;
	int		padding;

	printed = 0;
	count = flags.precision - ft_hexlen(n);
	count += (n < 0) ? 1 : 0;
	count = (count > 0) ? count : 0;
	padding = flags.width - ft_hexlen(n) - count;
	padding = (padding > 0) ? padding : 0;
	printed += padding + count + ft_hexlen(n);
	while (flags.minus == 0 && padding-- > 0)
		write(1, " ", 1);
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (count-- > 0)
		write(1, "0", 1);
	ft_puthex(n, cap);
	while (flags.minus == 1 && padding-- > 0)
		write(1, " ", 1);
	return (printed);
}

int		ft_puthex_pre(unsigned int n, struct s_flgs flags, int cap)
{
	int		printed;
	int		count;

	printed = 0;
	count = (flags.dot == 1) ? flags.precision : flags.width;
	count -= (n >= 0) ? ft_hexlen(n) : ft_hexlen(n) - 1;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		printed++;
	}
	while (count-- > 0)
	{
		write(1, "0", 1);
		printed++;
	}
	printed += ft_puthex(n, cap);
	return (printed);
}

int		ft_puthex_wid(unsigned int n, struct s_flgs flags, int cap)
{
	int		printed;
	int		padding;

	printed = 0;
	padding = flags.width - ft_hexlen(n);
	while (flags.minus == 0 && padding-- > 0)
	{
		write(1, " ", 1);
		printed++;
	}
	printed += ft_puthex(n, cap);
	while (flags.minus == 1 && padding-- > 0)
	{
		write(1, " ", 1);
		printed++;
	}
	return (printed);
}

int		ft_puthex(unsigned int n, int cap)
{
	char	*set;
	int		printed;
	int		i;

	if (cap == 1)
		set = "0123456789ABCDEF";
	else
		set = "0123456789abcdef";
	printed = 0;
	if (n / 16 > 0)
		printed += ft_puthex(n / 16, cap);
	i = n % 16;
	write(1, &set[i], 1);
	printed++;
	return (printed);
}
