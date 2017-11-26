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

int		ft_find_loc(int ***board, char *tetr, int **loc, int max)
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

int		ft_tetrlen(char **tetrs)
{
	int len;

	len = 0;
	while (tetrs[len])
		len++;
	return (len);
}

int		ft_arrange_tetrs(int ***board, char **tetrs, int index, int max)
{
	int *loc;

	if (index == ft_tetrlen(tetrs))
		return (1);
	loc = ft_memalloc(sizeof(int) * 2);
	loc = ft_init_loc(loc);
	while (loc[0] < max)
	{
		if (ft_find_loc(&(*board), tetrs[index], &loc, max))
		{
			ft_put_tetr(&(*board), tetrs[index], loc, index + 1);
			if (ft_arrange_tetrs(&(*board), tetrs, index + 1, max))
				return (1);
			ft_rem_tetr(&(*board), index + 1, max);
		}
		loc = ft_inc_loc(loc, max);
	}
	free(loc); //TODO: Added free here too
	return (0);
}
