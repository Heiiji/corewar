/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:24:15 by jjuret            #+#    #+#             */
/*   Updated: 2017/12/05 14:24:15 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_put(char *str, char c, char fd, char bool_free)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
	(c != 0) ? write(fd, &c, 1) : 0;
	(bool_free == 1) ? ft_strdel(&str) : 0;
}
