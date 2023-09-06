CC ?= gcc 
CXX ?= g++
CPP ?= g++


APP_NAME_LED= stream_LED
OBJ_FILES_LED = stream_LED.o


LIBS = .

all: $(APP_NAME_LED)

$(APP_NAME_LED): $(OBJ_FILES_LED)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $^ -g


clean:
	rm *.o $(APP_NAME_LED)
fresh:
	make clean
	make all