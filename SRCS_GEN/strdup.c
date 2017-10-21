/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeahoare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 23:32:17 by jeahoare          #+#    #+#             */
/*   Updated: 2016/12/14 21:04:25 by jeahoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		index;

	index = 0;
	while (src[index])
		index++;
	str = (char *)malloc(sizeof(*str) * index + 1);
	if (str == NULL)
		return (NULL);
	index = 0;
	while (src[index] != '\0')
	{
		str[index] = src[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
