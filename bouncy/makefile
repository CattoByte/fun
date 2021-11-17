CPP		=g++
CPPFLAGS	=-O #I'm dumb so I need to use this to avoid smashing my stack or having the bus fail on me
MAINCPP		="main.cpp"
BUILDFILE	="bouncy"

all: build

build:
	$(CPP) $(MAINCPP) $(CPPFLAGS) -o $(BUILDFILE)

debug:
	clear
	$(CPP) $(MAINCPP) $(CPPFLAGS) -g -o $(BUILDFILE)
	./$(BUILDFILE)
