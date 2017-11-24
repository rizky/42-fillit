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

#include "../includes/fillit.h"

int		ft_count_tetrs(char *str)
{
	if (str != NULL)
		return ((int)((ft_strlen(str) + 1) / 21));
	else
		return (0);
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

int		main(int argc, char **argv)
{
	char	**tetrs;
	int		**board;
	int		success;
	int		max;

	if (!ft_isvalid(argc, argv[1]))
		return (0);
	tetrs = ft_handel_input(argv[1]);
	if (!tetrs)
	{
		ft_errormsg(0);
		return (0);
	}
	max = 2;
	success = 0;
	while (success == 0)
	{
		board = ft_init_board(max);
		success = ft_arrange_tetrs(&board, tetrs, 0, max);
		if (success)
			ft_print_board(board, max);
		max++;
	}
	ft_putchar('\n');
	return (0);
}
