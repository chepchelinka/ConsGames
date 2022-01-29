TicTac.exe: src/* src/game/*
	gcc -o TicTac.exe src/main.c src/game/game.c src/game/matrix_api.c src/game/win_checker.c
