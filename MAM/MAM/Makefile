SFML_PATH=/usr/local/Cellar/sfml/2.6.1/
CXXFLAGS= -std=c++17 -Wall -Wpedantic -I${SFML_PATH}include/
LDFLAGS=-L${SFML_PATH}lib/
CFLAGS=-g -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -pthread
CPPFLAGS=
LDLIBS=
LIBS=
CPP=g++

all: server

server: Collision.o CollisionManager.o Delegate.o entity.o PlayerEntity.o MAM.o
	$(CPP) $(CXXFLAGS) $(LDFLAGS) $(LIBS) $^ -o $@ $(CFLAGS)

clean:
	\rm -f *.o server
