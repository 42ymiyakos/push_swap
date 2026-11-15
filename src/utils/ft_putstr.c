/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 11:19:29 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/09 19:15:26 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

void	ft_putstr_fd(t_context *ctx, const char *s, int fd)
{
	size_t	len;
	ssize_t	written;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	while (len > 0)
	{
		written = write(fd, s, len);
		if (written <= 0)
			error_exit(ctx);
		s += written;
		len -= (size_t)written;
	}
}
