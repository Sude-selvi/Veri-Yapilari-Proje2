all: derle calistir


derle:
	g++ -I ./include/ -o ./lib/main.o -c ./src/main.cpp 
	g++ -I ./include/ -o ./lib/dugum.o -c ./src/dugum.cpp  
	g++ -I ./include/ -o ./lib/yigit.o -c ./src/yigit.cpp
	g++ -I ./include/ -o ./lib/agac.o -c ./src/agac.cpp 
	g++ -I ./include/ -o ./lib/YBLDugum.o -c ./src/YBLDugum.cpp
	g++ -I ./include/ -o ./lib/YBL.o -c ./src/YBL.cpp
	g++ -I ./include/ -o ./lib/bagliListeDugum.o -c ./src/bagliListeDugum.cpp
	g++ -I ./include/ -o ./lib/bagliListe.o -c ./src/bagliListe.cpp
	g++ -I ./include/ -o ./bin/main ./lib/dugum.o ./lib/yigit.o ./lib/agac.o ./lib/YBLDugum.o ./lib/YBL.o ./lib/bagliListeDugum.o ./lib/bagliListe.o ./src/main.cpp

calistir:
	./bin/main