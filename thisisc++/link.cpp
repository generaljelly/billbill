#include <iostream>

void add_element();
void delete_element();
void print_list();
void search();
void update_element();

// create node, search, add elements, remove elements,  update
// duplicates allowed
// allow user to add n amount of elements without stopping


struct Node {
    int el;
    Node *next;
};

Node *head = NULL; // pointer to beginning of list

// command "delete head" causes issues in print array as head cannot be reset to NULL
// so global variable is created to prevent this
int doNotPrint = 0;

int main(void) {
    do {
        int choice;
        std::cout << "1. Add Element to List" << std::endl << "2. Update Element" << std::endl << "3. Search for Element"
        << std::endl << "4. Remove Element" << std::endl << "5.Exit" << std::endl << std::endl;

        scanf("%d", &choice);
        switch (choice) {
            case 1:     
                add_element();
                break;
            case 2:
                update_element();
                break;
            case 3:
                search();
                break;
            case 4:
                delete_element();
                break;
            case 5:
                exit(0);
            default:
                std::cout << "Out of Range" << std::endl;
        }
        print_list();
    } while(1);

}

void print_list() {
    if (doNotPrint == 1) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    int numOfEl = 0;
    Node *temp = head;
    std::cout << "[ ";
    while (temp->next != NULL) {
        std::cout << temp->el << " ";
        temp = temp->next;
        numOfEl++;
    }

    std::cout << temp->el << " ]" << std::endl;
    numOfEl++;
    std::cout << "Number of Items: " << numOfEl << std::endl;
}

void add_element() {

    int el;
    std::cout << "What would you like to add? ";
    scanf("%d", &el);

    // creating new node
    struct Node *new_node = new Node; 
    new_node->el = el;
    new_node->next = NULL;
    
    // points head to new node if list empty
    if (head == NULL) {
        head = new_node;
    }
    else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // second to last node noted, will point to new node
        temp->next = new_node;
    }
}

void delete_element() {
    if (head == NULL) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    int el;

    std::cout << "Choose element to be deleted ";
    scanf("%d", &el);

    // if list has only one element
    if (head->next == NULL) {
        if (head->el == el) {
            delete head;
            doNotPrint = 1;
        }
        return;
    }

    Node *temp = head;
    Node *prev = temp;

    // iterate through all nodes
    while (temp->next != NULL) {

        // if element in beginning of list
        if (head->el == el) {
            temp = temp->next;
            delete head;
            head = temp;
            // if only one element left, retrigger base case
            /// DO WHILE LOOOOOP ////// ////////////////////////////////////////////
            if (head->next == NULL) {
                if (head->el == el) {
                    delete head;
                    doNotPrint = 1;
                }
                return;
            }
        }

        // if element in end
        // temp is second to last, temp->next is last
        else if (temp->next->next == NULL) {
            Node *lastNode = temp->next; //lastNode pointer unnecessary, simplifies code
            // check if last node needs to be deleted
            if (lastNode->el == el) {
                delete lastNode;
                lastNode = temp;
                temp->next = NULL;
                // check if secondtolast (new last) node need to be deleted as well
                if (temp->el == el) {
                    delete temp;
                    temp = prev;
                    prev->next = NULL;
                }
                return;
            }
            // check if only secondtolast node needs to be deleted
            else if (temp->el == el) {
                prev->next = lastNode;
                delete temp;
            }
        }
        // if element in middle
        else {
            if (temp->el == el) {
                // node to be deleted is "D"
                // point previous node to D to next node 
                prev->next = temp->next;
                delete temp;
            }
        }
        prev = temp; // one step behind iterating pointer
        temp = temp->next; // iterate
    }
    return;
   
}


void search() {
    if (head == NULL) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    
    int el, i = 0;
    std::cout << "What element would you like to search for? ";
    scanf("%d", &el);

    // one element in list
    if (head->next == NULL) {
        if (head->el == el) {
            std::cout << "Element found in first position" << std::endl;
        }
        else {
            std::cout << "Element not found" << std::endl;
        }
        return;
    }

    Node *temp = head;
    bool foundBefore = false; // return to user that element wasnt found

    while (temp->next != NULL) {
        i++; // i = position
        if (temp->el == el) {
            if (foundBefore == false) {
                std::cout << "Element found in position(s): " << std::endl << i << std::endl;
                foundBefore = true; 
            }
            else {
                std::cout << i << std::endl;
            }
        }
        temp = temp->next;
    }
    i++;
    // check last element
    if (temp->el == el) {
        std::cout << i << std::endl;
    }

    if (foundBefore == false) {
        std::cout << "Element not found" << std::endl;
    }
    
}

void update_element() {
    if (head == NULL) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    int el, newel;

    std::cout << "Which element(s) would you like to update " << std::endl;
    scanf("%d", &el);
    std::cout << "What to? ";
    scanf("%d", &newel);

    // only one element
    if(head->next == NULL) {
        if (head->el == el) {
            head->el = newel;
        }
        else {
            std::cout << "Element entered not found" << std::endl;
        }
        return;
    }

    Node *temp = head;
    while (temp->next != NULL) {
        if (temp->el == el) {
            temp->el = newel;
        }
        temp = temp->next;
    } 
    // check final element
    if (temp->el == el) {
        temp->el = newel;
    }

}
