#ifndef PRIOQ
#define PRIOQ

using namespace std; 

//STRUKTURA
struct s_list
{
  char data[100];
  s_list *next;
  int prio;
  int rand;
};

//KLASA
class prio_q
{
    private:
        int e_numb = 0;
        s_list *head;
        s_list *tail;
    public:
        prio_q();
        ~prio_q();
        bool isEmpty();
        void size();
        char* max();
        void removeMax();
        int  priority();
        void insert(char data[100], int prio);
        int get_e_numb() {return e_numb;}
        void insertRand(char data[100], int prio, int rand);
};
#endif