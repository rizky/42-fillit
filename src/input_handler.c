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

int		ft_count_tetrs(char *str)
{
	if (str != NULL)
		return ((int)((ft_strlen(str) + 1) / 21));
	else
		return (0);
}

char	**ft_handel_input(char *str)
{
	char	**tetrs;
	int		i;
	int		offset;
	int		cnt_tetrs;

	i = 0;
	offset = 0;
	cnt_tetrs = ft_count_tetrs(str);
	if (cnt_tetrs == 0)
		return (0);
	tetrs = (char **)ft_memalloc(sizeof(char*) * (cnt_tetrs + 1));
	while (i < cnt_tetrs)
	{
		tetrs[i] = ft_tetrs_decoder(str + offset);
		if (tetrs[i] == NULL)
		{
			free(*tetrs); //TODO: Added free here!
			free(tetrs);
			return (0);
		}
		offset = offset + 21;
		i++;
	}
	tetrs[ft_count_tetrs(str)] = 0;
	return (tetrs);
}
