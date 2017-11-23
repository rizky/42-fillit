/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrs_decoder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:33:09 by rnugroho          #+#    #+#             */
/*   Updated: 2017/11/23 13:33:10 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		is_one_solution(int sol[19])
{
	int i;
	int	max;

	i = 0;
	max = 0;
	while (i < 19)
	{
		if (max < sol[i])
			max = sol[i];
		i++;
	}
	return (max);
}

int		get_sol(int sol[19])
{
	int i;

	i = 0;
	while (i < 19)
	{
		if (sol[i] == 1)
			return (i);
		i++;
	}
	return (0);
}


char	*tetrs_decoder(char *str)
{
	char	tetrs[19][5] = {
			">>>", "v<<", ">>v", "><v<", ">v>", "v<>>", ">v^>", "v^>>", "v>>",
			"vvv", "vv>", "vv<", "v>v", "v<v", "v><v", "v<>v", ">vv", "><vv",
			">v<"
			};
	int		sol[19] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int		offset[19] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int		i;
	int		c;
	char	*ptr;
	char	*result;

	if (!is_tetr_valid(str))
		return (NULL);
	c = 0;
	ptr = str;
	while (*ptr != '#' && *ptr != '\0')
		ptr++;
	while (is_one_solution(sol) < 1 && c < 5)
	{
		i = 0;
		while (i < 19)
		{
			if (sol[i] == 0)
			{
				if (tetrs[i][c] == '\0')
					sol[i] = 1;
				else if (tetrs[i][c] == '>' && *(ptr + offset[i] + 1) == '#'
						&& (ptr + offset[i] + 1 - str) < 21)
					offset[i] = offset[i] + 1;
				else if (tetrs[i][c] == 'v' && *(ptr + offset[i] + 5) == '#'
						&& (ptr + offset[i] + 5 - str) < 21)
					offset[i] = offset[i] + 5;
				else if (tetrs[i][c] == '^' && *(ptr + offset[i] - 5) == '#'
						&& (ptr + offset[i] - 5 - str) < 21)
					offset[i] = offset[i] - 5;
				else if (tetrs[i][c] == '<' && *(ptr + offset[i] - 1) == '#'
						&& (ptr + offset[i] - 1 - str) < 21)
					offset[i] = offset[i] - 1;
				else
					sol[i] = -1;
			}
			i++;
		}
		c++;
	}
	if (is_one_solution(sol) == 0)
		return (NULL);
	result = ft_strdup(tetrs[get_sol(sol)]);
	return (result);
}
