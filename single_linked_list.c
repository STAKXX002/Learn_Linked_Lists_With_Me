#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// 1. Create Linked List
void createList(int n) {
    struct Node *newNode, *temp;
    int data;
    head = NULL;
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

// 2. Traverse
void traverse() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 3. Count elements
int countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// 4. Insert at beginning
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// 5. Insert at end
void insertAtEnd(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// 6. Insert at ith position
void insertAtPosition(int pos, int data) {
    if (pos < 1) return;
    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// 7. Insert after element
void insertAfterElement(int element, int data) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != element)
        temp = temp->next;
    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
}

// 8. Delete last node
void deleteLast() {
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

// 9. Delete first node
void deleteFirst() {
    if (head == NULL) return;
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

// 10. Delete ith node
void deleteAtPosition(int pos) {
    if (head == NULL || pos < 1) return;
    if (pos == 1) {
        deleteFirst();
        return;
    }
    struct Node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) return;
    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

// 11. Delete node after a given node
void deleteAfterElement(int element) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != element)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) return;
    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

// 12. Reverse list
void reverseList() {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// 13. Append two lists
void appendList(struct Node* list2) {
    if (head == NULL) {
        head = list2;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = list2;
}

// 14. Find middle (without counting)
void findMiddle() {
    if (head == NULL) return;
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element: %d\n", slow->data);
}

// 15. Max value
void findMax() {
    if (head == NULL) return;
    int max = head->data;
    struct Node* temp = head->next;
    while (temp != NULL) {
        if (temp->data > max) max = temp->data;
        temp = temp->next;
    }
    printf("Max value: %d\n", max);
}

// 16. Min value
void findMin() {
    if (head == NULL) return;
    int min = head->data;
    struct Node* temp = head->next;
    while (temp != NULL) {
        if (temp->data < min) min = temp->data;
        temp = temp->next;
    }
    printf("Min value: %d\n", min);
}

// 17. Sort list
void sortList() {
    struct Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main() {
    int choice, n, data, pos, element;
    struct Node* list2 = NULL;

    do {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1.Create 2.Traverse 3.Count 4.InsertBeg 5.InsertEnd 6.InsertPos\n");
        printf("7.InsertAfter 8.DelLast 9.DelFirst 10.DelPos 11.DelAfter\n");
        printf("12.Reverse 13.Append 14.Middle 15.Max 16.Min 17.Sort 0.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2: traverse(); break;
            case 3: printf("Total nodes: %d\n", countNodes()); break;
            case 4: printf("Enter data: "); scanf("%d", &data); insertAtBeginning(data); break;
            case 5: printf("Enter data: "); scanf("%d", &data); insertAtEnd(data); break;
            case 6: printf("Enter pos & data: "); scanf("%d %d", &pos, &data); insertAtPosition(pos, data); break;
            case 7: printf("Insert after which element? "); scanf("%d", &element);
                    printf("Enter data: "); scanf("%d", &data); insertAfterElement(element, data); break;
            case 8: deleteLast(); break;
            case 9: deleteFirst(); break;
            case 10: printf("Enter position: "); scanf("%d", &pos); deleteAtPosition(pos); break;
            case 11: printf("Delete after element: "); scanf("%d", &element); deleteAfterElement(element); break;
            case 12: reverseList(); break;
            case 13:
                printf("Creating second list to append...\n");
                printf("Enter number of nodes: "); scanf("%d", &n);
                list2 = NULL;
                for (int i = 0; i < n; i++) {
                    printf("Enter data for node %d: ", i + 1);
                    scanf("%d", &data);
                    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                    newNode->data = data;
                    newNode->next = NULL;
                    if (list2 == NULL)
                        list2 = newNode;
                    else {
                        struct Node* t = list2;
                        while (t->next != NULL) t = t->next;
                        t->next = newNode;
                    }
                }
                appendList(list2);
                break;
            case 14: findMiddle(); break;
            case 15: findMax(); break;
            case 16: findMin(); break;
            case 17: sortList(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
