/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_tetrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:12:23 by rnugroho          #+#    #+#             */
/*   Updated: 2017/11/24 15:12:23 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		find_loc(int ***board, char *tetr, int **loc, int max)
{
	while ((*loc)[0] < max)
	{
		if (ft_is_put_tetr(&(*board), tetr, (*loc), max))
			return (1);
		(*loc)[1]++;
		if ((*loc)[1] == max)
		{
			(*loc)[0]++;
			(*loc)[1] = 0;
		}
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
		return (1);
	i = 0;
	loc = ft_memalloc(sizeof(int) * 2);
	while (i < tetrlen(tetrs))
	{
		loc = ft_init_loc(loc);
		while (loc[0] < max)
		{
			if (!is_exist((*board), i + 1, max) &&
				find_loc(&(*board), tetrs[i], &loc, max))
			{
				ft_put_tetr(&(*board), tetrs[i], loc, i + 1);
				if (ft_arrange_tetrs(&(*board), tetrs, index + 1, max))
					return (1);
				ft_rem_tetr(&(*board), i + 1, max);
			}
			loc = ft_inc_loc(loc, max);
		}
		i++;
	}
	return (0);
}
