# TIC TAC TOE

## This C-project is about game calls tic-tac-toe

### That you can play with your friend on local PC

---

## COMPILING

If you use gcc compiler you can compile the sources like this

``` bash
gcc -o main.exe main.c
```

or just

``` bash
gcc main.c
```

but your final file will looks like

``` bash
a.out 
```

---

## RUNNING

### __Linux / Unix__

``` bash
./main.exe
```

### __Windows__

``` bash
main.exe
```

---

## THE RULES

Rules in Tic Tac Toe are simply stupid:

### Whoever first puts 3 of his pieces on the board won

---

## THE BOARD

``` text
+---+---+---+---+
|   | 1 | 2 | 3 |
+---+---+---+---+
| 1 |   |   |   |
+---+---+---+---+
| 2 |   |   |   |
+---+---+---+---+
| 3 |   |   |   |
+---+---+---+---+
```

The first row and column are helpful

### This column is about rows, you can choose for move

``` bash
+---+
|   |
+---+
| 1 |
+---+
| 2 |
+---+
| 3 |
+---+
```

### This row is about columns, you can choose for move

``` bash
+---+---+---+---+
|   | 1 | 2 | 3 |
+---+---+---+---+
```

---

## MOVING

You can make move after move invite that looks like

``` bash
Player-X is moving
Enter coordinats as: ROW COL (2, 1)
```

Next just insert 2 numbers separated by space(s) or enter(s)

``` bash
1 2
```

or

``` bash
1
2
```

---

## WINNING

After somebody won the board will reset and win counter of winner increase

for example:

after Player-X won:

``` bash
Games played: 0
P-X wins: 0
P-O wins: 0
Moves made: 0
```

before:

``` bash
Games played: 0
P-X wins: 1
P-O wins: 0
Moves made: 0
```

---

## THE CONSTANTS

In the first 5 lines in main.h looks like:

``` C
#define P1 'X'
#define P2 'O'
#define FREE ' '

#define SIZE 3
```

The P1, P2, FREE constants are about char of board.

__P1__ - The first player's constant

__P2__ - The second player's constant

__FREE__ - constant of not used (free) cell if board

__SIZE__ - constant of the size of the board. Using 3 by default but you can change it in code.

``` C
#define SIZE 4
```

In future the size will changed for a specific flag

---
---

## TO DO

- [ ] Command shell

  - [ ] exit command
  - [ ] change names command

- [ ] Flags

  - [ ] Change some constants by flag
    - [ ] SIZE
    - [ ] P1 / P2 / FREE

- [ ] Solo mode