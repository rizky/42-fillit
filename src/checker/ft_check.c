/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:05:06 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/22 13:05:08 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fillit.h"
#define BUFFER_SZ 4096

int	ft_validfile(char *filestr)
{
	int fd;
	char *bf;

	fd = open(filestr, O_RDONLY);
	if (fd == -1)
		return (1);
	bf = (char *)malloc(sizeof(char) * BUFFER_SZ + 1);
	if (!read(fd,bf,BUFFER_SZ))
		return (1);
	if (!ft_syntaxcheck(bf))
		return (1);
	return (0);
}

//int main(int argc, char **argv)
//{
//	if (argc != 2)
//	{
//		ft_putstr("error\n");
//		exit(0);
//	}
//	if (!ft_validfile(argv[1]))
//	{
//		ft_putstr("error\n");
//		exit(0);
//	}
//}
