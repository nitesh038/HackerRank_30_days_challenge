#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;	
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }           
           return root;
           }
        }

	void levelOrder(Node * root)
    {
        std::queue<Node *> q;
        
       //Write your code here
        std::cout<<root->data;
        q.push(root);

        while(!q.empty())
        {   
            root = q.front();
            q.pop();
            if(root->left)
            {
                std::cout<<" "<<root->left->data;
                q.push(root->left);
            }
            if(root->right)
            {
                std::cout<<" "<<root->right->data;
                q.push(root->right);
            }
        }

  
	}

};//End of Solution