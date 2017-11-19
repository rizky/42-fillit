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
	int nlines;
	ssize_t reader;
	char *bf;
	char **ret;

	nlines = 0;
	if (fd == -1)
		exit(0);
	bf = (char *)malloc(sizeof(char) * BUFFER_SZ + 1);
	ret = (char **)malloc(sizeof(char *) * 4);
	reader = read(fd, bf, BUFFER_SZ);
	while (reader && nlines <=4)
	{
		if (*reader == '\n')
			nlines++;
		if (*reader ==)
		//TODO: use a "compass" to understand how to put the arrows... ^v><
	}
	return 0;
}

int main()
{
	int fd = 0;

	fd = open("tetris", O_RDONLY);
	if (fd == -1)
		exit(0);
	ft_checkvalidfile(fd);
	return 0;
}
