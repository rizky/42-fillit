/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:05:41 by rnugroho          #+#    #+#             */
/*   Updated: 2017/11/23 13:05:41 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fillit.h"

int		count_tetrs(char *str)
{
	return ((ft_strlen(str) + 1) / 21);
}

char	**handel_input(char *argv)
{
	char	*str;
	char	**tetrs;
	int		i;
	int		offset;

	i = 0;
	offset = 0;
	str = read_file(argv);
	if (count_tetrs(str) == 0)
		return (0);
	tetrs = (char **)ft_memalloc(sizeof(char*) * (count_tetrs(str) + 1));
	while (i < count_tetrs(str))
	{
		tetrs[i] = tetrs_decoder(str + offset);
		if (tetrs[i] == NULL)
		{
			return (0);
		}
		offset = offset + 21;
		i++;
	}
	tetrs[count_tetrs(str)] = 0;
	return (tetrs);
}

int		main(int argc, char **argv)
{
	char	**tetrs;
	int		**board;
	int		success;
	int		square_size;

	tetrs = handel_input(argv[1]);
	if (!tetrs)
	{
		ft_putstr("Error\n");
		return (0);
	}
	square_size = 2;
	success = 0;
	while (success == 0)
	{
		board = init_board(square_size);
		success = arrange_tetrs(&board, tetrs, 0, square_size);
		square_size++;
	}
	ft_putchar('\n');
	return (0);
}
