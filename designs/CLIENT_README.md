# Fortune Teller Server

## Program Requirements
For this program, in concurrence with its server counterpart, to be considered successful it must take input through the client side application
and then that message goes to the server application. From there a function is prompted and that function returns a random message much like
a magic eight ball would after asking it a question. Finally the server side takes that returned message and outputs it to the console.

## Program Inputs
For the client-side application, it prompts the user for a question and awaits their input.

## Program Outputs
The client-side application itself won't output anything but instead sends a message to the server-side application which, in turn, prints a response to the console

## Test Plan
To test this client-side application we will use the server-side application that was made previous to this one. We will input a yes/no question that is prompted by
the client-side and check if the server side prompty outputs both the question and the randomly chosen response in the specified format.

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
       question as well as the randomly generated response in a
       specified format.
