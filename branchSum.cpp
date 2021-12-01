#include<iostream>
#include<vector>
using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

void SumWhileTraverse(BinaryTree *node, int currentSum, vector<int> &sums){
	if(node == NULL)
		return;
	
	int auxSum = currentSum + node->value;
	if(node->left == NULL && node->right == NULL)
		sums.push_back(auxSum);
	
	SumWhileTraverse(node->left, auxSum, sums);
	SumWhileTraverse(node->right, auxSum, sums);
}

vector<int> BranchSums(BinaryTree *root) {
	vector<int> listSums;
	SumWhileTraverse(root, 0, listSums);
	return listSums;
}

void Output(BinaryTree* tree){
    cout << "[";
    for(int i : BranchSums(tree))
        cout << " " <<  i << " ";
    cout << "]";
}

int main(){
    BinaryTree* tree = new BinaryTree(1);
    tree->left = new BinaryTree(2);
    tree->left->left = new BinaryTree(4);
    tree->left->right = new BinaryTree(5);
    tree->left->left->left = new BinaryTree(8);
    tree->left->left->right = new BinaryTree(9);
    tree->left->right = new BinaryTree(5);
    tree->left->right->left = new BinaryTree(10);
    tree->right = new BinaryTree(3);
    tree->right->right = new BinaryTree(7);
    tree->right->left = new BinaryTree(6);

    Output(tree);
    return 0;
}