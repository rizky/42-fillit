/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:33:02 by rnugroho          #+#    #+#             */
/*   Updated: 2017/11/23 13:33:02 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_print_board(int **board, int square_size)
{
	int row;
	int col;

	row = 0;
	while (row < square_size)
	{
		col = 0;
		while (col < square_size)
		{
			if (board[row][col] != 0)
				ft_putchar(board[row][col] + 'A' - 1);
			else
				ft_putchar('.');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
