#include <vector>
#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

struct Node* newNode(int value){
	struct Node* node = new Node();
	node->data = value;
	node->left = nullptr;
	node->right = nullptr;
}

void TraverseTree(Node* node, vector<int>& result){
	if(node == nullptr)
		return;
	TraverseTree(node->left, result);
	TraverseTree(node->right, result);
	result.push_back(node->data);
}

vector<int> GetRemovalSequence(Node* root){
	vector<int> result;
	
	if(root == nullptr)
		return result;

	TraverseTree(root, result);
}

//      1
//    /   \
//   2     3
//  /
// 4

// 4 -> 3 -> 2 -> 1
int main(){
	auto root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);

	auto result = GetRemovalSequence(root);

	for(auto item : result){
		cout << " [" << item << "] ";
	}

	return 0;
}
