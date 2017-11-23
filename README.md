Algorithm:

[v] Try max square from 2, until it can fit all the tetrs

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


0  1  2  3  4
5  6  7  8  9
10 11 12 13 14
15 16 17 18 19
20


....\n
##..\n
.#..\n
.#..\n

```

Andrea:
- ft_basicheck(input bufftetrim) --> check the presence of other char different from (.  #  \n)
- ft_validfile(input pathtofile) --> check if the file is present and readable

Commands
- make re && time ./fillit tetriminos