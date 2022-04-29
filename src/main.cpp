#include <iostream>
#include "functions.hh"
#include "priority_queue.hh"
using namespace std;

//im mniejsza liczby prio tym wiekszy priorytet

int x = 1;
int y;
int main() 
{
    
    prio_q message_send;
    prio_q message_get;
    
    system("clear");
    int how_many = new_message(&message_send);
    cout << endl;
    cout << "Wiadomość zmieniona na paczki ustawione w losowej kolejności, które zostaną dodane do kolejki priorytetowej:" << endl;
    receive_message(&message_send, &message_get, how_many);
    cout << endl; 
    cout << endl; 
    cout << "Wiadomość ustawiona w pierwotnej kolejności odczytana z kolejki priorytetowej:" << endl;
    read_the_message(&message_get, how_many);   
    cout << endl;
    
    return 0;
}
