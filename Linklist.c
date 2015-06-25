#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

typedef struct node Node;

Node *head;
Node *tail;

void insert(int);
int fetch(int);
void display(void);
void removee(void);
int main(int argc, char *argv[]) {
	int choice;
	int value;
	int index;
	while(1) {
		printf("What do you want to do?\n\n");
		printf("1. Insert \n2. Fetch \n3. display \n4. Remove\n5. Exit\n");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("\nEnter the value you want to insert!\n");
				scanf("%d", &value);
				insert(value);
				printf("\nInserted the value %d into linkedList\n", value); 
				break;
			case 2:
				printf("\nValue at what index you want to fetch\n");
				scanf("%d", &index);
				value = fetch(index);
				printf("\nValue at index %d is %d\n", index, value); //need to fetch real value
				break;
			case 3:
				
				display();
                break;
            case 4:
            removee();
            break;
           case 5:
                   printf("\nExiting...\n"); 
                  exit(0);   
			default:
				break;
		}
	}
}


void insert(int value) {
	if(head == NULL) {
		head = (Node *)malloc(sizeof(Node));
		head->value = value;
		head->next = NULL;
		tail = head;
	} else {
		tail->next = (Node *)malloc(sizeof(Node));
		tail->next->value = value;
		tail->next->next = NULL;
		tail = tail->next;
	}
}

int fetch(int index) {
    int i;
	if(head == NULL) {
		printf("linklist is empty");
	}
		
	Node *pointer = head;
	for ( i = 0; i < index; i++) {
		if(pointer->next == NULL) {
			return -1;
		}
		pointer = pointer->next;
	}
	
	return pointer->value;
}
void display()
{
    
int i;
     Node *im;
     
    im=head;
    if (head==NULL)
    {
        printf("Linklist is empty\n");
    }
   
    else
    {
        printf ("\n The status of the link list is \n");
       
        
            while(im->next!=NULL)
            {
           
                
                printf ("%d\n",(im->value));
                im=im->next;
                
        
            }
            printf ("%d\n",(im->value));
            return;
        
    }
}
void removee(){
int rem,ind;
printf("condition for removing\n1. By index\n2. By value\n") ;
scanf("%d",&rem);
switch(rem)
{
    case 1:
    printf("At what index u want to remove");
    scanf("%d",&ind);
    rem1(ind);
    
    break;
    case 2:
    printf("What value you want to remove");
    scanf("%d",&ind);
    rem2(ind);
    break;
    default:
    break;
}

   
}
void rem1(ind)
{
  int i;  
if(head == NULL) {
		printf("linklist is empty");
	}
		
	Node *p = head;
    if(ind==0)
    {
        head=p->next;
    }
    else
    {
	for ( i = 1; i < ind; i++) {
		if(p->next == NULL) {
			printf("No. at index not found");
		}
        
        p=p->next;
		
	}
     if(p->next==tail)
    {
        tail=p;
    }
    p->next=p->next->next;
    }
    
    printf("no. at index %d is deleted",ind);
	
	
}	
void rem2(ind)

{
    
     Node *prev=head;
   
    
       if(prev->value == ind)
    {
        
 
            prev = prev->next;
            head=prev;
            return;
    }  
    
     
    while(prev->next != NULL && prev->next->value != ind)
    {
        prev = prev->next;
    }
 
    
    if(prev->next == NULL)
    {
        printf("\n Given node is not present in Linked List");
        return;
        
    }
    if(prev->next==tail)
    {
        tail=prev;
    }
 
    
    prev->next = prev->next->next;
    printf("\n Given node is Removed From Linked List");
    return;
    }