/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:21:30 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/09 19:14:53 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putsize_fd(t_context *ctx, size_t size, int fd)
{
	char	c;

	if (size >= 10)
		ft_putsize_fd(ctx, size / 10, fd);
	c = size % 10 + '0';
	if (write(fd, &c, 1) < 0)
		error_exit(ctx);
}
