#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node* next;
};


void print_list(struct node*head)
{
  while(head!= NULL){
  	printf("%d\n", head->item);
  	head = head->next;
  }
}

void insert_node(struct node *head, struct node *newnode, struct node *prevnode){
	
	if(prevnode == NULL){
		head = newnode;
		return;
	}
	struct node* tmp = prevnode -> next;
	prevnode -> next = newnode;
	newnode -> next = tmp;
}


void delete_node(struct node *head, struct node *delnode){
	struct node* count = head;
	while(count != NULL){
		if(count -> next == delnode){
			count -> next = delnode -> next;
			break;
		}
		
		count = count -> next;
	}
}


int main()
{
    struct node *firstNode, *secondNode, *thirdNode, *fourthNode;

    firstNode = malloc(sizeof(struct node));
    secondNode = malloc(sizeof(struct node));
    thirdNode = malloc(sizeof(struct node));
    fourthNode = malloc(sizeof(struct node));

   firstNode -> item = 1;
   secondNode -> item = 2;
   thirdNode -> item = 3;
   fourthNode -> item = 4;

    insert_node(NULL, firstNode, NULL);
    insert_node(firstNode, secondNode, firstNode);
    insert_node(firstNode, thirdNode, secondNode);
	
	printf("Initial structure: \n");
    print_list(firstNode);

    insert_node(firstNode, fourthNode, secondNode);

	printf("Insert node after node2: \n");
    print_list(firstNode);
    
    delete_node(firstNode,secondNode);
    printf("Delete node2: \n");
    print_list(firstNode);
}
