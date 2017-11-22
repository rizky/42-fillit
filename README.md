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
```

Andrea:
- **ft_basicheck**(input bufftetrim) --> check the presence of other char different from (.  #  \n)
- **ft_validfile**(input pathtofile) --> check if the file is present and readable
- **ft_linecheck**(input bufftetrim) --> check if the tetriminos block is valid