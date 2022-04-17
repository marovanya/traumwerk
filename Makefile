build:
	g++ -w -std=c++14 -Wfatal-errors \
	./src/*.cpp \
	-o bin/traumwerk \
   -lGL\
   -lGLEW\
   -lglfw

clean:
	rm ./game;

run:
	./game;
