/*
 * This is the server application to be used for communicating with a client
 * application and ultimately telling a "fortune".
 *
 * Author: Ethan Smith
 * Date: 02/08/2025
 * Course: CS440 - Computer Networking
 * Professor: Dr. James Jerkins 
 */

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#include <err.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

const int MAX_LINE    = 256;
const int SERVER_PORT = 11421;
const int MAX_PENDING = 5;

char* get_response();

int main(void) {
	
	struct sockaddr_in sin;
	char buf[MAX_LINE];
	socklen_t new_len;
	int s, new_s;	
	/*
	 * build address data structure (moreso filling it out)
	 */

	memset(&sin, 0, sizeof sin);
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(SERVER_PORT);


	/*
	 * setup passive open
	 */ 
	
	if((s = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
		err(1, "unable to open socket"); 		
	}

	if((bind(s, (struct sockaddr*)&sin, sizeof sin)) == -1) {
		close(s);
		err(2, "unable to bind socket");
	} 

	if((listen(s, MAX_PENDING)) == -1) {
		close(s);
		err(3, "unable to listen on socket");
	} 

	/* wait for connection, then recieve and then pring a message*/
	while(1) { 
		memset(buf, 0, sizeof buf);
		new_len = sizeof sin;
		if((new_s = accept(s, (struct sockaddr*)&sin, &new_len)) == -1) {
			close(s);
			err(4, "accept error");
                }

		while((recv(new_s, buf, sizeof buf, 0)) > 0) {
                        //printf("%s%s", "Q: ", buf);
                        //printf("%s%s\n", "R: ", get_response());
                        //char* temp_buf = "Q: ";
                        //char* temp_response = "R: ";
                        //strncat(temp_buf, buf, sizeof "Q: " - strlen("Q: ") - 1);
                        //strncat(temp_response, get_response(), sizeof "R: " - strlen("R: ") - 1);                
                        char* response = get_response();                        

                        send(new_s, buf, new_len, 0);
                        send(new_s, response, strlen(response), 0);
			memset(buf, 0, sizeof buf);
		}

		close(new_s);
	}

	/*this will never be reached*/
	close(s);
	return 0;
}

char* get_response() {
    uint32_t choice = 1 + arc4random_uniform(20);
    
    switch(choice) {
        case 1:
            return "It is certain";
            break;
        case 2:
            return "Without a doubt";
            break;
        case 3:
            return "You may rely on it";
            break;
        case 4:
            return "Most likely";
            break;
        case 5:
            return "Yes";
            break;
        case 6:
            return "Reply hazy try again";
            break;
        case 7:
            return "Better not tell you now";
            break;
        case 8:
            return "Concentrate and ask again";
            break;
        case 9:
            return "My reply is no";
            break;
        case 10:
            return "Outlook not so good";
            break;
        case 11:
            return "Is it decidedly so";
            break;
        case 12:
            return "Yes, definitely";
            break;
        case 13:
            return "As I see it, yes";
            break;
        case 14:
            return "Outlook good";
            break;
        case 15:
            return "Signs point to yes";
            break;
        case 16:
            return "Ask again later";
            break;
        case 17:
            return "Cannot predict now";
            break;
        case 18:
            return "Don't count on it";
            break;
        case 19:
            return "My sources say no";
            break;
        case 20:
            return "Very doubtful";
            break;
    }
    return "you're not supposed to be here";    
}
