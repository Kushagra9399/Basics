#include <iostream>
using namespace std;

int front= -1;
int rear= -1;
int queue[10];

void enqueue(int a){
    if (rear==9){
        printf("Queue Overflowed...\n");
    }else if (front==-1 && rear==-1){
        front = rear = 0;
        queue[rear]=a;
    }else{
        queue[rear+1]=a;
        rear++;
    }
};

void dequeue(){
    if (rear==-1){
        printf("Queue Underflowed...\n");
    }else if (front==0 && rear==0){
        printf("Poped: %d\n",queue[front]);
        front = rear = -1;
    }else{
        printf("Poped: %d\n",queue[front]);
        front++;
    }
}

void display(){
    if (front==-1 && rear==-1){
        printf("Queue is Empty...\n");
    }else{
        for (int i = front;i<rear+1;i++){
            printf("%d\n",queue[i]);
        }
    }
}

int peak(){
    if (front==-1 && rear==-1){
        return -1;
    }else{
        return queue[front];
    }
}

int main(){
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    display();
    cout<<peak();
    dequeue();
    display();
    enqueue(7);
    enqueue(8);
    display();
    cout<<peak();
}
