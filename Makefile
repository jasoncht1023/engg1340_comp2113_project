minigame.o: minigame.cpp minigame.h
	g++ -pedantic-errors -std=c++11 -c minigame.cpp

minigame2.o: minigame2.cpp minigame2.h
	g++ -pedantic-errors -std=c++11 -c minigame2.cpp

main.o: main.cpp minigame.h minigame2.h
	g++ -pedantic-errors -std=c++11 -c main.cpp

fm_maze: main.o minigame.o minigame2.o
	g++ -pedantic-errors -std=c++11 main.o minigame.o minigame2.o -o fm_maze
