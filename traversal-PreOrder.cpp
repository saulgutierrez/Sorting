#include <iostream>
#include <conio.h>
using namespace std;
// function Prototype
void preOrder(int[10][10], int);
int main()
{
    int nodes, tree[10][10], x, y, root = 1;
    cout << "Please input the number of nodes : ";
    cin >> nodes;
    cout << "Please input the left-right child array representation of the tree/graph :";
    for (int i = 1; i <= nodes; i++)
    {
        cin >> x;
        cin >> y;
        tree[i][0] = x; // tree[1][0] left child of node 1
        tree[i][1] = y;//tree[1][1] right child of 1 
    }
    cout << "Pre-order traversal is :" << endl;
    preOrder(tree, root);
    getch();
    return 0;
}

//Pre order traversal function

void preOrder(int tree[10][10], int root) 
{
    if (root == 0)
        return;

    cout << root << "\t"; // 1

    //Left Child
    if (tree[root][0] != 0) // tree[1][0] != 0 value = 2
        preOrder(tree, tree[root][0]);

    //Right Child
    if (tree[root][1] != 0) // tree[1][1] = 3
        preOrder(tree, tree[root][1]);
}

