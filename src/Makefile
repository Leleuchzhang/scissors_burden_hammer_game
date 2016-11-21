.PHONY:clean all
CC=g++
CFLAGS=-Wall -g
BIN=client service
all:$(BIN)
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
client:client.o comm.o
	$(CC) $(CFLAGS) $^ -o $@ 
	
service:service.o comm.o
	$(CC) $(CFLAGS) $^ -o $@
clean:
	rm -f *.o $(BIN)