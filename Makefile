bin/anime2: cppfiles/animatingpix.cpp headers/screen.h headers/screenc1.cpp headers/screendraw.cpp headers/particle.h headers/particle.cpp headers/swarm.h headers/swarm.cpp
	g++ -Isrc/include -Lsrc/lib -Iheaders/ -o bin/anime2.exe cppfiles/animatingpix.cpp headers/screen.h headers/screenc1.cpp headers/screendraw.cpp headers/particle.h headers/particle.cpp headers/swarm.h headers/swarm.cpp -lmingw32 -lSDL2main -lSDL2
	./bin/anime2.exe
clean:
	del -fR bin


# make sure You set compiler flags are in the following order for the make file to work for SDL.
# The order is:
# -lmingw32
# -lSDL2main
# -lSDL2
# -lSDL2_image
# -lSDL2_ttf
# -lSDL2_mixer
# - any other additional library You wish to add
