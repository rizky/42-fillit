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

int		ft_isvalid(int argc, char *argv)
{
	if (argc != 2)
	{
		ft_errormsg(3);
		return (0);
	}
	if (ft_strlen(argv) == 0)
	{
		ft_errormsg(0);
		return (0);
	}
	return (1);
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
