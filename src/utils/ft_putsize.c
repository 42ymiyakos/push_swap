/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:21:30 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/09 16:59:53 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putsize_fd(size_t size, int fd)
{
	char	c;

	if (size >= 10)
		ft_putsize_fd(size / 10, fd);
	c = size % 10 + '0';
	write(fd, &c, 1);
}
