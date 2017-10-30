/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:59:39 by jjuret            #+#    #+#             */
/*   Updated: 2017/10/30 13:21:12 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	isneg(int *target, int *neg)
{
	if (*target < 0)
	{
		*target = -(*target);
		*neg = 1;
		return (1);
	}
	return (0);
}

static int	leng(int target)
{
	int	result;

	result = 0;
	while (target > 0)
	{
		target /= 10;
		result++;
	}
	return (result);
}

static char	*count(char *result, int n)
{
	while (n > 0)
	{
		result--;
		*result = (n % 10) + 48;
		n /= 10;
	}
	return (result);
}

char		*ft_itoa(int n)
{
	char	*result;
	int		size;
	int		neg;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	size = isneg(&n, &neg) + leng(n) + 1;
	if ((result = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	result += (size - 1);
	*result = '\0';
	result = count(result, n);
	if (neg == 1)
	{
		result--;
		*result = '-';
	}
	return (result);
}
