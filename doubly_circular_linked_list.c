#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;

// Utility to create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

// 1. Create list
void createList(int n) {
    if (n <= 0) return;
    int data;
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head = createNode(data);
    Node *tail = head;

    for (int i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        Node *newNode = createNode(data);
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
}

// 2. Traverse
void traverse() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// 3. Count
int count() {
    if (!head) return 0;
    int c = 0;
    Node *temp = head;
    do {
        c++;
        temp = temp->next;
    } while (temp != head);
    return c;
}

// 4. Insert at beginning
void insertBeginning(int data) {
    Node *newNode = createNode(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node *tail = head->prev;
    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
    head = newNode;
}

// 5. Insert at end
void insertEnd(int data) {
    if (!head) {
        head = createNode(data);
        return;
    }
    Node *newNode = createNode(data);
    Node *tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
}

// 6. Insert at ith position
void insertAtPosition(int data, int pos) {
    int n = count();
    if (pos <= 1) {
        insertBeginning(data);
        return;
    }
    if (pos > n) {
        insertEnd(data);
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;
    Node *newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// 7. Insert after element
void insertAfterElement(int data, int key) {
    if (!head) return;
    Node *temp = head;
    do {
        if (temp->data == key) {
            Node *newNode = createNode(data);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Element %d not found.\n", key);
}

// 8. Delete last node
void deleteLast() {
    if (!head) return;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    Node *tail = head->prev;
    tail->prev->next = head;
    head->prev = tail->prev;
    free(tail);
}

// 9. Delete first node
void deleteFirst() {
    if (!head) return;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    Node *tail = head->prev;
    Node *temp = head;
    head = head->next;
    head->prev = tail;
    tail->next = head;
    free(temp);
}

// 10. Delete ith node
void deleteAtPosition(int pos) {
    int n = count();
    if (pos < 1 || pos > n) return;
    if (pos == 1) {
        deleteFirst();
        return;
    }
    if (pos == n) {
        deleteLast();
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos; i++)
        temp = temp->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

// 11. Delete after certain node
void deleteAfterElement(int key) {
    if (!head) return;
    Node *temp = head;
    do {
        if (temp->data == key) {
            Node *target = temp->next;
            if (target == head) {
                deleteFirst();
                return;
            }
            temp->next = target->next;
            target->next->prev = temp;
            free(target);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Element %d not found.\n", key);
}

// 12. Reverse linked list
void reverseList() {
    if (!head) return;
    Node *curr = head, *temp = NULL;
    do {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    } while (curr != head);
    head = head->next;
}

// 13. Append two linked lists
void appendLists(Node *head2) {
    if (!head2) return;
    if (!head) {
        head = head2;
        return;
    }
    Node *tail1 = head->prev;
    Node *tail2 = head2->prev;

    tail1->next = head2;
    head2->prev = tail1;
    tail2->next = head;
    head->prev = tail2;
}

// 14. Find middle (without count)
void findMiddle() {
    if (!head) return;
    Node *slow = head, *fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element: %d\n", slow->data);
}

// 15. Find max value
void findMax() {
    if (!head) return;
    Node *temp = head;
    int max = temp->data;
    do {
        if (temp->data > max)
            max = temp->data;
        temp = temp->next;
    } while (temp != head);
    printf("Maximum value: %d\n", max);
}

// 16. Find min value
void findMin() {
    if (!head) return;
    Node *temp = head;
    int min = temp->data;
    do {
        if (temp->data < min)
            min = temp->data;
        temp = temp->next;
    } while (temp != head);
    printf("Minimum value: %d\n", min);
}

// 17. Sort the list
void sortList() {
    if (!head) return;
    Node *i, *j;
    for (i = head; i->next != head; i = i->next) {
        for (j = i->next; j != head; j = j->next) {
            if (i->data > j->data) {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

// MENU
int main() {
    int choice, data, pos, n, key;
    Node *secondList = NULL;

    while (1) {
        printf("\n---- Doubly Circular Linked List Menu ----\n");
        printf("1.Create 2.Traverse 3.Count 4.Insert Beginning 5.Insert End 6.Insert at Position");
        printf("\n7.Insert After Element 8.Delete Last 9.Delete First 10.Delete at Position 11.Delete After Element");
        printf("\n12.Reverse 13.Append Another List 14.Find Middle 15.Find Max 16.Find Min 17.Sort 0.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2: traverse(); break;
            case 3: printf("Count: %d\n", count()); break;
            case 4: printf("Enter data: "); scanf("%d", &data); insertBeginning(data); break;
            case 5: printf("Enter data: "); scanf("%d", &data); insertEnd(data); break;
            case 6: printf("Enter data & position: "); scanf("%d %d", &data, &pos); insertAtPosition(data, pos); break;
            case 7: printf("Enter data & key: "); scanf("%d %d", &data, &key); insertAfterElement(data, key); break;
            case 8: deleteLast(); break;
            case 9: deleteFirst(); break;
            case 10: printf("Enter position: "); scanf("%d", &pos); deleteAtPosition(pos); break;
            case 11: printf("Enter key: "); scanf("%d", &key); deleteAfterElement(key); break;
            case 12: reverseList(); break;
            case 13:
                printf("Creating second list to append.\nEnter number of nodes: ");
                scanf("%d", &n);
                secondList = NULL;
                {
                    Node *tempHead = head; // temporarily backup
                    head = NULL;
                    createList(n);
                    appendLists(head);
                    head = tempHead;
                }
                break;
            case 14: findMiddle(); break;
            case 15: findMax(); break;
            case 16: findMin(); break;
            case 17: sortList(); break;
            case 0: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
}
