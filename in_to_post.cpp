#include <iostream>
using namespace std;

char stack[50];
int top = -1;
void push(char a){
    stack[top+1]=a;
    top++;
}

char pop(){
    if(top == -1){
        printf("Stack Underflowed!!!");
    }else{
        char a = stack[top];
        top--;
        return a;
    }
}

bool isEmpty(){
    if(top==-1){
        return true;
    }else{
        return false;
    }
}

void display(){
    int i = top;
    for(i;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}

void peak(){
    printf("Top element is: %d\n",stack[top]);
}

int prio(char a){
    if (a=='*' || a=='/'){
        return 3;
    }else if (a=='+' || a=='-'){
        return 2;
    }else{
        return 1;
    }
}

int main(){
    char a;
    string infi;
    string post="";
    printf("Enter the infix: ");
    getline(cin,infi);
    for (int i=0;i!=infi.length();i++){
        if (infi[i]=='('){
            push(infi[i]);
        }else if(isalnum(infi[i])==true){
            post = post + infi[i];
        }else if(infi[i]==')'){
            while(stack[top]!='('){
                post += pop();
            }
            a=pop();
        }else{
            if (isEmpty()==true){
                push(infi[i]);
            }else if (isEmpty()==false){
                if (prio(infi[i])<=prio(stack[top])){
                    a = stack[top];
                    post+=pop();
                    push(infi[i]);
                }else {
                    push(infi[i]);
                }
            }
        }
    }
    while(stack[top]!=NULL){
        post += pop();
    }
    cout << post;
}
