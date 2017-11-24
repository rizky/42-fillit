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
	int index;

	i = 0;
	max = 0;
	index = 0;
	while (i < 19)
	{
		if (max < sol[i])
		{
			max = sol[i];
			index = i;
		}
		i++;
	}
	if (max < 1)
		return (-1);
	else
		return (index);
}

int	check_shape(int *offset_i, char tetr, char *ptr, char *str)
{
	int sol_i;

	sol_i = 0;
	if (tetr == '\0')
		sol_i = 1;
	else if (tetr == '>' && *(ptr + *offset_i + 1) == '#'
			&& (ptr + *offset_i + 1 - str) < 21)
		*offset_i = *offset_i + 1;
	else if (tetr == 'v' && *(ptr + *offset_i + 5) == '#'
			&& (ptr + *offset_i + 5 - str) < 21)
		*offset_i = *offset_i + 5;
	else if (tetr == '^' && *(ptr + *offset_i - 5) == '#'
			&& (ptr + *offset_i - 5 - str) < 21)
		*offset_i = *offset_i - 5;
	else if (tetr == '<' && *(ptr + *offset_i - 1) == '#'
			&& (ptr + *offset_i - 1 - str) < 21)
		*offset_i = *offset_i - 1;
	else
		sol_i = -1;
	return (sol_i);
}

char	*decode(char *str, int *sol, int *offset, const char tetrs[19][5])
{
	int			i;
	int			c;
	char		*ptr;

	c = 0;
	ptr = str;
	while (*ptr != '#' && *ptr != '\0')
		ptr++;
	while (is_one_solution(sol) == -1 && c < 5)
	{
		i = 0;
		while (i < 19)
		{
			if (sol[i] == 0)
				sol[i] = check_shape(&(offset[i]), tetrs[i][c], ptr, str);
			i++;
		}
		c++;
	}
	if (is_one_solution(sol) == -1)
		return (NULL);
	return (ft_strdup(tetrs[is_one_solution(sol)]));
}

char	*tetrs_decoder(char *str)
{
	const char	tetrs[19][5] = {
	">>>", "v<<", ">>v", "><v<", ">v>", "v<>>", ">v^>", "v^>>", "v>>",
	"vvv", "vv>", "vv<", "v>v", "v<v", "v><v", "v<>v", ">vv", "><vv",
	">v<"
	};
	int			*sol;
	int			*offset;
	
	if (!is_tetr_valid(str))
		return (NULL);
	sol = init_array();
	offset = init_array();
	return (decode(str, sol, offset, tetrs));
}
