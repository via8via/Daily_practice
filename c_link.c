#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
} Link ;

int main()
{
	Link *CreateList(Link * head,int num);//创建链表 
	void PrintfLink(Link* link);//输出 
	Link *InsertElement(Link *link,int insertNum,int n);//插入 
	Link *DeleteElement(Link *link, int n); //删除 
	
	Link *head =NULL,*ins,*del;
	int insertNum,deleteNum ,n;
	
    head = CreateList(head,10);
    printf("链表为："); 
    PrintfLink(head);
    
    printf("\n");
    
    printf("输入在哪个数后插入:");
    scanf("%d",&n);
    printf("输入插入的数：");
    scanf("%d",&insertNum);
    ins =  InsertElement(head,insertNum, n);
    PrintfLink(ins);
    
    printf("\n");
     
    printf("请输入要删除的数:");
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
			knot1->data = i;//链表数据域赋值 
		    head = knot1;//head 这个变量当头指向第一个节点， 
		}
		else
		{
			knot1->data = i;
			temp1->next = knot1; // 存放每次创建的节点地址 
		}
		temp1 = knot1; //temp1 指向每次创建的节点 	
	}
	knot1->next = NULL;//最后一个地址指向NULL 
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
	head = link; //这个是方便后续在输出函数里输出。  
	
	knot2 = (Link*)malloc(sizeof(Link));
	knot2->data = insertNum;
	
	while(link != NULL && link->data != n)  //寻找插入的位置 
	{
		link=link->next;
	 } 	
	//找到插入的位置后，把存放下一个节点的地址给新节点，让原来的节点存放新节点地址，即完成插入 
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
		 	if( head == link) //如果删除的节点是第一个
		 	{
		 		link =link->next;  //指向第二个节点 
		 		free(knot3);  //删除节点 
		 		head = link; // 让head 指向这个节点，方便后续打印输出。 
			}
			else
			{
				knot3->next = link->next;  //  把要删除的节点里存放的地址给前一个 
				free(link);
				link =knot3->next;	  
			}	
		 }
		else
		{
			knot3 =link; //这一步相对于下一个语句来说，存放的是前一个节点的地址。 
			link =link->next; //移步下一个节点 	
		}
	 	
	} 
	return head; 
 }
