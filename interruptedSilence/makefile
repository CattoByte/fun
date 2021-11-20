CPP		=g++
CPPFLAGS	=
MAINCPP		="main.cpp"
BUILDFILE	="interruptedSilence"

all: build

build:
	$(CPP) $(MAINCPP) $(CPPFLAGS) -o $(BUILDFILE)

debug:
	clear
	$(CPP) $(MAINCPP) $(CPPFLAGS) -g -o $(BUILDFILE)
	./$(BUILDFILE)
