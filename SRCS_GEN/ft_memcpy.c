/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:44:51 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 13:34:07 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*cursor;
	unsigned char	*copiter;
	unsigned char	*mem;

	mem = (unsigned char *)dst;
	if (n == 0)
		return (dst);
	cursor = (unsigned char *)dst;
	copiter = (unsigned char *)src;
	while (n--)
	{
		*cursor = *copiter;
		copiter++;
		cursor++;
	}
	return (mem);
}
