/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkvalidfile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:07:07 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/20 13:33:34 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#define BUFFER_SZ 4096

static char *ft_returnstring(const char *bf, int nlines)
{
	while (bf[0] != '\n' & bf[1] != '\n')
	{
		if (*bf == '\n')
			nlines++;
		if (*bf == '#' )
			nlines++;
		bf++;
	}
}

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
	if (reader == 0)
		exit(0);
	ret = (char **) ft_returnstring(bf, 0); //TODO: FIX
	free(*ret);
	free(ret);
	free(bf);
	return 0;
}

