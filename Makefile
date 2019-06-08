dependencies:
	mkdir -p lib
	wget -O lib/assert.h https://raw.githubusercontent.com/stanley-c-cpp-projects/assert/master/src/assert.h
	wget -O lib/assert.c https://raw.githubusercontent.com/stanley-c-cpp-projects/assert/master/src/assert.c

test: test/queue-test.o src/queue.o lib/assert.o
	mkdir -p bin
	gcc -o bin/test.bin test/queue-test.o lib/assert.o src/queue.o
	./bin/test.bin
