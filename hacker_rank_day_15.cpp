#include <iostream>
#include <cstddef>
using namespace std;	
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:

      Node* insert(Node *head,int data)
      {
          Node* node= new Node(data);

          Node *p1 = head;
          //Complete this method
          if(head == NULL)
          {
              head = node;
              p1 = head;
              return head;
          }
          else
          {
            while(p1->next != NULL)
            {
                p1 = p1->next;
            } 
            p1->next = node;
            return head;
          }
      }

      void display(Node *head)
      {
          Node *start=head;
          while(start)
          {
              cout<<start->data<<" ";
              start=start->next;
          }
      }
};
int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }	
	mylist.display(head);
		
}