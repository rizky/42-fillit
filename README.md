Algorithm:

[✅] Try max square from 2, until it can fit all the tetrs

Result:

```
AB0CD0EG
AB0CD0EG
ABBCDDEG
AF0CH0EG
IF0JH0K0
IFFJHHK0
I00JJ0KK
I0000000

./fillit  36.71s user 0.07s system 99% cpu 36.901 total

AB0CD0EF0
AB0CD0EF0
ABBCDDEFF
AGHCIJEK0
0GH0IJ0K0
LGHHIJJKK
LG00I0000
LL0000000
000000000

./fillit  1215.61s user 6.24s system 98% cpu 20:46.37 total

AAAAB..
..BBBDD
CCC.DD.
EECGGG.
.EE.GF.
HHHIFFF
H..III.

./fillit  0.28s user 0.00s system 99% cpu 0.289 total

ABJJCD.
ABJJCDD
ABBCCED
AGIIEE.
GGIFEHH
.GIFF.H
...F..H

./fillit  0.89s user 0.01s system 97% cpu 0.929 total

AB.CD.EG
AB.CD.EG
ABBCDDEG
AF.CH.EG
IF.JH.K.
IFFJHHK.
I..JJ.KK
I.......

./fillit ok_09_block  37.04s user 0.33s system 93% cpu 39.938 total


0  1  2  3  4
5  6  7  8  9
10 11 12 13 14
15 16 17 18 19
20
21 22 23 24 25


....\n
##..\n
.#..\n
.#..\n

valid test 13 : fail :/
WHAT IS EXPECTED:
BBB.
..BC
A.CC
AAAC

YOUR OUTPUT:
ABBB.
AAABC
...CC
....C
.....

```

Commands
- make re && time ./fillit inputs/tetrs0


Test Case

- [✅] bad_tetrs0
- [✅] bad_tetrs1
- [❌] bad_tetrs4
- [✅] ok_tetrs0
- [✅] ok_tetrs1
- [✅] ok_tetrs2
- [✅] ok_tetrs3

* Check if the char only # and .


__Function with free__

- arrange_tetrs.c

```C
int		ft_arrange_tetrs(int ***board, char **tetrs, int index, int max)
{
	int *loc;

	if (index == ft_tetrlen(tetrs))
		return (1);
	loc = ft_memalloc(sizeof(int) * 2);
	loc = ft_init_loc(loc);
	while (loc[0] < max)
	{
		if (ft_find_loc(&(*board), tetrs[index], &loc, max))
		{
			ft_put_tetr(&(*board), tetrs[index], loc, index + 1);
			if (ft_arrange_tetrs(&(*board), tetrs, index + 1, max))
				return (1);
			ft_rem_tetr(&(*board), index + 1, max);
		}
		loc = ft_inc_loc(loc, max);
	}
	free(loc); //TODO: Added free here too
	return (0);
}
```

- input_handler.c

```C
char	**ft_handel_input(char *str)
{
	char	**tetrs;
	int		i;
	int		offset;
	int		cnt_tetrs;

	i = 0;
	offset = 0;
	cnt_tetrs = ft_count_tetrs(str);
	if (cnt_tetrs == 0)
		return (0);
	tetrs = (char **)ft_memalloc(sizeof(char*) * (cnt_tetrs + 1));
	while (i < cnt_tetrs)
	{
		tetrs[i] = ft_tetrs_decoder(str + offset);
		if (tetrs[i] == NULL)
		{
			ft_memdel((void **)tetrs); //TODO: Added free here!
			return (0);
		}
		offset = offset + 21;
		i++;
	}
	tetrs[cnt_tetrs] = 0;
	return (tetrs);
}
```

- main.c

```C
char	*ft_checkargc(int argc, char *argv)  //TODO: This one
{
	if (argc != 2)
	{
		ft_errormsg(3);
		exit(0);
	}
	else
		return (ft_read_file(argv));
}

char	**ft_process_input(int argc, char *argv)
{
	char	**tetrs;
	char	*str;

	str = ft_checkargc(argc, argv); //TODO: I've created a new function since this one has 29 lines!! (see ft_checkargc)
	if (!str)
	{
		ft_errormsg(0);
		return (0);
	}
	if (ft_checkfile(str) == 0)
	{
		ft_errormsg(0);
		free(str);
		return (0);
	}
	tetrs = ft_handel_input(str);
	free(str);
	if (tetrs == NULL)
	{
		ft_errormsg(0);
		ft_memdel((void **)tetrs);
		return (0);
	}
	return (tetrs);
}
```