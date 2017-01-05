# Hello
CXX=g++
LIBS=-lm -lSDL2 -lGL -lGLEW
OPT=-O3
CXXFLAGS=-I. -std=c++11 -Wall $(OPT)
DEPS=MainGame.h Variables.h PixelList.h Curve.h
OBJ=Curve.o MainGame.o PixelList.o main.o


#$@ = left side of :
#$^ = right side of :

# %.o depends on %.cpp and DEPS
%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

ulamspiral: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

# Do not do something with the file "clean"
.PHONY: clean nuke force
clean:
	rm -f *.o ulamspiral

nuke: clean
	@echo Calm down!

force: clean ulamspiral
