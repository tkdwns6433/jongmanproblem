
#define RED 0;
#define BLACK 1;
typedef int Color;

struct Node
{
	Color color;
	int key;
	Node *left;
	Node *right;
	Node *p;
};

struct RedBlackTree
{
	Node *root;
	Node *nil;
};

void left_rotate(RedBlackTree T, Node *x)
{
	Node* y = x->right;
	x->right = y->left;
	if (y->left != T.nil)
	{
		y->left->p = x;
	}
	y->p = x->p;
	if (x->p == T.nil)
	{
		T.root = y;
	}
	else if (x == x->p->left)
	{
		x->p->left = y;
	}
	else
	{
		x->p->right = y;
		y->left = x;
		x->p = y;
	}
}

void right_rotate(RedBlackTree T, Node *x)
{
	Node* y = x->left;
	x->left = y->right;
	if (y->right != T.nil)
	{
		y->right->p = x;
	}
	y->p = x->p;
	if (x->p == T.nil)
	{
		T.root = y;
	}
	else if (x == x->p->right)
	{
		x->p->right = y;
	}
	else
	{
		x->p->left = y;
		y->right = x;
		x->p = y;
	}
}
