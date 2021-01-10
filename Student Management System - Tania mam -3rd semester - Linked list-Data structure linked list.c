#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct Student
{
    int ID;
    char name[100];
    char phone[100];
    float GPA;
    struct Student *next;
    
}* head;

void insert(int ID, char* name, char* phone, float GPA)
{
	
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
	student->ID = ID;
	strcpy(student->name, name);
	strcpy(student->phone, phone);
	student->GPA= GPA;
	student->next = NULL;
	
	if(head==NULL){
		// if head is NULL
		// set student as the new head
		head = student;
	}
	else{
		// if list is not empty
		// insert student in beginning of head
		student->next = head;
		head = student;
	}
	
}


void update(int ID)
{
	
    struct Student * temp = head;
	while(temp!=NULL){
		
		if(temp->ID==ID){
			printf("Record with ID number %d Found !!!\n",ID);
			printf("Enter new name: ");
			scanf("%s", temp->name);
			printf("Enter new phone number: ");
			scanf("%s", temp->phone);
			printf("Enter new GPA: ");
			scanf("%f",&temp->GPA);
			printf("Updation Successful!!!\n");
			return;
		}
		temp = temp->next;
		
	}
	printf("Student with ID number %d is not found !!!\n", ID);
	
}

void Delete(int ID)
{

    struct Student * temp1 = head;
	struct Student * temp2 = head; 
	while(temp1!=NULL){
		
		if(temp1->ID==ID){
			
			printf("Record with ID Number %d Found !!!\n", ID);
			
			if(temp1==temp2){
				// this condition will run if
				// the record that we need to delete is the first node
				// of the linked list
				head = head->next;
				free(temp1);
			}
			else{
				// temp1 is the node we need to delete
				// temp2 is the node previous to temp1
				temp2->next = temp1->next;
				free(temp1); 
			}
			
			printf("Record Successfully Deleted !!!\n");
			return;
			
		}
		temp2 = temp1;
		temp1 = temp1->next;
		
	}
	printf("Student with ID number %d is not found !!!\n",ID);
	
}


void display()
{
    struct Student * temp = head;
	while(temp!=NULL){
		
		printf("ID: %d\n", temp->ID);
		printf("Name: %s\n", temp->name);
		printf("Phone: %s\n", temp->phone);
		printf("GPA: %0.4f\n\n", temp->GPA);
		temp = temp->next;
		
	}
}
void search(int ID)
{
    struct Student * temp = head;
	while(temp!=NULL){
		if(temp->ID==ID){
			printf("ID: %d\n", temp->ID);
			printf("Name: %s\n", temp->name);
			printf("Phone: %s\n", temp->phone);
			printf("GPA: %0.4f\n", temp->GPA);
			return;
		}
		temp = temp->next;
	}
	printf("Student with ID number %d is not found !!!\n", ID);
}

int main()
{
system("COLOR 0A");
    head = NULL;
    int choice;
    char name[100];
    char phone[100];
    int ID;
    float GPA;

    

	printf("\n________________________________________________________________________________________________________________________");
	printf("\n\t\t\t\t\tWelcome To Student Management System\n");
	printf("\n________________________________________________________________________________________________________________________\n");
	
    printf("\n \n \tEnter 1 to insert student details\n \tEnter 2 to search for student details\n \tEnter 3 to delete student details\n \tEnter 4 to update student details\n \tEnter 5 to display all student details");
    
    
    
    do
    {
        printf("\n\n\n Enter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter ID number: ");
                scanf("%d", &ID);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                printf("Enter GPA: ");
                scanf("%f", &GPA);
                insert(ID, name, phone, GPA);
                break;
            case 2:
                printf("Enter ID number to search: ");
                scanf("%d", &ID);
                search(ID);
                break;
            case 3:
                printf("Enter ID number to delete: ");
                scanf("%d", &ID);
                Delete(ID);
                break;
            case 4:
                printf("Enter ID number to update: ");
                scanf("%d", &ID);
                update(ID);
                break;
            case 5:
                display();
                break;
        }
        
    } while (choice != 0);

}

