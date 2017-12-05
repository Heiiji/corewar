/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:23:35 by jjuret            #+#    #+#             */
/*   Updated: 2017/12/05 14:23:40 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

size_t	ft_strlen(const char *str)
{
	size_t index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
		index++;
	return (index);
}
