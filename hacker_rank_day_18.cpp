#include <iostream>

using namespace std;

struct Node
{
    char data{};
    struct Node* next{NULL};
};

class Queue
{
    private:
        struct Node* front{NULL};
        struct Node* rear{NULL};

    public:
        bool isEmpty(struct Node* front)
        {
            if(front == NULL)
                return true;

            return false;
        }
        bool isFull(struct Node* r)
        {
            if(r == NULL)
                return true;
            
            return false;
        }
        void Enqueue(char c);
        int Dequeue();

};

void Queue::Enqueue(char c)
{
    struct Node* t = new Node;
    if(isFull(t))
        return ;

    t->data = c;
    //Note t->next = NULL //initialised in struct
    //Following is the Condition to check first node
    if(front == NULL)
    {
        front = rear = t;
    }
    else
    {
        rear->next = t;
        rear = t;    
    }
}
int Queue::Dequeue()
{
    if(isEmpty(front))
        return -1;

    int dequeued_element = front->data;
    front = front->next;
    return dequeued_element;
}

class Stack
{
    private:
        struct Node* top{NULL};

    public:
        bool isEmpty()
        {
            if(top == NULL)
                return true;
            
            return false;
        }
        bool isFull(struct Node* t)
        {   
            if(t == NULL)
                return true;

            return false;
        }
        void Push(char c);
        int Pop();
};

void Stack::Push(char c)
{
    struct Node* t = new Node;
    if(isFull(t))
        return;

    t->data = c;
    t->next = top;
    top = t;
}
int Stack::Pop()
{
    if(isEmpty())
        return -1;

    int popped_element = top->data;
    top = top->next;
    return popped_element;
}
class Solution {
    //Write your code here
    private:
        Stack s;
        Queue q;

    public:
        void pushCharacter(char c)
        {
            s.Push(c);
        }
        void enqueueCharacter(char c)
        {
            q.Enqueue(c);
        }
        int popCharacter()
        {
            return s.Pop();
        }
        int dequeueCharacter()
        {
            return q.Dequeue();
        }
};


int main() {
    // read the string s.
    string s;
    getline(cin, s);
    
  	// create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}