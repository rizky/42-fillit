#include "../libft/libft.h"
#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	char	*tetr_str;

	char	**tetrs = ft_strsplit(tetr_str, ' ');
	int		**tetrs_arr;
	char	*str;

	int **board;
	int success;
	int square_size;

	str = read_file(argv[1]);
	int i = 0;
	int offset = 0;
	tetrs = (char **)ft_memalloc(sizeof(char*)*(count_tetrs(str) + 1));
	while (i < count_tetrs(str))
	{
		tetrs[i] = tetrs_decode(str + offset);
		if (!tetrs[i])
		{
			ft_errormsg(1);
			return (0);
		}
		offset = offset + 21;
		i++;
	}
	tetrs[count_tetrs(str)] = 0;

	square_size = 2;
	success = 0;
	while (success == 0)
	{
		board = init_board(square_size);
		success = arrange_tetrs(&board, tetrs, 0, square_size);
		square_size++;
		ft_memdel ((void **)board);
	}
	return (0);
}