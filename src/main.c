#include "../libft/libft.h"
#include "../includes/fillit.h"

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



int		main(int argc, char **argv)
{
	char	*tetr_str = "vvv vv> vvv vv> vvv vv> vvv vv> vvv vv> vv> vv>";
	char	**tetrs = ft_strsplit(tetr_str, ' ');

	int **board;
	int success;
	int square_size;

	square_size = 2;
	while (success == 0)
	{
		board = init_board(square_size);
		success = arrange_tetrs(&board, tetrs, 0, square_size);
		square_size++;
		ft_memdel ((void **)board);
	}
	return (0);
}