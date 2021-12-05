#include "STD_Types.h"
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

typedef struct Node_type node;

struct Node_type{
	u32 ID ;
	u8 NAME[20];
	u32 AGE ;
	u8 GENDER[6];
	u32 Res;
    node *Next;
};

u32 RES[5]={0,0,0,0,0};

void AddNode(void);
void PrintLinkedList(void);
void Edit(void);
void Reserve(void);
void Cancel(void);
void Display(void);
void Today(void);


u32 ListLength = 0;
node head;

void main(void)
{
	u32 input;
	u32 Mode;
	u32 passward=0;
	u32 exitflag = 0;
	while (exitflag==0) 
	{
		printf(" Enter Mode : \n\n1 for Admin \n\n2 For USER : ");
		scanf("%d",&Mode);
		while (Mode == 1 )
		{
		if (passward !=1234)
		{
		printf ("\nplease enter your admin password ");
		scanf("%d",&passward);
		if (passward==1234)
		{
		break;	
		}
		else
		{
			printf("\n Wrong Passward");
		}
		}
		else if (passward==1234)
		{
		printf("---------------- YOU'RE IN ADMIN MODE -------------");
		printf("\nTo add node enter 0\n");
		printf("To print the linked list enter 1 : \n");
		printf("Edit patient info 2 : \n");
		printf("For Reservation press 3 : \n");
		printf("To Cancel Reservation press 4 : \n");
		printf("To Exit enter 5 : \n");
		printf("Your Choice:  ");
		scanf("%d",&input);
		switch (input)
		{
			case 0 : AddNode(); break;
			case 1 : PrintLinkedList(); break;
			case 2 : Edit(); break ;
			case 3 : Reserve(); break;
			case 4 : Cancel() ; break;
			case 5 : printf("Thank You\nGood Bye\n");passward=0; Mode = 0 ;break;
			default: printf("enter right input\n");break ;
		}
		}
		
		}
		while(Mode == 2)
		{
			printf("---------------- YOU'RE IN USER MODE -------------");
			printf("\nTo view patient record enter     : 0\n");
			printf("To view today's reservations enter : 1 \n");
			printf("To Exit enter 2 : \n");
			scanf("%d",&input);
			switch(input)
			{
				case 0 :Display();break;
				case 1 :Today();break;
				case 2 :Mode = 0;break;
				default:printf("enter right input\n");break ;
			}		
		}
	}
	
}


void AddNode(void)
{
	u32 id ;
	u32 age ;
	

	 
	
	
	
	printf("\nenter id : ");
	scanf("%d",&id);
	if(id != head.ID )
	{
	
	if (ListLength == 0)
	{
		
	printf("\nenter name : ");
	scanf("%s",&head.NAME);
	
	
	printf("\nenter age : ");
	scanf("%d",&age);
	
	printf("\nenter gender : ");
	scanf("%s",&head.GENDER);
	
		head.ID = id ;
		head.AGE = age ;
		head.Next  = NULL; 
	}
	
	
	
	else
	{
		
		node* last;
		node *new = (node*) malloc(sizeof(node));
		

		new->Next  = NULL;
		
		last = &head;
		
		
		
		while( (last -> Next) != NULL  )
		{
			if(last->ID != id)
			{
			last = (last -> Next);
			}
			else
			{
				printf("\nalready exists\n\n");
				break;
			}
		}
		if (last-> ID != id )
		{
		last -> Next = new;
				
		printf("\nenter name : ");
		scanf("%s",&new->NAME);
		
		
		
	
		printf("\nenter age : ");
		scanf("%d",&age);
	
		printf("\nenter gender : ");
		scanf("%s",&new->GENDER);
		new->ID = id ;
		new->AGE = age ;
		new->Res = 0 ;
		}
		else 
		{
			printf("already exists");
		}

	}


	/* Increase the list length by one node */
	ListLength++;
	printf("\n\n\n");
	}
	else{printf(" ID Already Exists\n\n");}
	
	
	return;
}

void PrintLinkedList(void)
{
	printf("\n\n----------------------\n");
	/* at lease 1 node is created */
	if (ListLength > 0)
	{
		node *Last = &head;
		u32 i = 1;
		
		/* Print the list head */
		printf("ID Number     %d     = %d\n", i,Last -> ID);
		printf("name Number   %d     = %s\n", i,Last -> NAME);
		printf("age Number    %d     = %d\n", i,Last -> AGE);
		printf("gender Number %d     = %s\n", i,Last -> GENDER);
		printf("Res Number    %d     = %d\n\n\n", i,Last -> Res);

		
		while ((Last -> Next) != NULL)
		{
			i++;
		Last = Last -> Next;
		printf("ID Number     %d     = %d\n", i,Last -> ID);
		printf("NAME Number   %d     = %s\n", i,Last->NAME);
		printf("Age Number    %d     = %d\n", i,Last -> AGE);
		printf("gender Number %d     = %s\n", i,Last -> GENDER);
		printf("Res Number    %d     = %d\n\n\n", i,Last -> Res);
		
		}
	}
	
	else
	{
		printf("List is Empty\n");
	}
	
	printf("----------------------\n\n\n");
}

