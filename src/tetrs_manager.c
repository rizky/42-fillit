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

int		ft_is_put_tetr(int ***board, char *tetr, int *loc, int max)
{
	int		i;
	int		row;
	int		col;

	row = loc[0];
	col = loc[1];
	i = -1;
	if ((*board)[row][col] != 0)
		return (0);
	g_tetr_len = (int)ft_strlen(tetr);
	while (++i < g_tetr_len)
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
	}
	return (1);
}

void	ft_put_tetr(int ***board, char *tetr, int *loc, int val)
{
	int		i;
	int		row;
	int		col;

	row = loc[0];
	col = loc[1];
	i = 0;
	(*board)[row][col] = val;
	g_tetr_len = (int)ft_strlen(tetr);
	while (i < g_tetr_len)
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

void	ft_rem_tetr(int ***board, int val, int max)
{
	int i;
	int j;

	i = 0;
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

int		ft_is_tetr_valid(char *str)
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
