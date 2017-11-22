/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linecheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:31:13 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/22 13:31:14 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_linecheck(const char *bf)
{
	int index;
	int linesblock;
	int charead;

	index = 0;
	linesblock = 0;
	charead = 0;
	while(bf[index])
	{
		if (bf[index] == '\n' && charead != 3)
			return (0);
		
		index++;
	}
}
