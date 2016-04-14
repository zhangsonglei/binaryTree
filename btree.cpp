#include<iostream>
using namespace std;
                                                // 二叉树类型的定义(二叉链表形式储存) 
typedef char datatype;                          // 树的结点数据类型为字符型，可以根据需要修改
typedef struct node *pointer;                   // 定义二叉树结点类型
struct node {
	datatype data;                              //结点数据
	pointer lchild,rchild;                      //左右孩子结点
};

typedef pointer bitree;                         //定义二叉树类型
                                                //先根遍历交换左右子树 
                                                // 层次遍历序列生成 
const int maxsize=100;
pointer Q[maxsize+1];

bitree level_creat()                            //由层次序列建立二叉树，返回根指针
{
	char ch;
	int front,rear;
	pointer root,s;
	root=NULL;                                  //置空二叉树	
	front=rear=0;                               //置空队列
	while(cin>>ch,ch!='#')
	{
		if(ch!='@')                             //非虚结点，建立新结点
		{
			s=new node;
			s->data=ch;
			s->lchild=s->rchild=NULL;
		}
		else s=NULL;
			rear++;
		Q[rear]=s;                              //不管结点是否为虚都要入队
		if(rear==1)
		{
			root=s;
			front=1;
		}                                       //第一个点是根，要修改头指针，他不是孩子
		else if(s && Q[front])                  //孩子和双亲都不是虚结点
				if(rear%2==0) 
					Q[front]->lchild=s;         // rear是偶数，新结点是左孩子
		else 
		{
			Q[front]->rchild=s;                 //rear 是奇数，新结点是右孩子
			front++;
		}
	}
	return root;
}
                                               // 交换左右子数 
void exchange(bitree t) 
{
	pointer p;
	if(t==NULL) 
		return;                                //空树，直接返回
	p=t->lchild; 
	t->lchild=t->rchild; 
	t->rchild=p;                               //交换
	exchange(t->rchild);                       //遍历原左子树
	exchange(t->lchild);                       //遍历原右子树
}
                                               // 二叉树的先根遍历 
void preorder(bitree t)                        //先根遍历
{
	if(t==NULL) 
		return; 
	
	cout<<t->data<<" ";                        //先访问跟
	preorder(t->lchild);                       //先根遍历左子树
	preorder(t->rchild);                       //先根遍历右子树
}
                                               // 二叉树的中序遍历 
void midorder(bitree t)                        //中序遍历
{
	if(t==NULL) 
		return; 
	
	midorder(t->lchild);                       //先根遍历左子树
	cout<<t->data<<" ";                        //先访问跟
	midorder(t->rchild);                       //先根遍历右子树
}
                                               // 二叉树的后序遍历 
void behorder(bitree t)                        //后序遍历
{
	if(t==NULL) 
		return;
	
	behorder(t->lchild);                      //先根遍历左子树
	behorder(t->rchild);                      //先根遍历右子树
	cout<<t->data<<" ";                       //先访问跟
}

void main()
{
	bitree T=NULL;
	int ch;
	cout<<"首先层次遍历序列生成二叉树，请输入结点数据(输入'@'为虚结点，输入'#'结束):\n";
	T=level_creat();
	if(T==NULL) 
		cout<<"二叉树生成失败!\n";
	else cout<<"二叉树生成成功!\n";

AA: do{
		cout<<" \t\t----------------------菜单--------------------\n"
		<<" \t\t\t\t0.退出\n"
		<<" \t\t\t\t1.重新建立二叉树\n"
		<<" \t\t\t\t2.交换左右子数\n"
		<<" \t\t\t\t3.前序遍历二叉树\n"
		<<" \t\t\t\t4.中序遍历二叉树\n"
		<<" \t\t\t\t5.后序遍历二叉树\n"
		<<" \t\t----------------------------------------------\n";
		cout<<" 请选择：";
		cin>>ch;
		system("cls");
		switch(ch)
		{
			case 0: 
				break;
			case 1: 
				T=level_creat(); 
				cout<<"二叉树生成成功!\n"; 
				break;
			case 2: 
				exchange(T); 
				cout<<" 交换成功!\n"; 
				break;
			case 3: 
				cout<<"前序遍历的结果为:";
				preorder(T); 
				cout<<endl; 
				break;
			case 4: 
				cout<<"中序遍历的结果为:";
				midorder(T); 
				cout<<endl;
				break;
			case 5: 
				cout<<"后序遍历的结果为:";
				behorder(T); 
				cout<<endl; 
				break;
			default: cout<<"您输入错误!请重新输入"; goto AA;
		}
	}
	while(ch!=0);
}