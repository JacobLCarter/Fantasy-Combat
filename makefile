CXX = g++
CXXFLAGS = -g3
CXXFLAGS += -Wall
CXXFLAGS += -std=c++0x

SRCES = game.cpp character.cpp vampire.cpp barbarian.cpp blue_men.cpp \
		medusa.cpp harry_potter.cpp lineup.cpp losers.cpp utils.cpp main.cpp
HDRS = game.hpp character.hpp vampire.hpp barbarian.hpp blue_men.hpp \
	   medusa.hpp harry_potter.hpp lineup.hpp losers.hpp utils.hpp \
	   underflowException.hpp
OBJS = game.o character.o vampire.o barbarian.o blue_men.o \
	   medusa.o harry_potter.o lineup.o losers.o utils.o main.o

fantasy: ${OBJS} 
	${CXX} ${CXXFLAGS} ${OBJS} -o fantasy -ggdb

game.o: game.cpp game.hpp
	${CXX} ${CXXFLAGS} -c game.cpp

character.o: character.cpp character.hpp
	${CXX} ${CXXFLAGS} -c character.cpp

vampire.o: vampire.cpp vampire.hpp
	${CXX} ${CXXFLAGS} -c vampire.cpp

barbarian.o: barbarian.cpp barbarian.hpp
	${CXX} ${CXXFLAGS} -c barbarian.cpp

blue_men.o: blue_men.cpp blue_men.hpp
	${CXX} ${CXXFLAGS} -c blue_men.cpp

medusa.o: medusa.cpp medusa.hpp
	${CXX} ${CXXFLAGS} -c medusa.cpp

harry_potter.o: harry_potter.cpp harry_potter.hpp
	${CXX} ${CXXFLAGS} -c harry_potter.cpp

lineup.o: lineup.cpp lineup.hpp
	${CXX} ${CXXFLAGS} -c lineup.cpp

losers.o: losers.cpp losers.hpp
	${CXX} ${CXXFLAGS} -c losers.cpp

utils.o: utils.cpp utils.hpp
	${CXX} ${CXXFLAGS} -c utils.cpp

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

clean: 
	 rm *.o fantasy
