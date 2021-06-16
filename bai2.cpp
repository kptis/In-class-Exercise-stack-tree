#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

// Cac function cho cau a, bai2
void quickSort(int a[], int l, int r) //Sap xep day khong giam
{
    int p = a[(l + r) / 2];
    int i = l, j = r;
    while (i < j)
    {
        while (a[i] < p)
        {
            i++;
        }
        while (a[j] > p)
        {
            j--;
        }
        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (i < r)
    {
        quickSort(a, i, r);
    }
    if (l < j)
    {
        quickSort(a, l, j);
    }
}

void ghiFileOutput(int a[], int sophantu)
{
    FILE *fo = fopen("output21.txt", "w");
    if (fo == NULL)
    {
        printf("\nKhong mo duoc file!");
        // getch();
        exit(0);
    }
    for (int i = 0; i < sophantu; i++)
    {
        fprintf(fo, "%d ", a[i]);
    }
    fprintf(fo, "\n");
    fclose(fo);
}
void xuLyFileInput(int a[], int sophantu)
{
    FILE *fi = fopen("input2.txt", "r");

    for (int j = 0; j < sophantu; j++)
    {
        fscanf(fi, "%d", &a[j]);
    }

    quickSort(a, 0, sophantu - 1);
    ghiFileOutput(a, sophantu);

    fclose(fi);
}
int sophantu()
{
    FILE *fi = fopen("input2.txt", "r");
    int a;
    int sophantu = 0;
    while (!feof(fi))
    {
        fscanf(fi, "%d", &a);
        sophantu++;
    }
    // printf("%d", sophantu);
    fclose(fi);
    return sophantu;
}

// functions for Ex2b
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;

} node;

typedef struct binarySearchTree
{
    node *root;
} bst;

// Create new node
node *newNode(int data)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    return n;
}

//  create new tree
bst *newBinaryTree()
{
    bst *t = (bst *)malloc(sizeof(bst));
    t->root = NULL;
    return t;
}

node *insert(node *newnode, int key)
{
    // Return a new node if the tree is empty
    if (newnode == NULL)
        return newNode(key);

    // Traverse to the right place and insert the node
    if (key < newnode->data)
        newnode->left = insert(newnode->left, key);
    else
        newnode->right = insert(newnode->right, key);

    return newnode;
}
void levelOrder(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    FILE *fo1 = fopen("output22.txt", "a");
    if (fo1 == NULL)
    {
        fprintf(stderr, "Cannot open output22.txt");
        perror("Because:");
        fclose(fo1);
        return;
    }
    //while there is at least one discovered node
    while (!q.empty())
    {
        node *current = q.front();
        printf("%d ", current->data);
        fprintf(fo1, "%d ", current->data);
        if (current->left != NULL)
        {
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            q.push(current->right);
        }
        q.pop();
        //remove the element at front
    }
    fclose(fo1);
}

void inorder(bst *t, node *n)
{
    if (n == NULL)
    {
        return;
    }
    inorder(t, n->left);
    printf("%d\t", n->data);
    inorder(t, n->right);
}

int main()
{
    int n = sophantu();
    int a[n];
    xuLyFileInput(a, n);
    // FILE *fi = fopen("input2.txt", "r");

    // for (int j = 0; j < sophantu(); j++)
    // {
    //     fscanf(fi, "%d", &a[j]);
    // }
    // fclose(fi);
    //cau2 b

    // xay dung cay nhi phan tu mang so doc duoc tu file 
    bst *t = newBinaryTree();
    t->root = insert(t->root, a[7]);
    for (int i = 1; i < n; i++)
    {
        if (i != 7)
        {
            t->root = insert(t->root, a[i]);
        }
    }

    levelOrder(t->root);
    return 0;
}