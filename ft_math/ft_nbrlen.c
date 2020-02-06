/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:22:44 by cclaude           #+#    #+#             */
/*   Updated: 2020/02/06 11:50:04 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libutils.h"

int		ft_nbrlen(long n)
{
	long	nbr;
	int		size;

	nbr = n;
	size = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		size++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}
