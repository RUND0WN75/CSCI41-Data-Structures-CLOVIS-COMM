a.out: main.o die.o player.o table.o game.o
	g++ main.o die.o player.o table.o game.o

main.o: main.cc die.h player.h table.h game.h
	g++ -c main.cc

die.o: die.cc die.h
	g++ -c die.cc

player.o: player.cc player.h
	g++ -c player.cc

table.o: table.cc player.h die.h
	g++ -c table.cc

game.o: game.cc game.h player.h table.h
	g++ -c game.cc

clean:
	rm -f *.o a.out core
