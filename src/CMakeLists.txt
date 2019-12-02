cmake_minimum_required(VERSION 3.15)
project("zeromq")

#find cppzmq wrapper, installed by make of cppzmq
find_package(cppzmq)
target_link_libraries( cppzmq)

add_executable( req_rep_broker.cpp
                req_rep_client.cpp
                req_rep_worker.cpp
)
