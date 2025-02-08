CC=cc
CFLAGS= -Wall -g

.PHONY: clean all

all: server client

server: ./server_side/server.c
	${CC} ${CFLAGS} -o $@ ./server_side/server.c

client: ./client_side/client.c
	${CC} ${CFLAGS} -o $@ ./client_side/client.c

clean:
	@rm -f server client *.core *.c~ 