void Edit (void)
{
	node* ptr ;
	ptr = &head ;
	u32 Id;
	printf("enter ID you want to edit ");
	scanf("%d",&Id);
	for (u32 i = 0 ;;i++)
	{
		if(ptr->ID !=Id & ptr ->Next != NULL)
		{
		ptr=ptr->Next ; 	
		}
		else if (ptr ->ID == Id)
		{
		u32 age ;
		u32 gender; 
		printf("\nedit name :  ");
		scanf("%s",&ptr->NAME);
		printf("\nedit age : ");
		scanf("%d",&age);
		printf("\nedit gender : ");
		scanf("%s",&ptr->GENDER);
		ptr -> AGE = age ;
		printf("patient info is updated \n\n");
		break;		
		}
		else 
		{
			printf(" doesnt exist \n\n");
			break;
		}
	}
	
		
}
	
void Reserve(void)
{
	node* ptr ;
 	ptr = &head ;
	u32 app ;
	u32 id ;
	printf("available appointments are : \n 1 for 2:00-2:30 \n 2 for 2:30-3:00 \n 3 for 3:00-3:30 \n 4 for 3:30-4:00 \n 5 for 4:00-4:30\n\n ");
for(u32 i = 0; i<5;i++)
{
	if(RES[i] == 0 )
	{
		printf ( "%d     ",i+1);
	}
}
printf("enter id you want to reserve : ");
scanf("%d",&id);

for (u32 i = 0 ;;i++)
	{
		if(ptr->ID !=id & ptr ->Next != NULL)
		{
		ptr=ptr->Next ; 	
		}
		else if (ptr ->ID == id)
		{
		if(ptr->Res==0)
		{
		printf("enter the appointment you want to reserve : ");
		scanf("%d",&app);
		if(app <=5 && RES[app-1] == 0)
		{
		ptr->Res = app;
		RES[app-1]= 1;
    	break;
		}
		else
		{
			printf("wrong appointment ");
		}
		}
		else 
		{
			printf("already reserved ");
			break;
		}
		}
		else 
		{
			printf(" ID doesnt exist \n\n");
			break;
		}
	}
	}
	

void Cancel(void)
{
	node * ptr;
	ptr =&head;
	u32 id ;
	printf(" Enter the ID you want to cancel : ");
	scanf("%d",&id);
	for (u32 i = 0 ;;i++)
	{
		if(ptr->ID !=id & ptr ->Next != NULL)
		{
		ptr=ptr->Next ; 	
		}
		else if (ptr ->ID == id)
		{
		RES[ptr->Res-1]=0;
		ptr->Res = 0 ;
		break;
		}
		else 
		{
			printf(" ID doesnt exist \n\n");
			break;
		}	
	}
}

void Display(void)
{
	node * ptr;
	ptr =&head;
	u32 id ;
	printf(" Enter the ID you want to display : ");
	scanf("%d",&id);
	for (u32 i = 0 ;;i++)
	{
		if(ptr->ID !=id & ptr ->Next != NULL)
		{
		ptr=ptr->Next ; 	
		}
		else if (ptr ->ID == id)
		{
		printf("\nID Number        %d    = %d\n" ,  i+1 ,ptr-> ID);
		printf("name Number        %d    = %s\n", i+1,ptr -> NAME);
		printf("age Number         %d    = %d\n", i+1,ptr -> AGE);
		printf("gender Number      %d    = %s\n", i+1,ptr -> GENDER);
		printf("appointment number %d    = %d\n\n\n", i+1,ptr -> Res);

		break;
		}
		else 
		{
			printf(" ID doesnt exist \n\n");
			break;
		}	
	}
}
void Today (void)
{
{
	printf("\n\n----------------------\n");
	if (ListLength > 0)
	{
		node *Last = &head;
		u32 i = 1;
		if (Last -> Res > 0 )
		{
			if (Last -> Res != 0)
			{
		printf("ID Number %d     = %d\n", i,Last -> ID);
		printf("Res Number %d    = %d\n\n\n", i,Last -> Res);
			}
		}
		
		while ((Last -> Next) != NULL)
		{
		i++;
		Last = Last -> Next;
		if (Last -> Res != 0)
		{
		printf("ID Number %d     = %d\n", i,Last -> ID);
		printf("Res Number %d    = %d\n\n\n", i,Last -> Res);
		}
		}
	}
	
	else
	{
		printf("List is Empty\n");
	}
	
	printf("----------------------\n\n\n");
}
}
	








