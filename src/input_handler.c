/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:32:53 by rnugroho          #+#    #+#             */
/*   Updated: 2017/11/23 13:32:54 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_errormsg(int msg)
{
	if (msg == 0)
		ft_putstr("error\n");
	if (msg == 3)
		ft_putstr_fd("Usage : ./fillit source_file\n", 2);
}

char	*ft_read_file(char *file)
{
	ssize_t ret;
	int		fd;
	char	*buffer;
	char	*output;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_errormsg(0);
		return (NULL);
	}
	if (!(buffer = (char*)malloc(sizeof(*buffer) * (BUF_SIZE + 1))))
		return (NULL);
	ret = read(fd, buffer, BUF_SIZE);
	buffer[ret] = '\0';
	output = ft_strdup(buffer);
	close(fd);
	free(buffer);
	return (output);
}

char	**ft_handel_input(char *argv)
{
	char	*str;
	char	**tetrs;
	int		i;
	int		offset;

	i = 0;
	offset = 0;
	str = ft_read_file(argv);
	if (ft_count_tetrs(str) == 0)
		return (0);
	tetrs = (char **)ft_memalloc(sizeof(char*) * (ft_count_tetrs(str) + 1));
	while (i < ft_count_tetrs(str))
	{
		tetrs[i] = ft_tetrs_decoder(str + offset);
		if (tetrs[i] == NULL)
			return (0);
		offset = offset + 21;
		i++;
	}
	tetrs[ft_count_tetrs(str)] = 0;
	return (tetrs);
}