#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// to check if list is empty
int isEmpty() {
    return head == NULL;
}

// 1. Create Circular Linked List
void createList(int n) {
    struct Node *newNode, *temp;
    int data;
    head = NULL;
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }
}

// 2. Traverse
void traverse() {
    if (isEmpty()) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// 3. Count elements
int countNodes() {
    if (isEmpty()) return 0;
    int count = 0;
    struct Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// 4. Insert at beginning
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (isEmpty()) {
        head = newNode;
        newNode->next = head;
        return;
    }
    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// 5. Insert at end
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (isEmpty()) {
        head = newNode;
        newNode->next = head;
        return;
    }
    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

// 6. Insert at ith position
void insertAtPosition(int pos, int data) {
    int count = countNodes();
    if (pos < 1 || pos > count + 1) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

// 7. Insert after element
void insertAfterElement(int element, int data) {
    if (isEmpty()) return;
    struct Node* temp = head;
    do {
        if (temp->data == element) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Element not found.\n");
}

// 8. Delete last node
void deleteLast() {
    if (isEmpty()) return;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head, *prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
}

// 9. Delete first node
void deleteFirst() {
    if (isEmpty()) return;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    struct Node* del = head;
    head = head->next;
    temp->next = head;
    free(del);
}

// 10. Delete ith node
void deleteAtPosition(int pos) {
    int count = countNodes();
    if (pos < 1 || pos > count) return;
    if (pos == 1) {
        deleteFirst();
        return;
    }
    struct Node *temp = head, *prev = NULL;
    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

// 11. Delete after a given node
void deleteAfterElement(int element) {
    if (isEmpty()) return;
    struct Node* temp = head;
    do {
        if (temp->data == element) {
            struct Node* del = temp->next;
            if (del == head)
                head = head->next;
            temp->next = del->next;
            free(del);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Element not found.\n");
}

// 12. Reverse list
void reverseList() {
    if (isEmpty()) return;
    struct Node *prev = NULL, *curr = head, *next = NULL;
    struct Node* last = head;
    do {
        next = curr->next;
        curr->next = prev ? prev : head;
        prev = curr;
        curr = next;
    } while (curr != head);
    head->next = prev;
    head = prev;
}

// 13. Append two lists
void appendList(struct Node* list2) {
    if (list2 == NULL) return;
    if (head == NULL) {
        head = list2;
        return;
    }
    struct Node* temp1 = head;
    while (temp1->next != head)
        temp1 = temp1->next;
    struct Node* temp2 = list2;
    while (temp2->next != list2)
        temp2 = temp2->next;
    temp1->next = list2;
    temp2->next = head;
}

// 14. Find middle without counting
void findMiddle() {
    if (isEmpty()) return;
    struct Node *slow = head, *fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element: %d\n", slow->data);
}

// 15. Find max
void findMax() {
    if (isEmpty()) return;
    int max = head->data;
    struct Node* temp = head->next;
    while (temp != head) {
        if (temp->data > max) max = temp->data;
        temp = temp->next;
    }
    printf("Max value: %d\n", max);
}

// 16. Find min
void findMin() {
    if (isEmpty()) return;
    int min = head->data;
    struct Node* temp = head->next;
    while (temp != head) {
        if (temp->data < min) min = temp->data;
        temp = temp->next;
    }
    printf("Min value: %d\n", min);
}

// 17. Sort list
void sortList() {
    if (isEmpty()) return;
    struct Node *i, *j;
    int temp;
    for (i = head; i->next != head; i = i->next) {
        for (j = i->next; j != head; j = j->next) {
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
        printf("\n--- Circular Linked List Menu ---\n");
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
            case 7: printf("After which element? "); scanf("%d", &element);
                    printf("Enter data: "); scanf("%d", &data); insertAfterElement(element, data); break;
            case 8: deleteLast(); break;
            case 9: deleteFirst(); break;
            case 10: printf("Enter position: "); scanf("%d", &pos); deleteAtPosition(pos); break;
            case 11: printf("Delete after element: "); scanf("%d", &element); deleteAfterElement(element); break;
            case 12: reverseList(); break;
            case 13:
                printf("Enter nodes for second list: "); scanf("%d", &n);
                list2 = NULL;
                for (int i = 0; i < n; i++) {
                    printf("Enter data %d: ", i + 1);
                    scanf("%d", &data);
                    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                    newNode->data = data;
                    if (list2 == NULL) {
                        list2 = newNode;
                        list2->next = list2;
                    } else {
                        struct Node* t = list2;
                        while (t->next != list2)
                            t = t->next;
                        t->next = newNode;
                        newNode->next = list2;
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
