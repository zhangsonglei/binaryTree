#include<iostream>
using namespace std;
                                                // ���������͵Ķ���(����������ʽ����) 
typedef char datatype;                          // ���Ľ����������Ϊ�ַ��ͣ����Ը�����Ҫ�޸�
typedef struct node *pointer;                   // ����������������
struct node {
	datatype data;                              //�������
	pointer lchild,rchild;                      //���Һ��ӽ��
};

typedef pointer bitree;                         //�������������
                                                //�ȸ����������������� 
                                                // ��α����������� 
const int maxsize=100;
pointer Q[maxsize+1];

bitree level_creat()                            //�ɲ�����н��������������ظ�ָ��
{
	char ch;
	int front,rear;
	pointer root,s;
	root=NULL;                                  //�ÿն�����	
	front=rear=0;                               //�ÿն���
	while(cin>>ch,ch!='#')
	{
		if(ch!='@')                             //�����㣬�����½��
		{
			s=new node;
			s->data=ch;
			s->lchild=s->rchild=NULL;
		}
		else s=NULL;
			rear++;
		Q[rear]=s;                              //���ܽ���Ƿ�Ϊ�鶼Ҫ���
		if(rear==1)
		{
			root=s;
			front=1;
		}                                       //��һ�����Ǹ���Ҫ�޸�ͷָ�룬�����Ǻ���
		else if(s && Q[front])                  //���Ӻ�˫�׶���������
				if(rear%2==0) 
					Q[front]->lchild=s;         // rear��ż�����½��������
		else 
		{
			Q[front]->rchild=s;                 //rear ���������½�����Һ���
			front++;
		}
	}
	return root;
}
                                               // ������������ 
void exchange(bitree t) 
{
	pointer p;
	if(t==NULL) 
		return;                                //������ֱ�ӷ���
	p=t->lchild; 
	t->lchild=t->rchild; 
	t->rchild=p;                               //����
	exchange(t->rchild);                       //����ԭ������
	exchange(t->lchild);                       //����ԭ������
}
                                               // ���������ȸ����� 
void preorder(bitree t)                        //�ȸ�����
{
	if(t==NULL) 
		return; 
	
	cout<<t->data<<" ";                        //�ȷ��ʸ�
	preorder(t->lchild);                       //�ȸ�����������
	preorder(t->rchild);                       //�ȸ�����������
}
                                               // ��������������� 
void midorder(bitree t)                        //�������
{
	if(t==NULL) 
		return; 
	
	midorder(t->lchild);                       //�ȸ�����������
	cout<<t->data<<" ";                        //�ȷ��ʸ�
	midorder(t->rchild);                       //�ȸ�����������
}
                                               // �������ĺ������ 
void behorder(bitree t)                        //�������
{
	if(t==NULL) 
		return;
	
	behorder(t->lchild);                      //�ȸ�����������
	behorder(t->rchild);                      //�ȸ�����������
	cout<<t->data<<" ";                       //�ȷ��ʸ�
}

void main()
{
	bitree T=NULL;
	int ch;
	cout<<"���Ȳ�α����������ɶ�������������������(����'@'Ϊ���㣬����'#'����):\n";
	T=level_creat();
	if(T==NULL) 
		cout<<"����������ʧ��!\n";
	else cout<<"���������ɳɹ�!\n";

AA: do{
		cout<<" \t\t----------------------�˵�--------------------\n"
		<<" \t\t\t\t0.�˳�\n"
		<<" \t\t\t\t1.���½���������\n"
		<<" \t\t\t\t2.������������\n"
		<<" \t\t\t\t3.ǰ�����������\n"
		<<" \t\t\t\t4.�������������\n"
		<<" \t\t\t\t5.�������������\n"
		<<" \t\t----------------------------------------------\n";
		cout<<" ��ѡ��";
		cin>>ch;
		system("cls");
		switch(ch)
		{
			case 0: 
				break;
			case 1: 
				T=level_creat(); 
				cout<<"���������ɳɹ�!\n"; 
				break;
			case 2: 
				exchange(T); 
				cout<<" �����ɹ�!\n"; 
				break;
			case 3: 
				cout<<"ǰ������Ľ��Ϊ:";
				preorder(T); 
				cout<<endl; 
				break;
			case 4: 
				cout<<"��������Ľ��Ϊ:";
				midorder(T); 
				cout<<endl;
				break;
			case 5: 
				cout<<"��������Ľ��Ϊ:";
				behorder(T); 
				cout<<endl; 
				break;
			default: cout<<"���������!����������"; goto AA;
		}
	}
	while(ch!=0);
}