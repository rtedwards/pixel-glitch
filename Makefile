CXX		  := clang++
CXX_FLAGS := -Wall -Wextra -Wno-missing-field-initializers -std=c++17 -g

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*

compile:
	clang++ -Wall -Wextra -Wno-missing-field-initializers -std=c++17 -g -I$(INCLUDE) -L$(LIB) src/main.cpp -o bin/pixel-glitch

compile-window:
	clang++ -Wall -Wextra -std=c++17 -g -Iinclude -I/opt/X11/include -L/opt/X11/lib -lX11 -lz -Dcimg_display src/main.cpp -o bin/pixel-glitch

compile-lib:
	clang++ -Wall -Wextra -std=c++17 -g -Iinclude -I/opt/X11/include -L/opt/X11/lib -lX11 -lz -ltiff -ljpeg -lpng -Dcimg_display src/main.cpp -o bin/pixel-glitch