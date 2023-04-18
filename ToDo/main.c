#include <stdio.h>
#include "stdlib.h"

typedef struct ToDo todo;

struct ToDo {
    char buffer[101];
    todo* next;
    int count;
};

void interface();

void seelist();

void addtolist();

void deleteitem();

void adjustcount();

//start of pointer is null
todo* start = NULL;

int main() {
    int choice;
    interface();

    while (1) {

        system("Color 3F");

        //clear console
        system("cls");

        //print interface
        printf("Adams Highly Efficient To Do List With No Problems Whatsoever\n");
        printf("1. View To Do List\n");
        printf("2. Add To Do\n");
        printf("3. Delete To Do\n");
        printf("4. Exit\n");

        //get user input
        printf("Enter your choice: \t\t");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                seelist();
                break;
            case 2:
                addtolist();
                break;
            case 3:
                deleteitem();
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("Invalid choice\n");
                system("pause");
        }
    }
    return 0;
}




//interface and splash screen
void interface() {
    system("Color 4F");
    printf("\n\n\n\n");
    printf("\t_______________________"
           "________________________"
           "________________________"
           "________________________"
           "__________\n");
    printf("\t_______________________"
           "________________________"
           "________________________"
           "________________________"
           "_________\n\n");
    printf("\t} : } : } : } : } : } "
           ": } : } : } :   "
           "WHAT COULD GO WRONG??"
           "     : { : { : { : { : { "
           ": { : { : { : {\n\n");
    printf("\t_______________________"
           "________________________"
           "________________________"
           "________________________"
           "__________\n");
    printf("\t_______________________"
           "________________________"
           "________________________"
           "________________________"
           "_________\n\n");


    system("pause");

}

//view list

void seelist() {
    //clear console
    system("cls");

    //pointer for traversing
    todo* temp;

    //start of list
    temp = start;

    //if list is empty
    if (start == NULL)
        printf("\n\tNothing's due today!\n");

    //move until last node
    while (temp != NULL){
        //print node number
        printf("\n\t%d. ", temp->count);

        //print data
        puts(temp->buffer);

        //clear output console
        fflush(stdin);

        //move to next node
        temp = temp->next;
    }

    printf("\n\n\n");
    system("pause");
}

void addtolist() {
    char c;

    //pointers to node
    todo *add, *temp;
    system("cls");

    //loop until user enters 'n'
    while (1){
        printf("\n\tWant to add a new task? (y/n): ");
        fflush(stdin);
        scanf("%c", &c);

        //if user enters 'n'
        if (c == 'n')
            break;
        else {
            //if start node is null
            if (start == NULL){
                //allocate memory
                start = (todo*)malloc(sizeof(todo));

                //set next node to null
                start->next = NULL;

                //set count to 1
                start->count = 1;

                //get data
                printf("\n\tEnter task: ");
                fflush(stdin);
                gets(start->buffer);
            }
            else {
                //allocate memory
                add = (todo*)malloc(sizeof(todo));

                //set next node to null
                add->next = NULL;

                //get data
                printf("\n\tEnter task: ");
                fflush(stdin);
                gets(add->buffer);

                //set count
                add->count = start->count + 1;

                //set temp to start
                temp = start;

                //move to last node
                while (temp->next != NULL)
                    temp = temp->next;

                //set last node to new node
                temp->next = add;
            }

            adjustcount();
        }
    }
}

//delete item
void deleteitem() {
    int num, i;
    todo *temp, *prev;

    //clear console
    system("cls");

    //print list
    seelist();

    //get node number to delete
    printf("\n\tEnter task number to delete: ");
    scanf("%d", &num);

    //if list is empty
    if (start == NULL){
        printf("\n\tNothing's due today!\n");
        system("pause");
        return;
    }

    //if node to delete is first node
    if (num == 1){
        //set temp to start
        temp = start;

        //set start to next node
        start = start->next;

        //free memory
        free(temp);

        //adjust count
        adjustcount();
    }
    else {
        //set temp to start
        temp = start;

        //move to node to delete
        for (i = 1; i < num; i++){
            prev = temp;
            temp = temp->next;
        }

        //set previous node to next node
        prev->next = temp->next;

        //free memory
        free(temp);

        //adjust count
        adjustcount();
    }
}

void adjustcount() {
    //traverse using node pointer
    todo* temp;
    int i = 1;
    temp = start;

    //move to last node
    while (temp != NULL){
        //set count
        temp->count = i;

        //move to next node
        temp = temp->next;

        //increment count
        i++;
    }

}
