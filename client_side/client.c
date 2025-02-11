/*
 * This is the client side file to work in concurrence with the server side  application.
 * In lieu, this program asks for user input which gets sent to the server application
 * which then outputs a random response that acts as a "fortune" much like a magic
 * 8-ball
 *
 * Author: Ethan Smith
 * Date: 02/08/2025
 * Course: CS440 - Computer Networking
 * Professor: Dr. James Jerkins
 */
 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
 
const int SERVER_PORT = 11421;
const int MAX_LINE    = 256;
const int MAX_PENDING = 5;
 
int main(int argc, char* argv[]) {
    
    char buf[MAX_LINE];
    struct hostent *hp;
    struct sockaddr_in sin;
    char *host;
    int s;
    size_t len;
	 
    if (argc == 2)
	host = argv[1]; 
    else {
	fprintf(stderr, "usage: client hostname\n");
	exit(1);
    }
	 
    hp = gethostbyname(host); 
    if (!hp)
	errx(1, "unknown host %s", host);
		 
    memset(&sin, 0, sizeof sin);
    sin.sin_family = AF_INET;
    memcpy(&sin.sin_addr, hp->h_addr, hp->h_length);
    sin.sin_port = htons(SERVER_PORT);
	
    if (((s = socket(PF_INET, SOCK_STREAM, 0)) == -1))
	err(2, "unable to open socket");
		
    if (((connect(s, (struct sockaddr*)&sin, sizeof sin)) == -1)) {
	close(s);
	err(3, "connect failed");
    }
	
    memset(buf, 0, sizeof buf);
    printf("%s", "Enter your (yes/no) question: ");
    while (fgets(buf, sizeof buf, stdin)) {
	len = strnlen(buf, sizeof buf);
	send(s, buf, len, 0);
	    
        recv(s, buf, sizeof buf, 0);
        printf("Q: %s", buf);
        memset(buf, 0, sizeof buf);

        recv(s, buf, sizeof buf, 0);
        printf("R: %s", buf);
        memset(buf, 0, sizeof buf);

        printf("\n%s", "Enter your (yes/no) question: ");
    }
	
    close(s);
    return 0;
}
