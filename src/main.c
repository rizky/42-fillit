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

int		ft_checkgrid(char *str)
{
	int i;

	i = 0;
	while (str[i] && i < 20)
	{
		if ((i + 1) % 5 == 0 && str[i] != '\n' && i != 0)
			return (0);
		if ((i + 1) % 5 != 0 && str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

char	**ft_process_input(int argc, char *str)
{
	char	**tetrs;

	if (argc != 2)
	{
		ft_errormsg(3);
		return (0);
	}
	tetrs = ft_handel_input(str);
	if (tetrs == NULL)
	{
		ft_errormsg(0);
		return (0);
	}
	return (tetrs);
}

int		main(int argc, char **argv)
{
	char	**tetrs;
	int		**board;
	int		success;
	int		max;

	tetrs = ft_process_input(argc, argv[1]);
	if (!tetrs)
		return (0);
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
