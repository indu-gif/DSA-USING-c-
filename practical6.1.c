#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;

void insertatfirst(int x);
void insertatend(int x);
void insertatposition(int item, int index);
void deleteatfirst();
void deleteatend();
void deleteatposition(int index);
void display();

int main() {
    int choice = 0;
    int item, index;

    printf("Enter the operation number\n");
    printf("1.insertatfirst\n2.insertatend\n3.insertatposition\n4.deleteatfirst\n5.deleteatend\n6.deleteatposition\n7.display\n");
    printf("Enter your choice =\n");
    scanf("%d", &choice);

    while (choice != 8) {
        switch (choice) {
            case 1:
                printf("Enter element=");
                scanf("%d", &item);
                insertatfirst(item);
                break;

            case 2:
                printf("Enter element=");
                scanf("%d", &item);
                insertatend(item);
                break;

            case 3:
                printf("Enter element=");
                scanf("%d", &item);
                printf("Enter position=");
                scanf("%d", &index);
                insertatposition(item, index);
                break;

            case 4:
                deleteatfirst();
                break;

            case 5:
                deleteatend();
                break;

            case 6:
                printf("Enter position=");
                scanf("%d", &index);
                deleteatposition(index);
                break;

            case 7:
                display();
                break;

            default:
                printf("Invalid option\n");
        }

        printf("Enter your choice =\n");
        scanf("%d", &choice);
    }

    return 0;
}

void insertatfirst(int x) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory not available\n");
        return;
    }
    temp->data = x;
    temp->next = NULL;
    if (head != NULL) {
        temp->next = head;
    }
    head = temp;
}

void display() {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insertatend(int x) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory not available\n");
        return;
    }
    temp->data = x;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        return;
    }
    struct node *t1 = head;
    while (t1->next != NULL) {
        t1 = t1->next;
    }
    t1->next = temp;
}

void insertatposition(int item, int index) {
    int i = 0;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory not available\n");
        return;
    }
    ptr->data = item;
    ptr->next = NULL;
    if (index == 1) {
        ptr->next = head;
        head = ptr;
    } else {
        temp = head;
        for (i = 0; i < (index - 2); i++) {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
}

void deleteatfirst() {
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct node *ptr = head;
    if (head->next == NULL) {
        printf("Value deleted is %d\n", head->data);
        head = NULL;
        free(ptr);
    } else {
        head = head->next;
        free(ptr);
    }
}

void deleteatend() {
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct node *ptr = head, *temp;
    if (head->next == NULL) {
        printf("Value deleted is %d\n", head->data);
        head = NULL;
        free(ptr);
    } else {
        while (ptr->next != NULL) {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        printf("Value deleted is %d\n", ptr->data);
        free(ptr);
    }
}

void deleteatposition(int index) {
    struct node *ptr = head, *temp;
    int i = 0;
    if (index == 1) {
        head = ptr->next;
        free(ptr);
    } else {
        for (i = 0; i < (index - 2); i++) {
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = temp->next;
        printf("Value deleted is %d\n", temp->data);
        free(temp);
    }
}