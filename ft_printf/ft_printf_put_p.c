/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:50:49 by cclaude           #+#    #+#             */
/*   Updated: 2019/11/01 17:29:35 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_memlen(unsigned long n)
{
	int	len;

	len = 0;
	if (n / 16 > 0)
		len += ft_memlen(n / 16);
	len++;
	return (len);
}

int		ft_putmem_prewid(unsigned long n, struct s_flgs flags)
{
	int		printed;
	int		padding;
	int		count;

	count = flags.precision - ft_memlen(n);
	count = (count > 0) ? count : 0;
	padding = flags.width - count - ft_memlen(n) - 2;
	padding = (padding > 0) ? padding : 0;
	printed = 2 + padding + count;
	while (flags.minus == 0 && padding-- > 0)
		write(1, " ", 1);
	write(1, "0x", 2);
	while (count-- > 0)
		write(1, "0", 1);
	printed += ft_putmem(n, 0);
	while (flags.minus == 1 && padding-- > 0)
		write(1, " ", 1);
	return (printed);
}

int		ft_putmem_wid(unsigned long n, struct s_flgs flags)
{
	int		printed;
	int		padding;

	printed = 0;
	padding = (flags.dot == 1) ? flags.precision : flags.width - 2;
	padding -= ft_memlen(n);
	while (flags.minus == 0 && padding-- > 0)
	{
		write(1, " ", 1);
		printed++;
	}
	printed += ft_putmem(n, 1);
	while (flags.minus == 1 && padding-- > 0)
	{
		write(1, " ", 1);
		printed++;
	}
	return (printed);
}

int		ft_putmem_pre(unsigned long n, struct s_flgs flags)
{
	char	*set;
	int		i;
	int		printed;
	int		count;

	write(1, "0x", 2);
	printed = 2;
	count = (flags.dot == 1) ? flags.precision : flags.width - 2;
	count -= ft_memlen(n);
	while (count-- > 0)
	{
		write(1, "0", 1);
		printed++;
	}
	set = "0123456789abcdef";
	if (n / 16 > 0)
		printed += ft_putmem(n / 16, 0);
	i = n % 16;
	write(1, &set[i], 1);
	printed++;
	return (printed);
}

int		ft_putmem(unsigned long n, int start)
{
	char	*set;
	int		i;
	int		printed;

	printed = 0;
	if (start)
	{
		write(1, "0x", 2);
		printed += 2;
	}
	set = "0123456789abcdef";
	if (n / 16 > 0)
		printed += ft_putmem(n / 16, 0);
	i = n % 16;
	write(1, &set[i], 1);
	printed++;
	return (printed);
}
