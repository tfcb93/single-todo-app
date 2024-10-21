all:
	g++ -o ./build/single-list-app main.cpp actions.cpp menu.cpp utils.cpp
run:
	./build/single-list-app