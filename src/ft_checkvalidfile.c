/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkvalidfile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:07:07 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/19 17:07:09 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#define BUFFER_SZ 4096


int	ft_checkvalidfile(int fd)
{
	ssize_t reader;
	char *bf;
	char **ret;

	if (fd == -1)
		exit(0);
	bf = (char *)malloc(sizeof(char) * BUFFER_SZ + 1);
	ret = (char **)malloc(sizeof(char *) * 4);
	reader = read(fd, bf, BUFFER_SZ);
	return 0;
}
