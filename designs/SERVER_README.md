# Fortune Teller Server

## Program Requirements
For this program, in concurrence with its client counterpart, to be considered successful it must take input through the client side application
and then that message comes back to the server application. From there a function is prompted and that function returns a random message much like
a magic eight ball would after asking it a question. Finally it takes that returned message and outputs it to the console.

## Program Inputs
For this server-side application it won't be taking any inputs, at least not in terms from the server application itself but instead from the client application.i
Along with this it will not take any command line arguments because it is just a daemon.

## Program Outputs
For this server-side application it will be outputting both the input from the client-side as well as the response to the question given by the client application.

## Test Plan
As described in the assignment document, for testing at least the server application, we make use of the netcat utility(nc(1)). After establishing a connection
from the client/netcat to the server we then feed in some kind of message on the client/netcat side and see if the server side outputs both the message it was
given along with the randomly chosen response in the specified format.

## Overview
1. Client/Netcat Sends Input
    a. The client sends a message/question to the server 
2. Server Receives Input
    a. The server receives the message from the client
3. Call Response Function
    a. When the server receives a message, the server calls a
       function get_response()
4. Generate Random Response
    a. The get_response() function uses arc4random_uniform(3) to
       generate a random number which, in turn, runs through a 
       switch case and returns a response dependent on the
       random number
5. Print Question & Response to Console
    a. The message returned from the get_response() function is
       sent back to the main() method and prints both the client's
       question as well as the randomly generated response 
       in a specified format
