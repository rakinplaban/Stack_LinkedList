#include <iostream>

using namespace std;

class EmptyStack{};

class Stack{
    struct Node{
        int data;
        Node* ptr;
    };
private:
    Node* top;

public:
    Stack(){
        top = NULL;
    }
    void push(int val){
        Node* node = new Node;
        node->data = val;
        node->ptr = top;
        top = node;
    }

    void pop(){
        if(top==NULL){
            throw EmptyStack();
        }
        else{
            Node* temp = new Node;
            temp = top;
            top = temp->ptr;
            delete(temp);
        }
    }

    int topData(){
        if (top==NULL){
            return -1;
        }
        else{
            return top->data;
        }
    }

    void display(){
        Node* temp = new Node;
        temp = top;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->ptr;
        }
        cout << endl;
    }
};

int main()
{
    Stack s1;
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.pop();
    s1.push(8);
    s1.push(12);
    cout << s1.topData() << endl;
    s1.display();
    return 0;
}
