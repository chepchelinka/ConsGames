# TIC TAC TOE

## This C-project is about game calls tic-tac-toe that you can play with your friend on local PC

---

## INSTALLING
To install this repository you can use next command

```
git clone https://github.com/chepchelinka/Tic-Tac.git
```

## COMPILING

If you use gcc compiler you can compile the sources like this

```
gcc -o main.exe main.c
```

or just

```
gcc main.c
```

but your final file will looks like

```
a.out 
```

---

## RUNNING

### __Linux / Unix__

```
./main.exe
```

### __Windows__

```
main.exe
```

---

## THE RULES

Rules in Tic Tac Toe are simply stupid:

Whoever first puts 3 of his pieces on the board won

---

## THE BOARD

```
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

```
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

```
+---+---+---+---+
|   | 1 | 2 | 3 |
+---+---+---+---+
```

---

## MOVING

You can make move after move invite that looks like

```
Player-X is moving
Enter coordinats as: ROW COL (2, 1)
```

Next just insert 2 numbers separated by space(s) or enter(s)

```
1 2
```

or

```
1
2
```

---

## WINNING

After somebody won the board will reset and win counter of winner increase

for example:

after Player-X won:

```
Games played: 0
P-X wins: 0
P-O wins: 0
Moves made: 0
```

before:

```
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

The __P1__, __P2__, __FREE__ constants are about char of board.

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
