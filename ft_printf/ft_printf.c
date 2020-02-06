/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:18:32 by cclaude           #+#    #+#             */
/*   Updated: 2019/11/01 20:01:26 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		func_branch(const char *s, int *i, va_list args)
{
	struct s_flgs	flags;
	int				printed;

	(*i)++;
	flagger(s, i, &flags, args);
	if (s[*i] == 'c')
		printed = ft_print_char(va_arg(args, int), flags);
	else if (s[*i] == 's')
		printed = ft_print_str(va_arg(args, char *), flags);
	else if (s[*i] == 'p')
		printed = ft_print_mem(va_arg(args, unsigned long), flags);
	else if (s[*i] == 'd' || s[*i] == 'i')
		printed = ft_print_nbr(va_arg(args, int), flags);
	else if (s[*i] == 'u')
		printed = ft_print_nbr(va_arg(args, unsigned int), flags);
	else if (s[*i] == 'x' || s[*i] == 'X')
		printed = ft_print_hex(va_arg(args, unsigned int), flags, s[*i]);
	else if (s[*i] == 'o')
		printed = ft_print_oct(va_arg(args, unsigned int), flags);
	else
		printed = ft_print_other(s[*i], flags);
	if (s[*i] != '\0')
		(*i)++;
	return (printed);
}

int		ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		printed;

	va_start(args, string);
	i = 0;
	printed = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
			printed += func_branch(string, &i, args);
		else
		{
			write(1, &string[i++], 1);
			printed++;
		}
	}
	va_end(args);
	return (printed);
}
