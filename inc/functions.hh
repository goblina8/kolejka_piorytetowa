#ifndef FUNCTIONS
#define FUNCTIONS
#include "priority_queue.hh"
using namespace std; 

int new_message(prio_q* message);
void receive_message(prio_q* message, prio_q* message_get, int how_many);
void read_the_message( prio_q* message_get, int how_many);  

#endif