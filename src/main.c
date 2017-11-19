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

int		tetr_len(char **tetr)
{
	char	*ptr;
	int		len;

	ptr = tetr;
	len = 0;
	while (tetr[len])
		len++;
}

int		put_tetriminos(int **board, char **tetr, int min_dim)
{
	int i;

	i = 0;
	while (tetr[i])
	{

	}
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
			ft_putstr(ft_itoa(0));
			col++;
		}
		ft_putchar('\n');
		row++;
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
	char	*tetr_str = ">vv >>> v>> >v>";
	char	**tetr = ft_strsplit(tetr_str, ' ');

	int **board;

	board = init_board(6);
	print_board(board, 6, 6);

	return (0);
}