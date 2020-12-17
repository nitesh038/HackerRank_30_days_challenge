#include <iostream>
#include <cstddef>

using namespace std;	

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

		int getHeight(Node* root)
        {
          //Write your code here
           if(root==NULL)
            return -1;

          int x=0;
          int y=0;
          x = getHeight(root->left);
          y = getHeight(root->right);

          if(x>y)
          {
              return x+1;
          }
          else
          {
            return y+1;
          }
          
        }

}; //End of Solution