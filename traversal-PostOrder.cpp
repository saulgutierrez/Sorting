#include <iostream>
#include <conio.h>
using namespace std;
void postOrder(int[][10], int);
int main()
{
    int nodes, tree[10][10], x, y, root = 1;
    cout << "Please input the number of nodes : ";
    cin >> nodes;
    cout << "Please input the left-right child array representation of the graph :";
    for (int i = 1; i <= nodes; i++)
    {
        cin >> x;
        cin >> y;
        tree[i][0] = x;
        tree[i][1] = y;
    }

    cout << endl
         << "Post-order traversal is :" << endl;
    postOrder(tree, root);
    getch();
    return 0;
}

//Post order traversal functiom

void postOrder(int tree[10][10], int root)
{

    if (root == 0)
        return;

    //left child
    if (tree[root][0] != 0)
        postOrder(tree, tree[root][0]);

    //right child
    if (tree[root][1] != 0)
        postOrder(tree, tree[root][1]);

    cout << root << "\t";
}

