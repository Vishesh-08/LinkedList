#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
struct Node*head;
void InsertBegin(int x)
{
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=head;
	head=temp;
	}

void InsertBefore(int x,int y)
{
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	struct Node* last=head;
	temp->data=x;
	temp->next=NULL;
	while(last->next->data!=y)
	{
		last=last->next;
	}
	temp->next=last->next;
	last->next=temp;
}
	
void InsertEnd(int x)
{
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	struct Node* last=head;
	temp->data=x;
	temp->next=NULL;
	if(head==NULL)
	head=temp;
	else{
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next=temp;
	}
}

void DeleteHead()
{
	struct Node* temp;
	temp=head;
	head=head->next;
	free(temp);
}

void DeleteBefore(int x)
{
	struct Node* prev=head;
	struct Node* pos=head;
	
	while(pos->next->data!=x)
	{
		prev=pos;
		pos=pos->next;;
	}
	prev->next=pos->next;
	free(pos);
}

void DeleteEnd()
{
	struct Node* prev=NULL;
	struct Node* last=head;
	while(last->next!=NULL)
	{
		prev=last;
		last=last->next;
	}
	prev->next=NULL;
	free(last);	
}
int main()
{
	head=NULL;
	struct Node*first=(struct Node*)malloc(sizeof(struct Node));
	struct Node*second=(struct Node*)malloc(sizeof(struct Node));
	struct Node*third=(struct Node*)malloc(sizeof(struct Node));
	
	head=first;
	first->data=9;
	first->next=second;
	
	second->data=8;
	second->next=third;
	
	third->data=10;
	third->next=NULL;
	
	InsertBegin(5);
	InsertEnd(3);
	InsertBefore(7,second->data);
	DeleteHead();
	DeleteEnd();
	DeleteBefore(third->data);
	struct Node* temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	return 0;
	
}
