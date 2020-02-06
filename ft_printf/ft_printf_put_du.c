/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_du.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:41:14 by cclaude           #+#    #+#             */
/*   Updated: 2020/02/06 18:13:13 by cclaude          ###   ########.fr       */
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

int		ft_putnbr_prewid(long n, struct s_flgs *flags)
{
	int		printed;
	int		count;
	int		padding;

	printed = 0;
	count = flags->precision - ft_nbrlen(n);
	count += (n < 0) ? 1 : 0;
	count = (count > 0) ? count : 0;
	padding = flags->width - ft_nbrlen(n) - count;
	padding = (padding > 0) ? padding : 0;
	printed += padding + count + ft_nbrlen(n);
	while (flags->minus == 0 && padding-- > 0)
		buf_write(flags->buffer, ' ', &flags->index);
	if (n < 0)
	{
		buf_write(flags->buffer, '-', &flags->index);
		n = -n;
	}
	while (count-- > 0)
		buf_write(flags->buffer, '0', &flags->index);
	ft_putnbr(flags, n);
	while (flags->minus == 1 && padding-- > 0)
		buf_write(flags->buffer, ' ', &flags->index);
	return (printed);
}

int		ft_putnbr_wid(long n, struct s_flgs *flags)
{
	int		printed;
	int		padding;

	printed = 0;
	padding = flags->width - ft_nbrlen(n);
	while (flags->minus == 0 && padding-- > 0)
	{
		buf_write(flags->buffer, ' ', &flags->index);
		printed++;
	}
	printed += ft_putnbr(flags, n);
	while (flags->minus == 1 && padding-- > 0)
	{
		buf_write(flags->buffer, ' ', &flags->index);
		printed++;
	}
	return (printed);
}

int		ft_putnbr_pre(long n, struct s_flgs *flags)
{
	int		printed;
	int		count;

	printed = 0;
	count = (flags->dot == 1) ? flags->precision : flags->width;
	count -= (n < 0 && flags->dot == 1) ? ft_nbrlen(n) - 1 : ft_nbrlen(n);
	if (n < 0)
	{
		buf_write(flags->buffer, '-', &flags->index);
		n = -n;
		printed++;
	}
	while (count-- > 0)
	{
		buf_write(flags->buffer, '0', &flags->index);
		printed++;
	}
	printed += ft_putnbr(flags, n);
	return (printed);
}

int		ft_putnbr(struct s_flgs *flags, long n)
{
	char	c;
	int		printed;

	printed = 0;
	if (n < 0)
	{
		buf_write(flags->buffer, '-', &flags->index);
		printed++;
		n = -n;
	}
	if (n / 10 > 0)
		printed += ft_putnbr(flags, n / 10);
	c = n % 10 + '0';
	buf_write(flags->buffer, c, &flags->index);
	printed++;
	return (printed);
}
