# gauss-elim-algorithm

## Goals
A class project written in C that aims to use the mathematical method, Gauss-Jordan Elimination, to solving systems of linear equation. This algorithm also is able to identify is a system of linear equation is consistent or not.

## How to use
Enter the following code in a terminal environment that supports a C compiler

```
cc GaussElim.c
./a.out
```

There are a few test files included in this repo. To use them, the program prompts the user asking which file should be read. Below is an example of using the m04.in file

```
enter the name of the file to be read : m04.in
```

The result output should be the folowing
```
Matrix to solve
   1.00000   1.00000   1.00000   1.00000   1.00000
   2.00000   4.00000   8.00000  16.00000   9.00000
   3.00000   9.00000  27.00000  81.00000  36.00000
   4.00000  16.00000  64.00000 256.00000 100.00000

Upper Trriangular Matrix 
   4.00000  16.00000  64.00000 256.00000 100.00000
   0.00000  12.00000  60.00000 252.00000  96.00000
   0.00000   0.00000 -24.00000-192.00000 -60.00000
   0.00000   0.00000   0.00000 -24.00000  -6.00000

SOLUTION MATRIX
[0.250000]
[0.500000]
[0.250000]
[0.000000]
```
