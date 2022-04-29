#include "priority_queue.hh"
#include <iostream>

using namespace std;

//FUNKCJE KLASY PRIO_Q
prio_q::prio_q()
{
    head = NULL;
}

prio_q::~prio_q()
{
    while(head)
    {
        removeMax();
    }
}

bool prio_q::isEmpty()
{
    cout << "czy pusta:" << !head << endl;
    return !head;
}

void prio_q::size()
{
    int number = get_e_numb();
    cout << "Wiadomość składa się z " << number << " części" << endl;
}


char* prio_q::max()
{
    if(head)
    {
        return head->data;
    }
    else
    {
        throw "EmptyQueueException";
    }
}

void prio_q::removeMax()
{
    if(head)
    {
        cout << head->data << " ";
    }
    else
    {
        throw "EmptyQueueException";
    }
    if(head)
    {
        s_list* p = head;
        head = head->next;
        if (!head)
        {
            tail = NULL;
        }
        delete p;
        e_numb--;  
    }
    else
    {
        throw "EmptyQueueException";
    }

}

void prio_q::insert(char data[100], int prio)
{
    e_numb++;
    s_list *p, *r;
    p = new s_list;
    p->next = NULL;
    p->prio = prio;
    for(int i=0; i<100; i++)
    {
        p->data[i] = data[i]; 
        if (data[i] == NULL)
        {
            i=100;
        }  
    }
    if (!head)
    {
        head = p;
        tail = p;
    }
    else if (head->prio < prio)
    {
        p->next = head;
        head = p;
    }
    else
    {
        r = head;
        while ((r->next) && (r->next->prio >= prio))
            {
                r = r->next;
            }
        p->next = r->next;
        r->next = p;
        if(!p->next)
        {
            tail = p;
        }
    }
}

int  prio_q::priority()
{
    if(!head)
    {
        throw "EmptyQueueException";
    }
    else
    { 
        return head->prio;
    }
}

void prio_q::insertRand(char data[100], int prio, int rand)
{
    s_list *p, *r;
    p = new s_list;
    p->next = NULL;
    p->prio = prio;
    p->rand = rand;
    for(int i=0; i<100; i++)
    {
        p->data[i] = data[i]; 
        if (data[i] == NULL)
        {
            i=100;
        }  
    }
    if (!head)
    {
        head = p;
        tail = p;
    }
    else if (head->rand < rand)
    {
        p->next = head;
        head = p;
    }
    else
    {
        r = head;
        while ((r->next) && (r->next->rand >= rand))
            {
                r = r->next;
            }
        p->next = r->next;
        r->next = p;
        if(!p->next)
        {
            tail = p;
        }
    }
}