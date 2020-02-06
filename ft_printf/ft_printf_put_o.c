/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_o.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 19:56:57 by cclaude           #+#    #+#             */
/*   Updated: 2019/11/02 17:20:40 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_octlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 8;
		len++;
	}
	return (len);
}

int		ft_putoct_prewid(unsigned int n, struct s_flgs flags)
{
	int		printed;
	int		count;
	int		padding;

	printed = 0;
	count = flags.precision - ft_octlen(n);
	count += (n < 0) ? 1 : 0;
	count = (count > 0) ? count : 0;
	padding = flags.width - ft_octlen(n) - count;
	padding = (padding > 0) ? padding : 0;
	printed += padding + count + ft_octlen(n);
	while (flags.minus == 0 && padding-- > 0)
		write(1, " ", 1);
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (count-- > 0)
		write(1, "0", 1);
	ft_putoct(n);
	while (flags.minus == 1 && padding-- > 0)
		write(1, " ", 1);
	return (printed);
}

int		ft_putoct_pre(unsigned int n, struct s_flgs flags)
{
	int		printed;
	int		count;

	printed = 0;
	count = (flags.dot == 1) ? flags.precision : flags.width;
	count -= (n >= 0) ? ft_octlen(n) : ft_octlen(n) - 1;
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
	printed += ft_putoct(n);
	return (printed);
}

int		ft_putoct_wid(unsigned int n, struct s_flgs flags)
{
	int		printed;
	int		padding;

	printed = 0;
	padding = flags.width - ft_octlen(n);
	while (flags.minus == 0 && padding-- > 0)
	{
		write(1, " ", 1);
		printed++;
	}
	printed += ft_putoct(n);
	while (flags.minus == 1 && padding-- > 0)
	{
		write(1, " ", 1);
		printed++;
	}
	return (printed);
}

int		ft_putoct(unsigned int n)
{
	char	*set;
	int		printed;
	int		i;

	set = "01234567";
	printed = 0;
	if (n / 8 > 0)
		printed += ft_putoct(n / 8);
	i = n % 8;
	write(1, &set[i], 1);
	printed++;
	return (printed);
}
