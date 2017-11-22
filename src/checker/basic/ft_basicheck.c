/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basicheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:13:23 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/22 12:13:24 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fillit.h"

int	ft_basicheck(const char *bf)
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
