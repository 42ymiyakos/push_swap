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
	if (s == NULL)
		return ;
	if (write(fd, s, ft_strlen(s)) < 0)
		error_exit(ctx);
}
