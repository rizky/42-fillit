/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrs_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:37:36 by rnugroho          #+#    #+#             */
/*   Updated: 2017/11/23 13:37:36 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		is_put_tetr(int ***board, char *tetr, int *loc, int max)
{
	int i;
	int row;
	int col;

	row = loc[0];
	col = loc[1];
	i = 0;
	if ((*board)[row][col] != 0)
		return (0);
	while (i < ft_strlen(tetr))
	{
		if (tetr[i] == '>')
			col++;
		if (tetr[i] == '<')
			col--;
		if (tetr[i] == 'v')
			row++;
		if (tetr[i] == '^')
			row--;
		if (row >= max || col >= max || row < 0 || col < 0
			|| (*board)[row][col] != 0)
			return (0);
		i++;
	}
	return (1);
}

void	put_tetr(int ***board, char *tetr, int *loc, int val)
{
	int i;
	int row;
	int col;

	row = loc[0];
	col = loc[1];
	i = 0;
	(*board)[row][col] = val;
	while (i < ft_strlen(tetr))
	{
		if (tetr[i] == '>')
			col++;
		if (tetr[i] == '<')
			col--;
		if (tetr[i] == 'v')
			row++;
		if (tetr[i] == '^')
			row--;
		(*board)[row][col] = val;
		i++;
	}
}

void	rem_tetr(int ***board, int val, int max)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			if ((*board)[i][j] == val)
				(*board)[i][j] = 0;
			j++;
		}
		i++;
	}
}

int		is_tetr_valid(char *str)
{
	int nblock;
	int i;

	i = 0;
	nblock = 0;
	while (i < 21 && *(str + i) != '\0')
	{
		if (*(str + i) == '#')
			nblock++;
		i++;
	}
	if (nblock == 4)
		return (1);
	else
		return (0);
}
