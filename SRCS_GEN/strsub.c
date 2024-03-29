/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeahoare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:24:22 by jeahoare          #+#    #+#             */
/*   Updated: 2016/12/14 20:59:44 by jeahoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*s_2;
	unsigned int	u_i;

	if (s == NULL)
		return (NULL);
	u_i = 0;
	s_2 = (char *)s;
	str = (char *)malloc(sizeof(*str) * len + 1);
	if (str == NULL)
		return (NULL);
	while (s_2[start] && len > 0)
	{
		str[u_i] = s_2[start];
		u_i++;
		start++;
		len--;
	}
	str[u_i] = '\0';
	return (str);
}
