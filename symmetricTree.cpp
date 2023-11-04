#include <bits/stdc++.h>

using namespace std;

template <typename T = int>
class TreeNode
{
public:
T data;
TreeNode<T> *left;
TreeNode<T> *right;

TreeNode(T data)
{
this->data = data;
left = NULL;
right = NULL;
}

~TreeNode()
{
if (left != NULL)
{
delete left;
}
if (right != NULL)
{
delete right;
}
}
};

bool isSymmetricHelper(TreeNode<int>* root1,TreeNode<int> *root2){
	if(root1 == NULL || root2 == NULL) return root1 == root2;
	if(root1->data != root2->data) return false;
	bool l = isSymmetricHelper(root1->left,root2->right);
	bool h = isSymmetricHelper(root1->right,root2->left);
	if(!l || !h) return false;
	return true;
}

bool isSymmetric(TreeNode<int>*root){
	if(root == NULL) return true;
	return isSymmetricHelper(root->left,root->right);
}



class Runner
{
TreeNode<int> *treeRoot;
TreeNode<int> *treeRoot2;

TreeNode<int> *takeTreeInput()
{
int rootData;
cin >> rootData;

if (rootData == -1)
{
return NULL;
}

TreeNode<int> *root = new TreeNode<int>(rootData);

queue<TreeNode<int> *> q;
q.push(root);

while (q.empty() == false)
{
TreeNode<int> *currentNode = q.front();
q.pop();
int leftChild, rightChild;

cin >> leftChild;

if (leftChild != -1)
{
TreeNode<int> *leftNode = new TreeNode<int>(leftChild);

currentNode->left = leftNode;
q.push(leftNode);
}

cin >> rightChild;

if (rightChild != -1)
{
TreeNode<int> *rightNode = new TreeNode<int>(rightChild);

currentNode->right = rightNode;
q.push(rightNode);
}
}

return root;
}

TreeNode<int> *copyTree(TreeNode<int> *root)
{
if (root == NULL)
{
return NULL;
}
TreeNode<int> *copyRoot = new TreeNode<int>(root->data);
copyRoot->left = copyTree(root->left);
copyRoot->right = copyTree(root->right);
return copyRoot;
}
public:
void takeInput()
{
treeRoot = takeTreeInput();
treeRoot2 = takeTreeInput();
}

void execute()
{
TreeNode<int> *copyRoot = copyTree(treeRoot);

// Get the answer from scaffold/solution
auto ans = isSymmetric(copyRoot);

// We are done with current copy root so we can delete it.
delete copyRoot;
}

void executeAndPrintOutput()
{
TreeNode<int> *copyRoot = copyTree(treeRoot);

// Get the answer from scaffold/solution
auto ans = isSymmetric(copyRoot);	
cout << ans << "\n";

// We are done with current copy root so we can delete it.
delete copyRoot;
}
};

int main()
{
Runner runner;
runner.takeInput();
runner.executeAndPrintOutput();

return 0;
}
