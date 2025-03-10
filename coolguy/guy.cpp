#include <iostream>

struct details 
{
    int notname;
};


struct Node
{   
    int num;
    Node *next;
    details d;
};

Node *head = NULL;


void insert_node(int num, int name) 
{
    Node *new_node = new Node;
    new_node->num = num;
    new_node->next = head;
    new_node->d.notname = name;
    head = new_node;
}

int main(void) 
{
    std::cout << ":3" << std::endl;
    insert_node(0, 7);
    insert_node(8, 0);
    insert_node(3, 2);

    while (head != NULL) 
    {
        std::cout << head->num << ": " << head->d.notname << std::endl;
        head = head->next;
    }

}
