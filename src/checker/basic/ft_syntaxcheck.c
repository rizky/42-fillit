/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntaxcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:29:48 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/22 13:29:49 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fillit.h"

int	ft_syntaxcheck(const char *bf)
{
	int index;

	index = 0;
	while (bf[index])
	{
		if (bf[index] != '.' && bf[index] != '#' && bf[index] != '\n')
			return (1);
		index++;
	}
	return (0);
}
