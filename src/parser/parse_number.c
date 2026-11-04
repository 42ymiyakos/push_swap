/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 19:01:22 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/03 14:48:08 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	parse_number(const char *s, int *out)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		++s;
	}
	if (!('0' <= *s && *s <= '9'))
		return (0);
	while ('0' <= *s && *s <= '9')
	{
		result = result * 10 + *s - '0';
		if (result * sign < INT_MIN || result * sign > INT_MAX)
			return (0);
		++s;
	}
	if (*s != '\0')
		return (0);
	*out = result * sign;
	return (1);
}
