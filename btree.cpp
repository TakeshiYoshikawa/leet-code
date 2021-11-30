#include <iostream>
#include <cstdlib>

class Node{
    public:
        int data;
        Node* left = NULL;
        Node* right = NULL;

        Node(int data){
            this->data = data;
        }
};

class BinaryTree{
    private:
    public:
        Node* root;

        BinaryTree() {}

        void PreOrder(Node* node) {
            if(node == NULL)
                return;
            
            std::cout << node->data << std::endl;
            PreOrder(node->left);
            PreOrder(node->right);
        }

        void InOrder(Node* node) {
            if(node == NULL)
                return;
            
            InOrder(node->left);
            std::cout << node->data << std::endl;
            InOrder(node->right);
        }

        void PostOrder(Node* node) {
            if(node == NULL)
                return;

            PostOrder(node->left);
            PostOrder(node->right);
            std::cout << node->data << std::endl;
        }

        BinaryTree create() {
            BinaryTree tree = BinaryTree();
            
            root = new Node(40);
        
            tree.root = root;
            tree.root->left = new Node(20);
            tree.root->left->left = new Node(10);
            tree.root->left->left->left = new Node(5);   
            tree.root->left->right = new Node(30);
            tree.root->right = new Node(50);
            tree.root->right->right = new Node(60);
            tree.root->left->right->left = new Node(67);
            tree.root->left->right->right = new Node(78); 
            
            return tree;
        } 
};

int main(){
    BinaryTree tree = BinaryTree();
    
    tree.create();

    // tree.PreOrder(tree.root);
    // tree.InOrder(tree.root);
    tree.PostOrder(tree.root);

    return 0;
}