//
//   Request-reply service in C++
//   Connects REP socket to tcp://localhost:5560
//   Expects "Hello" from client, replies with "World"
//
#include <string>
#include <zmq.hpp>
#include <iostream>

int main (int argc, char *argv[])
{
    zmq::context_t context(1);

    zmq::socket_t responder(context, ZMQ_REP);
    responder.connect("tcp://localhost:5560");

    while(1)
    {

        zmq::message_t request;

        //  Wait for next request from client
        responder.recv (&request);
        std::cout << "Received Hello" << std::endl;
        
       //  Send reply back to client
        zmq::message_t reply (5);
        memcpy (reply.data (), "World", 5);
        responder.send (reply);
        
    }
}