compiler = g++
src = src/*.cpp
include = include/

name = FlowerShell

all: build

build: 
	$(compiler) $(src) -I$(include) -o $(name) -DUNICODE -D_UNICODE

clean:
	rm -f $(name) $(name).exe

run: build
	./$(name)