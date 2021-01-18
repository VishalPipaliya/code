#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}
// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/

Node *createBST(Node *root, int data) {

    if (!root)
        return new Node(data);

    if (root->data > data)
        root->left = createBST(root->left, data);

    else
        root->right = createBST(root->right, data);

    return root;
}

Node *constructTree (int post[], int size) {

    Node *root = nullptr;

    for (int i = size - 1; i >= 0; --i)
        root = createBST(root, post[i]);

    return root;
}
