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

void	ft_print_board(int **board, int max);
void	ft_errormsg(int msg);
void	ft_put_tetr(int ***board, char *tetr, int *loc, int val);
void	ft_rem_tetr(int ***board, int val, int max);
int		ft_arrange_tetrs(int ***board, char **tetrs, int index, int max);
int		ft_count_tetrs(char *str);
int		ft_is_put_tetr(int ***board, char *tetr, int *loc, int max);
int		ft_is_tetr_valid(char *str);
int		*ft_init_array(void);
int		**ft_init_board(int size);
int		**ft_reset_board(int ***board, int size);
char	*ft_read_file(char *file);
char	*ft_tetrs_decoder(char *str);
int		*ft_init_loc(int *loc);
int		*ft_inc_loc(int *loc, int max);
char	**ft_handel_input(char *argv);
#endif
