/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:50:41 by cclaude           #+#    #+#             */
/*   Updated: 2019/11/01 16:49:28 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_putstr_prewid(char *s, struct s_flgs flags)
{
	int		ssize;
	int		padsize;
	int		i;
	char	c;

	c = ' ';
	if (flags.zero == 1 && flags.minus == 0)
		c = '0';
	ssize = (ft_strlen(s) < flags.precision) ? ft_strlen(s) : flags.precision;
	padsize = (flags.width > ssize) ? flags.width - ssize : 0;
	i = 0;
	while (flags.minus == 1 && i < flags.precision && s[i] != '\0')
		write(1, &s[i++], 1);
	i = 0;
	while (i++ < padsize)
		write(1, &c, 1);
	i = 0;
	while (flags.minus == 0 && i < flags.precision && s[i] != '\0')
		write(1, &s[i++], 1);
	return (ssize > flags.width ? ssize : flags.width);
}

int		ft_putstr_wid(char *s, struct s_flgs flags)
{
	int		padsize;
	int		i;
	char	c;

	c = ' ';
	if (flags.zero == 1 && flags.minus == 0)
		c = '0';
	padsize = (flags.width > ft_strlen(s)) ? flags.width - ft_strlen(s) : 0;
	i = 0;
	while (flags.minus == 1 && s[i] != '\0')
		write(1, &s[i++], 1);
	i = 0;
	while (i++ < padsize)
		write(1, &c, 1);
	i = 0;
	while (flags.minus == 0 && s[i] != '\0')
		write(1, &s[i++], 1);
	return (ft_strlen(s) > flags.width ? ft_strlen(s) : flags.width);
}

int		ft_putstr_pre(char *s, int prec)
{
	int	ssize;
	int	i;

	ssize = (ft_strlen(s) < prec) ? ft_strlen(s) : prec;
	i = 0;
	while (i < ssize && s[i] != '\0')
		write(1, &s[i++], 1);
	return (ssize);
}

int		ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write(1, &s[i++], 1);
	return (i);
}
