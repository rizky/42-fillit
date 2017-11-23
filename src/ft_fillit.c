#include "../includes/fillit.h"

void	print_board(int **board, int square_size)
{
	int row;
	int col;

	row = 0;
	while (row < square_size)
	{
		col = 0;
		while (col < square_size)
		{
			if (board[row][col] != 0)
				ft_putchar(board[row][col] + 'A' - 1);
			else
				ft_putchar('.');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

int		is_put_tetr(int ***board, char *tetr, int row, int col, int max)
{
	int i;

	i = 0;
	if ((*board)[row][col] != 0)
		return (0);
	while (i < ft_strlen(tetr))
	{
		if (tetr[i] == '>')
			col++;
		if (tetr[i] == '<')
			col--;
		if (tetr[i] == 'v')
			row++;
		if (tetr[i] == '^')
			row--;
		if (row >= max || col >= max || row < 0 || col < 0)
			return (0);
		if ((*board)[row][col] != 0)
			return (0);
		i++;
	}
	return (1);
}

void	put_tetr(int ***board, char *tetr, int row, int col, int val)
{
	int i;

	i = 0;
	(*board)[row][col] = val;
	while (i < ft_strlen(tetr))
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

int		tetrlen(char **tetrs)
{
	int len;

	len = 0;
	while (tetrs[len])
		len++;
	return (len);
}

int		find_loc(int ***board, char *tetr, int *row, int *col, int max)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			if (is_put_tetr(&(*board), tetr, i, j, max))
			{
				*row = i;
				*col = j;
				return (1);	
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	rem_tetr(int ***board, int val, int max)
{
	int i;
	int j;

	i = 0;
	j = 0;
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

int		is_exist(int **board, int index, int max)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			if (board[i][j] == index)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		board_dim(int **board, int max)
{
	int i;
	int j;
	int h;
	int v;

	i = 0;
	j = 0;
	h = 0;
	v = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			if (board[i][j] != 0)
			{
				h = j;
				v = i;
			}
			j++;
		}
		i++;
	}
	if (v >= h)
		return (v);
	else
		return (h);
}

int		arrange_tetrs(int ***board, char **tetrs, int index, int square_size)
{
	int i;
	int row;
	int col;

	if (index == tetrlen(tetrs))
	{
		print_board((*board), square_size);
		ft_putchar('\n');
		return (1);
	}
	i = 0;
	row = 0;
	col = 0;
	while (i < tetrlen(tetrs))
	{
		if (!is_exist((*board), i + 1, square_size) && find_loc(&(*board), tetrs[i], &row, &col, square_size))
		{
			put_tetr(&(*board), tetrs[i], row, col, i + 1);
			if (arrange_tetrs(&(*board), tetrs, index + 1, square_size))
				return (1);
			rem_tetr(&(*board), i + 1, square_size);
		}
		i++;
	}
	return (0);
}

int		**init_board(int size)
{
	int **board;

	board = (int **)malloc(sizeof(*board) * size);
	int i = 0;
	int j = 0;
	while (i < size)
	{
		j = 0;
		board[i] = (int *)malloc(sizeof(**board) * size);
		while (j < size)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	return (board);
}