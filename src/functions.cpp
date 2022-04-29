#include "functions.hh"
#include "priority_queue.hh"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int new_message(prio_q* message)
{
    char information[100];
    char package[100];
    int k = 0; 
    int how_many = 0;
    cout << "Podaj treść wiadomości o maksymalnie 100 znakach" << endl;
    fgets(information,100,stdin);
    for (int i=0; i<100; i++)
    {
        if(information[i]== ' ')
        {
            int random = rand() % 1000;
            message->insertRand(package, 100-i, random);
            how_many++;
            for (int j = 0; j<k; j++)
            {
                package[j] = NULL;
            }
            k=0;
        }
        else if(information[i]== '\n')
            {
                int random = rand() % 1000;
                message->insertRand(package, 100-i, random);
                how_many++;
                i = 100;
            }
            else 
                {
                    package[k] = information[i];
                    k++;
                }
    }
    return how_many;
}

void receive_message(prio_q* message_send, prio_q* message_get, int how_many)
{
    for (int i=0; i<how_many; i++)
    {
        message_get->insert(message_send->max(), message_send->priority());
        message_send->removeMax();
    }
}

void read_the_message(prio_q* message_get, int how_many)
{
    for (int i=0; i<how_many; i++)
        {
           message_get->removeMax();
        }
}

