#include<bits/stdc++.h>
using namespace std;
int size;
struct Q{
    int front, rear, size;
    int items[size];
};
void createQueue(){
   Q my_queue;
    my_queue.front = my_queue.rear = -1;
    cout<<"Enter the size of the queue: ";
    cin>>my_queue.size;
    my_queue.items[my_queue.size];
}
void Enqueue(Q q, int value){
    if((q.front == 0 && q.rear == q.size-1) || (q.rear == (q.front-1)%(q.size-1))){
        cout<<"Queue is full";
        return;
    }
    else if(q.front == -1){
        q.front = q.rear = 0;
        q.items[q.rear] = value;
    }
    else if(q.rear == q.size-1 && q.front != 0){
        q.rear = 0;
        q.items[q.rear] = value;
    }
    else{
        q.rear++;
        q.items[q.rear] = value;
    }
}
void Dequeue(Q q){
    if(q.front == -1){
        cout<<"Queue is empty";
        return;
    }
    int data = q.items[q.front];
    q.items[q.front] = -1;
    if(q.front == q.rear){
        q.front = -1;
        q.rear = -1;
    }
    else if(q.front == q.size-1){
        q.front = 0;
    }
    else{
        q.front++;
    }
    cout<<data<<" removed from the queue";
}
int main(){
    Q test;
    createQueue();
    int size;
    cin>>size;
    test.size = size;
    Enqueue(test, 10);
    Enqueue(test, 20);
    Enqueue(test, 30);
    Dequeue(test);
    Enqueue(test, 40);
    cout<<"Front: "<<test.front<<endl;
    cout<<"Rear: "<<test.rear<<endl;
    return 0;
}
