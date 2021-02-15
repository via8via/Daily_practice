#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
} Link ;

int main()
{
	Link *CreateList(Link * head,int num);//�������� 
	void PrintfLink(Link* link);//��� 
	Link *InsertElement(Link *link,int insertNum,int n);//���� 
	Link *DeleteElement(Link *link, int n); //ɾ�� 
	
	Link *head =NULL,*ins,*del;
	int insertNum,deleteNum ,n;
	
    head = CreateList(head,10);
    printf("����Ϊ��"); 
    PrintfLink(head);
    
    printf("\n");
    
    printf("�������ĸ��������:");
    scanf("%d",&n);
    printf("������������");
    scanf("%d",&insertNum);
    ins =  InsertElement(head,insertNum, n);
    PrintfLink(ins);
    
    printf("\n");
     
    printf("������Ҫɾ������:");
    scanf("%d",&deleteNum);
    del = DeleteElement(head, deleteNum);
    PrintfLink(del);
}


Link *CreateList(Link * head,int num)  
{
	Link *knot1,*temp1;
	int i;
	
	for(i=1;i<=num;i++)
	{
		knot1=(Link*)malloc(sizeof(Link));
		if(head == NULL)
		{
			knot1->data = i;//����������ֵ 
		    head = knot1;//head ���������ͷָ���һ���ڵ㣬 
		}
		else
		{
			knot1->data = i;
			temp1->next = knot1; // ���ÿ�δ����Ľڵ��ַ 
		}
		temp1 = knot1; //temp1 ָ��ÿ�δ����Ľڵ� 	
	}
	knot1->next = NULL;//���һ����ַָ��NULL 
	return head; 	
}

void PrintfLink(Link* link)
{
	while(link)
	{
    	printf("->%d",	link->data);
    	link=link->next;
	}
	printf("\n");
}

Link *InsertElement(Link *link,int insertNum,int n)
{
	Link *head,*knot2;
	head = link; //����Ƿ����������������������  
	
	knot2 = (Link*)malloc(sizeof(Link));
	knot2->data = insertNum;
	
	while(link != NULL && link->data != n)  //Ѱ�Ҳ����λ�� 
	{
		link=link->next;
	 } 	
	//�ҵ������λ�ú󣬰Ѵ����һ���ڵ�ĵ�ַ���½ڵ㣬��ԭ���Ľڵ����½ڵ��ַ������ɲ��� 
	knot2->next = link->next;       
	link->next = knot2;
	
	 return head;
	
 } 
 
 
Link *DeleteElement(Link *link, int n)
 {
 	Link *head,*knot3;
 	
	head =knot3 =link;

 	while(link != NULL)
	 {
	 	if(link->data == n) 
	 	{
		 	if( head == link) //���ɾ���Ľڵ��ǵ�һ��
		 	{
		 		link =link->next;  //ָ��ڶ����ڵ� 
		 		free(knot3);  //ɾ���ڵ� 
		 		head = link; // ��head ָ������ڵ㣬���������ӡ����� 
			}
			else
			{
				knot3->next = link->next;  //  ��Ҫɾ���Ľڵ����ŵĵ�ַ��ǰһ�� 
				free(link);
				link =knot3->next;	  
			}	
		 }
		else
		{
			knot3 =link; //��һ���������һ�������˵����ŵ���ǰһ���ڵ�ĵ�ַ�� 
			link =link->next; //�Ʋ���һ���ڵ� 	
		}
	 	
	} 
	return head; 
 }
