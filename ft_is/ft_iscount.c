/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:35:08 by cclaude           #+#    #+#             */
/*   Updated: 2020/02/05 18:35:37 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libutils.h"

int	ft_iscount(int c, char *base)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			count++;
		i++;
	}
	return (count);
}