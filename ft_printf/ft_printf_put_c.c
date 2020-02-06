/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:51:01 by cclaude           #+#    #+#             */
/*   Updated: 2019/11/01 16:49:41 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar_minwid(char c, int width)
{
	int	count;

	count = 0;
	write(1, &c, 1);
	while (count++ < width - 1)
		write(1, " ", 1);
	return (width);
}

int		ft_putchar_zerowid(char c, int width)
{
	int	count;

	count = 0;
	while (count++ < width - 1)
		write(1, "0", 1);
	write(1, &c, 1);
	return (width);
}

int		ft_putchar_wid(char c, int width)
{
	int	count;

	count = 0;
	while (count++ < width - 1)
		write(1, " ", 1);
	write(1, &c, 1);
	return (width);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
