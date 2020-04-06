FILE=queue
SRC_FILE=src/$(FILE)
LIB_FILE=lib/lib$(FILE)
LIBS_DIR=libs
INCLUDES_DIR=libs/include

dependencies:
	mkdir -p $(LIBS_DIR)
	mkdir -p $(INCLUDES_DIR)
	wget -O $(INCLUDES_DIR)/assert.h https://raw.githubusercontent.com/ss-c-cpp/assert/master/lib/assert.h
	wget -O $(LIBS_DIR)/libassert.a https://raw.githubusercontent.com/ss-c-cpp/assert/master/lib/libassert.a

lib: src/$(FILE).o
	mkdir -p lib
	gcc -c -o $(SRC_FILE).o $(SRC_FILE).c
	ar -cvq $(LIB_FILE).a $(SRC_FILE).o
	cp $(SRC_FILE).h lib/$(FILE).h

test:
	mkdir -p out
	gcc -g -static \
		-o out/queue-test.out \
		test/queue-test.c $(SRC_FILE).c \
		-L$(LIBS_DIR) -lassert
	./out/queue-test.out

.PHONY: test lib
