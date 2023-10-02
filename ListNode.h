#ifndef LISTNODE_H
#define LISTNODE_H

class NumberList {
private:
    struct ListNode {
        int id;
        double GPA;
        ListNode* next;
    };

    ListNode* head;

public:
    NumberList();
    ~NumberList();

    void appendNode(int, double);
    void deleteNode(int);
    void insertNode(int, double);
    void displayList() const;
};

#endif
