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
# include "../libft/libft.h"

#define BUF_SIZE 600

void	print_board(int **board, int square_size);
void	ft_errormsg(int msg);
void	put_tetr(int ***board, char *tetr, int *loc, int val);
void	rem_tetr(int ***board, int val, int max);
int		arrange_tetrs(int ***board, char **tetrs, int index, int square_size);
int		count_tetrs(char *str);
int		is_put_tetr(int ***board, char *tetr, int *loc, int max);
int		is_tetr_valid(char *str);
int		*init_array(void);
int		**init_board(int size);
char	*read_file(char *file);
char	*tetrs_decoder(char *str);

#endif
