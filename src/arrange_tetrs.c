/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_tetrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:37:27 by rnugroho          #+#    #+#             */
/*   Updated: 2017/11/23 13:37:27 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		find_loc(int ***board, char *tetr, int **loc, int max)
{
	int *c;

	c = ft_memalloc(sizeof(int) * 2);
	c[0] = (*loc)[0];
	c[1] = (*loc)[1];
	while (c[0] < max)
	{
		c[1] = 0;
		while (c[1] < max)
		{
			if (ft_is_put_tetr(&(*board), tetr, c, max))
			{
				(*loc)[0] = c[0];
				(*loc)[1] = c[1];
				return (1);
			}
			c[1]++;
		}
		c[0]++;
	}
	return (0);
}

int		is_exist(int **board, int index, int max)
{
	int i;
	int j;

	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			if (board[i][j] == index)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		tetrlen(char **tetrs)
{
	int len;

	len = 0;
	while (tetrs[len])
		len++;
	return (len);
}

int		ft_arrange_tetrs(int ***board, char **tetrs, int index, int max)
{
	int i;
	int *loc;

	if (index == tetrlen(tetrs))
	{
		ft_print_board((*board), max);
		return (1);
	}
	i = 0;
	loc = ft_memalloc(sizeof(int) * 2);
	while (i < tetrlen(tetrs))
	{
		// loc[0] = 0;
		// loc[1] = 1;
		if (!is_exist((*board), i + 1, max) &&
			find_loc(&(*board), tetrs[i], &loc, max))
		{
			ft_put_tetr(&(*board), tetrs[i], loc, i + 1);
			ft_print_board((*board), max);
			ft_putchar('\n');
			if (ft_arrange_tetrs(&(*board), tetrs, index + 1, max))
				return (1);
			ft_rem_tetr(&(*board), i + 1, max);
			loc[1] = loc[1] + 1;
			// if (loc[1] == max)
			// {
			// 	loc[1] = 0;
			// 	loc[0] = loc[0] + 1;
			// 	if (loc[0] == max)
			// 		break;
			// }
		}
		i++;
	}
	return (0);
}
