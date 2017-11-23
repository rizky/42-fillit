#include "../includes/fillit.h"

void	ft_errormsg(int msg)
{
	if (msg == 1)
		ft_putstr_fd("Error when opening the file", 2);
	if (msg == 2)
		ft_putstr_fd("The file is too large", 2);
	if (msg == 3)
		ft_putstr_fd("Usage : Must have only one file allowed", 2);
}

char	*read_file(char *file)
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

int		count_tetrs(char *str)
{
	return ((ft_strlen(str) + 1) / 21);
}

int 	is_one_solution(int sol[19])
{
	int i;
	int	n;

	i = 0;
	n = 0;
	while (i < 19)
	{
		n = sol[i] + n;
		i++;
	}
	return (n);
}


int 	get_sol(int sol[19])
{
	int i;
	i = 0;
	while (i < 19)
	{
		if (sol[i] == 1)
			return (i);
		i++;
	}
	return (0);
}

char	*tetrs_decode(char *str)
{
	char tetrs[19][5] = {
    ">>>", "v<<", ">>v", "><v<", ">v>", "v<>>", ">v^>", "v^>>", "v>>",
	"vvv", "vv>", "vv<", "v>v", "v<v", "v><v", "v<>v", ">vv", "><vv",
	">v<"
	};
	int	sol[19] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int	offset[19] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i;
	int c;
	char *ptr;
	char *result;

	c = 0;
	ptr = str;
	while (*ptr != '#' && *ptr != '\0')
		ptr++;
	while (is_one_solution(sol) > 1)
	{
		i = 0;
		while (i < 19)
		{
			if (sol[i])
			{
				if (tetrs[i][c] == '\0')
					sol[i] = 1;
				else if (tetrs[i][c] == '>' && *(ptr + offset[i] + 1) == '#')
					offset[i] = offset[i] + 1;
				else if (tetrs[i][c] == 'v' && *(ptr + offset[i] + 5) == '#')
					offset[i] = offset[i] + 5;
				else if (tetrs[i][c] == '^' && *(ptr + offset[i] - 5) == '#')
					offset[i] = offset[i] - 5;
				else if (tetrs[i][c] == '<' && *(ptr + offset[i] - 1) == '#')
					offset[i] = offset[i] - 1;
				else
					sol[i] = 0;
			}
			i++;
		}
		c++;
	}
	if (is_one_solution(sol) == 0)
		return (NULL);
	result = ft_strdup(tetrs[get_sol(sol)]);
	return (result);
}