/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_du.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:41:14 by cclaude           #+#    #+#             */
/*   Updated: 2019/11/01 18:37:07 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int		ft_putnbr_prewid(long n, struct s_flgs flags)
{
	int		printed;
	int		count;
	int		padding;

	printed = 0;
	count = flags.precision - ft_nbrlen(n);
	count += (n < 0) ? 1 : 0;
	count = (count > 0) ? count : 0;
	padding = flags.width - ft_nbrlen(n) - count;
	padding = (padding > 0) ? padding : 0;
	printed += padding + count + ft_nbrlen(n);
	while (flags.minus == 0 && padding-- > 0)
		write(1, " ", 1);
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (count-- > 0)
		write(1, "0", 1);
	ft_putnbr(n);
	while (flags.minus == 1 && padding-- > 0)
		write(1, " ", 1);
	return (printed);
}

int		ft_putnbr_wid(long n, struct s_flgs flags)
{
	int		printed;
	int		padding;

	printed = 0;
	padding = flags.width - ft_nbrlen(n);
	while (flags.minus == 0 && padding-- > 0)
	{
		write(1, " ", 1);
		printed++;
	}
	printed += ft_putnbr(n);
	while (flags.minus == 1 && padding-- > 0)
	{
		write(1, " ", 1);
		printed++;
	}
	return (printed);
}

int		ft_putnbr_pre(long n, struct s_flgs flags)
{
	int		printed;
	int		count;

	printed = 0;
	count = (flags.dot == 1) ? flags.precision : flags.width;
	count -= (n < 0 && flags.dot == 1) ? ft_nbrlen(n) - 1 : ft_nbrlen(n);
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
	printed += ft_putnbr(n);
	return (printed);
}

int		ft_putnbr(long n)
{
	char	c;
	int		printed;

	printed = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		printed++;
		n = -n;
	}
	if (n / 10 > 0)
		printed += ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	printed++;
	return (printed);
}
