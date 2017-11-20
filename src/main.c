#include "../libft/libft.h"
#include <fcntl.h>
#define BUF_SIZE 600

void	ft_errormsg(int msg)
{
	if (msg == 1)
		ft_putstr_fd("Error when opening the file", 2);
	if (msg == 2)
		ft_putstr_fd("The file is too large", 2);
	if (msg == 3)
		ft_putstr_fd("Usage : Must have only one file allowed", 2);
}

char	*ft_filetostr(char *file)
{
	int		ret;
	int		fd;
	char	*buffer;
	int		maxfile;
	char	*output;

	maxfile = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_errormsg(1);
		return (NULL);
	}
	if (!(buffer = (char*)malloc(sizeof(*buffer) * (BUF_SIZE + 1))))
		return (NULL);
	ret = read(fd, buffer, BUF_SIZE);
	buffer[ret] = '\0';
	output = ft_strdup(buffer);
	close(fd);
	free(buffer);
	return (output);
}

int	ft_isvalid(int argc, char *argv)
{
	if (argc != 2)
	{
		ft_errormsg(1);
		return (0);
	}
	if (ft_strlen(argv) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}

void	print_board(int **board, int nrow, int ncol)
{
	int row;
	int col;

	row = 0;
	while (row < nrow)
	{
		col = 0;
		while (col < ncol)
		{
			ft_putstr(ft_itoa(board[row][col]));
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
		if (row >= max || col >= max)
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

int		tetrlen(char **tetr)
{
	int len;

	len = 0;
	while (tetr[len])
		len++;
	return (len);
}

int		max_square(char **tetrs)
{
	int len;
	int max;

	len = tetrlen(tetrs);
	
}

void	arrange_tetrs(int ***board, char **tetrs, int min_dim)
{
	int i;
	int row;
	int col;

	i = 0;
	while (tetrs[i])
	{
		row = 0;
		while (row < 6)
		{
			col = 0;
			while (col < 6)
			{
				if (is_put_tetr(&(*board), tetrs[i], row, col))
				{
					put_tetr(&(*board), tetrs[i], row, col, i);
					col = 100;
					row = 100;
				}
				col++;
			}
			row++;
		}
		i++;
	}
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

int		main(int argc, char **argv)
{
	char	*tetr_str = ">vv >>> v>> >v> >>> vvv";
	char	**tetrs = ft_strsplit(tetr_str, ' ');

	int **board;

	board = init_board(6);
	arrange_tetrs(&board, tetrs, 100);
	print_board(board, 6, 6);
	return (0);
}