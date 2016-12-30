#include <stdio.h>
#include <stdlib.h>

enum Status
{
	ERROR = 0,
	OK
};
typedef int TElemType;
typedef struct BiTNode {
	TElemType data;
	BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;

static int g_count = 0;

Status CreateBiTree(BiTree& T, TElemType* p);
Status CreateBiTree(BiTree& T, TElemType* p)
{	
	g_count++;
	//p += g_count;
	if (0 == *(p+g_count)){
		T = NULL;
	}
	else{
		T= new BiTNode;
		T->data = *(p + g_count);
		CreateBiTree(T->lchild, p );
		CreateBiTree(T->rchild, p );
		
		return OK;
	}
	//g_count++;
	return ERROR;
}

int main()
{
	// 7 is in front of 6
	int* pTreeVal = new int[16]{111,1,2,3,0,0,4,5,0,7,0,0,6,0,0,0};
	BiTree pBiTree;// = new BiTNode;
	//pBiTree->data = 0;
	//pBiTree->lchild = NULL;
	//pBiTree->rchild = NULL;
	if (CreateBiTree(pBiTree, pTreeVal))
		printf("Create Binary Tree Successful!\n");

	delete[] pTreeVal;
	printf("Hello world!\n");
	system("pause");
	return 0;
}