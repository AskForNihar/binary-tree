#include<iostream.h>
#include<conio.h>
class tree
{
	struct node
	{
		int info;
		struct node *left;
		struct node *right;
	}*root;
	tree()
	{
		root=NULL;
	}
	node *create_node();
	void insert_at_end();
	int pre_order(struct node *temp);
	int post_order(struct node *temp);
	int inorder(struct node *temp);
};
node *tree :: create_node()
{
	struct node *temp;
	int ele;
	temp = new(struct node);
	cout<<"Enter value to be stored"<<endl;
	cin>>ele;
	if(temp == NULL)
	{
		cout<<"Insufficient Memory"<<endl;
		return 0;
	}
	else
	{
		cout<<"\n Node created successfully"<<endl;
		temp -> info = ele;
		temp -> left = NULL;
		temp -> right = NULL;
		if(root == NULL)
		{
			root = temp;
			root -> left = NULL;
			root -> right = NULL;
		}
		return temp;
	}
}
int tree :: pre_order(struct node *temp)
{
	cout<<"\t"<<temp -> info;
	if(temp -> left != NULL)
	{
		pre_order(temp -> left);
	}
	//else
	  //	return 0;
	if(temp -> right != NULL)
	{
		pre_order(temp -> right);
	}
	//else
	    //	return 0;
}
int tree :: post_order(struct node *temp)
{

	if(temp -> left != NULL)
	{
		post_order(temp -> left);
	}
	if(temp -> right != NULL)
	{
		post_order(temp -> right);
	}
	cout<<"\t"<<temp -> info;
}
int tree :: inorder(struct node *temp)
{

	if(temp -> left != NULL)
	{
		inorder(temp -> left);
	}
	//else
	  //	return 0;
	cout<<"\t"<<temp -> info;
	if(temp -> right != NULL)
	{
		inorder(temp -> right);
	}
	//else
	  //	return 0;

}


void tree :: insert_at_end()
{
	struct node *temp, *temp1;
	temp = root;
	int cntr = 0, opt;
	while(cntr == 0)
	{
		cout<<"Please choose"<<endl;
		cout<<"1. For adding as left child of "<<temp -> info <<endl;
		cout<<"2. for adding as right child of "<<temp -> info <<endl;
		cin>>opt;
		if(opt == 1)
		{
			if(temp -> left == NULL)
			{
				temp1 = create_node();
				temp -> left = temp1;
				cntr++;
			}
			else
			{
				temp = temp -> left;
			}
		}
		else if(opt == 2)
		{
			 if(temp -> right == NULL)
			{
				temp1 = create_node();
				temp -> right = temp1;
				cntr++;
			}
			else
			{
				temp = temp -> right;
			}
		}
		else
		{
			cout<<"Enter a valid number"<<endl;
		}
	}
}
void main()
{
	int opt, op;
	clrscr();
	tree t1;
	starts:
	cout<<"\n Please choose"<<endl;
	cout<<"1. For creating a new node"<<endl;
	cout<<"2. For Inserting an element in the binary tree"<<endl;
	cout<<"3. For performing Pre-Order traversal"<<endl;
	cout<<"4. For performing Post-Order traversal"<<endl;
	cout<<"5. For performing Inorder traversal"<<endl;
	cin>>opt;
	switch(opt)
	{
		case 1:
			t1.create_node();
		break;
		case 2:
			t1.insert_at_end();
		break;
		case 3:
			t1.pre_order(t1.root);
		break;
		case 4:
			t1.post_order(t1.root);
		break;
		case 5:
			t1.inorder(t1.root);
		break;
		default:
			cout<<"Invalid option. Please choose a valid option"<<endl;
	}
	cout<<"\n Do you wish to continue?"<<endl;
	cout<<"1. Yes"<<endl;
	cout<<"2. No"<<endl;
	cin>>op;
	if(op == 1)
		goto starts;
	else
		goto exit;
	exit:
	getch();
}

