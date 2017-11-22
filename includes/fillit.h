/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:35:58 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/19 18:36:00 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

int	ft_validfile(char *filestr);
int	ft_basicheck(const char *bf);

void	print_board(int **board, int square_size);
int		is_put_tetr(int ***board, char *tetr, int row, int col, int max);
void	put_tetr(int ***board, char *tetr, int row, int col, int val);
int		tetrlen(char **tetrs);
int		find_loc(int ***board, char *tetr, int *row, int *col, int max);
void	rem_tetr(int ***board, int val, int max);
int		is_exist(int **board, int index, int max);
int		board_dim(int **board, int max);
int		arrange_tetrs(int ***board, char **tetrs, int index, int square_size);
int		**init_board(int size);
#endif
