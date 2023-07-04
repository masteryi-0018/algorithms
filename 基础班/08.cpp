#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(): val(0) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* ptr): val(x), next(ptr) {}
};

ListNode* createList(int len) {
    if (len == 0) {
        return nullptr;
    }
    ListNode* lst = new ListNode(1);
    ListNode* head = lst;
    for (int i = 1; i < len; i++) {
        lst->next = new ListNode(i+1);
        lst = lst->next;
    }
    return head;
}

void printList(ListNode* lst) {
    while (lst != nullptr) {
        cout << lst->val << ' ';
        lst = lst->next;
    }
    cout << endl;
}

// 迭代
ListNode* reverseList1(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* next;
    while (head != nullptr) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

// 递归
ListNode* reverseList2(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* newhead = reverseList2(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newhead;
}

int main()
{
    int len = 5;
    ListNode* head = createList(len);
    printList(head);

    ListNode* newhead = reverseList1(head);
    printList(newhead);

    ListNode* newhead2 = reverseList2(newhead);
    printList(newhead2);

    // std::cout << "Hello World" << std::endl;
    // system("pause");
    return 0;
}