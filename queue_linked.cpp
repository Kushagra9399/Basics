#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};
node *head = NULL;
node *tail = NULL;
node *k;

void enqueue(int a){
    k = (struct node*)malloc(sizeof(struct node));
    k->data=a;
    k->next = NULL;
    if (head==NULL){
        head = tail = k;
    }else{
        tail->next = k;
        tail = tail->next;
    }
}

void dequeue(){
    k = head;
    if (head == NULL){
        printf("Empty Queue...");
    }else if (head == tail){
        head = tail= NULL;
    }else{
        head = head->next;
    }
    free(k);
}

void display(){
    k = head;
    if (k== NULL){
        printf("Queue Underflowed...");
    }else{
        while (k!=NULL){
            printf("%d\n",k->data);
            k = k->next;
        }
    }
}

void peek(){
    if (head==NULL){
        printf("Queue is Empty...");
    }else{
    printf("%d\n",head->data);
    }
}

int main(){
    dequeue();
    enqueue(3);
    display();
    enqueue(4);
    display();
    dequeue();
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    peek();
    enqueue(9);
    display();
}
