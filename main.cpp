#include <iostream>
#include <ctime>
#include <math.h>
#include <vector>
#include <cstdlib>

using namespace std;

template<typename T>
struct Node
{
       T data;
       Node* next;
       Node(T d, Node* n=NULL): data(d), next(n){}
};

template<typename T>
class myqueue
{
private:
Node<T> * first;
Node<T> * last;
int length;
public:
    myqueue() : first(NULL), last(NULL), length(0){}
    void push(T da)
    {
        if(first==NULL)
        {
           first = new Node<T>(da);
           last = first;
        }
        else
        {
           last->next = new Node<T>(da);
           last = last->next;
        }
        length++;
    }

    int giveLength()
    {
        return length;
    }

    void pop()
    {
        if(last!=NULL)
        {
            length--;
            Node<T> * temp=first;
            first = first->next;
            delete temp;
        }
    }

    void front()
    {
        if(first != NULL)
        cout << first->data;
    }

    bool isempty()
    {
        return last==NULL;
    }
};

int main()
{
    srand(time(NULL));
    int command, newCustomers, betjKunder1 = 0, betjKunder2 = 0, betjKunder3 = 0;
    double varv = 0, medel1 = 0, medel2 = 0, medel3 = 0;
    myqueue<int> q1;
    myqueue<int> q2;
    myqueue<int> q3;
    cout << "Simulation of three pay counters where one is prioritized (number one) if all the queues are equally long.\nEvery turn there is a random number of new customers arriving from 0 to 4.\nCommand (Write: 1): ";
    while(cin >> command)
    {
        varv ++;
        newCustomers = rand()%5;
        cout << "\nNew customers: " << newCustomers << endl;
        for(int i=0; i<newCustomers; i++)
        {
            if(q1.isempty())
                q1.push(1);
            else if(q2.isempty())
                q2.push(1);
            else if(q3.isempty())
                q3.push(1);
            else
            {
                if((q1.giveLength() <= q2.giveLength()) && (q1.giveLength()<= q3.giveLength()))
                    q1.push(1);
                else if(q2.giveLength() <= q3.giveLength())
                     q2.push(1);
                else if(q2.giveLength() > q3.giveLength())
                     q3.push(1);
            }
        }
        cout << "Queue 1: " << q1.giveLength();
        medel1 += q1.giveLength();
        cout << " , average waiting time: " << medel1 / varv << " minute(s). Served customers: " << betjKunder1;
        cout << "\nQueue 2: " << q2.giveLength();
        medel2 += q2.giveLength();
        cout << " , average waiting time: " << medel2 / varv << " minute(s). Served custormers: " << betjKunder2;
        cout << "\nQueue 3: " << q3.giveLength();
        medel3 += q3.giveLength();
        cout << " , average waiting time: " << medel3 / varv << " minute(s). Served customers: " << betjKunder3;
        if(q1.giveLength() > 0)
            {
                q1.pop();
                betjKunder1++;
            }
        if(q2.giveLength() > 0)
            {
                q2.pop();
                betjKunder2++;
            }
        if(q3.giveLength() > 0)
            {
                q3.pop();
                betjKunder3++;
            }
        cout << "\nCommand (Write: 1): ";
    }
    system("pause");
}
