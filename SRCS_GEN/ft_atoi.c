/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:19:40 by jjuret            #+#    #+#             */
/*   Updated: 2017/10/20 08:49:20 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int			ft_atoi(const char *str)
{
	char	*cursor;
	int		result;
	int		neg;

	neg = 1;
	cursor = (char *)str;
	result = 0;
	while ((*cursor <= (char)13 && *cursor >= (char)9) || *cursor == (char)32)
		cursor++;
	if (*cursor == '-' || *cursor == '+')
	{
		if (*cursor == '-')
			neg = -1;
		cursor++;
	}
	while (*cursor >= '0' && *cursor <= '9')
	{
		result *= 10;
		result += *cursor - 48;
		cursor++;
	}
	return (result * neg);
}
