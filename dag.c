#include<stdio.h>
#include<stdlib.h> 
typedef struct node
{
	char data;
	struct node *left;
	struct node *right;
} node; 
node *create()
{
	node *p;
	char x;
	printf("Enter data($ for no data):");
	scanf("%s",&x);
    int b=(int)x;
	if(b==36)
		return NULL;
	p=(node*)malloc(sizeof(node));
	p->data=x;
	printf("Enter left child of %c:",x);
	p->left=create();
	printf("Enter right child of %c:",x);
	p->right=create();
	return p;
}
void code_gen(node *t)		//address of root node is passed in t
{
	if(t!=NULL)
	{
        code_gen(t->left);	
        if(t->data!='*'&&t->data!='+'&&t->data!='-'&&t->data!='/')		
        {
            printf("%c,R0\n",t->data);
        }
        else
        {
            switch (t->data)
            {
                case '+':printf("ADD ");break;
                case '-':printf("SUB ");break;
                case '*':printf("MUL ");break;
                case '/':printf("DIV ");break;
            }
        } 
		code_gen(t->right);
	}
}
void inorder(node *t)		
{
	if(t!=NULL)
	{
        inorder(t->left);           
		printf("\n%c",t->data);				
		inorder(t->right);		
	}
}
int main()
{	
	node *root;
	root=create();
    printf("INORDER display:\n");
    inorder(root);
	printf("\nAFter code generation using dag:\nMOV ");
	code_gen(root);	
	return 0;
}