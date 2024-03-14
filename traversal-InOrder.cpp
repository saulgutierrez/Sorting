#include <iostream>
#include <conio.h>
using namespace std;
void inorder(int[][10], int);
int main()
{
    int nodes, tree[10][10], x, y, root = 1;
    cout << "Please input the number of nodes : ";
    cin >> nodes;
    cout << "Please input the left-middle-right child array representation of the graph :";
    for (int i = 1; i <= nodes; i++)
    {
    	
        cin >> x;
        cin >> y;
        tree[i][0] = x; //left child 
        tree[i][1] = y; // right child
    }
    cout << endl
         << "Inorder traversal is :" << endl;
    inorder(tree, root);
    getch();
    return 0;
}

//Inorder traversal function

void inorder(int tree[10][10], int root)
{
	if(root == 0)
		return;
    //left child
    if (tree[root][0] != 0)  // tree[1][0] = 2  , // tree[2][0] = 0
        inorder(tree, tree[root][0]);

	// Root
    cout << root << "\t"; // 2

    //right child
    if (tree[root][1] != 0) // tree[2][1]= 4
        inorder(tree, tree[root][1]);
}

