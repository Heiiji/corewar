/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:44:51 by jjuret            #+#    #+#             */
/*   Updated: 2017/10/31 14:56:39 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

void	*ft_memdup(const void *restrict src, size_t n)
{
	unsigned char	*cursor;
	unsigned char	*copiter;
	unsigned char	*dst;
	unsigned char	*mem;

	dst = (unsigned char*)malloc(n * sizeof(unsigned char));
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
