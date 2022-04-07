TicTac.exe: src/*
	gcc -o $@ \
		src/switcher.c    \
		src/game.c        \
		src/matrix_api.c  \
		src/win_checker.c \
		src/misc.c
