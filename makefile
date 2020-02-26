# this is the make file for our gravity sim project
# authored by Sean Dashner
# this creats a file called gravSim that can be run as ./gravSim in the project
# directory
############################################################################### 
# the objects are our main, physics, and spaceobject libraries
OBJS =  main.o Physics.o SpaceObject.o SolarSystem.o Planet.o Ship.o
# adding in the open gl and glut options
LIBS =  -lGLU -lGL -lglut
# using the g++ compiler
CC = g++
# normal makefile stuff
###############################################################################
prog : $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o gravSim 

main.o: main.cpp SpaceObject.h Physics.h
	$(CC) -c main.cpp
          
SpaceObject.o: SpaceObject.h SpaceObject.cpp
	$(CC) -c SpaceObject.cpp

Physics.o:  Physics.h Physics.cpp 
	$(CC) -c Physics.cpp

SolarSystem.o: SolarSystem.h SolarSystem.cpp SpaceObject.h Planet.h
	$(CC) -c SolarSystem.cpp

Planet.o: Planet.h Planet.cpp SpaceObject.h
	$(CC) -c Planet.cpp

Ship.o: Ship.h Ship.cpp
	$(CC) -c Ship.cpp

clean:
	rm *.o  gravSim

  