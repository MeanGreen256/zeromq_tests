//   Request-reply client in C++
//   Connects REQ socket to tcp://localhost:5559
//   Sends "Hello" to server, expects "World" back
//

//#include <zhelpers.hpp>
#include <string>
#include <zmq.hpp>
#include <iostream>

int main (int argc, char *argv[])
{
    zmq::context_t context(1);

    zmq::socket_t requester(context, ZMQ_REQ);
    requester.connect("tcp://localhost:5559");

    for( int request = 0 ; request < 10 ; request++) {
        zmq::message_t query (5);
        memcpy (query.data (), "Hello", 5);
        requester.send (query);

        zmq::message_t request_msg;
        //  Wait for next request from client
        requester.recv (&request_msg);
        std::cout << "Received Hello" << std::endl;
    }
}