#include <bits/stdc++.h>
using namespace std;

class node{

public:
    int data;
    node* left;
    node* right;

public:
    node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }

};

void levelOrderTraversal(node *root)
{

    queue<node *> q;
    q.push(root);
    q.push(NULL); // Seperator

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {

            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {

            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

node* buildTree(node* root){

    cout << "Enter the data "<<endl;
    int data;
    cin >> data;
    
    root = new node(data);

    if(data == -1){
        return NULL;
    }


    root -> left = buildTree(root -> left);
    root -> right = buildTree(root -> right);

    return root;
}

int main() {

    node* root = NULL;
    
    root = buildTree(root);
    levelOrderTraversal(root);

    return 0;
}