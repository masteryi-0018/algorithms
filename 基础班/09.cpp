#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* pre;
    ListNode(): val(0) {}
    ListNode(int x): val(x), next(nullptr), pre(nullptr) {}
    ListNode(int x, ListNode* nPtr, ListNode* pPtr): val(x), next(nPtr), pre(pPtr) {}
};

// 返回多个值可以封装成类，但是2个值可以直接用pair
pair<ListNode*, ListNode*> createList(int len) {
    if (len == 0) {
        return {nullptr, nullptr};
    }
    ListNode* lst = new ListNode(1);
    ListNode* head = lst;
    ListNode* pre;
    for (int i = 1; i < len; i++) {
        lst->next = new ListNode(i+1);
        pre = lst;
        lst = lst->next;
        lst->pre = pre;
    }
    return {head, lst};
}

void printForward(ListNode* lst) {
    while (lst != nullptr) {
        cout << lst->val << ' ';
        lst = lst->next;
    }
    cout << endl;
}

void printBackword(ListNode* lst) {
    while (lst != nullptr) {
        cout << lst->val << ' ';
        lst = lst->pre;
    }
    cout << endl;
}

// 迭代
pair<ListNode*, ListNode*> reverseList1(ListNode* head) {
    ListNode* ori = head;
    ListNode* pre = nullptr;
    ListNode* next;
    while (head != nullptr) {
        next = head->next;
        head->next = pre;
        head->pre = next;
        pre = head;
        head = next;
    }
    return {pre, ori};
}

// 递归，不会做 -.-

int main()
{
    int len = 5;
    pair<ListNode*, ListNode*> result = createList(len);
    ListNode* head = result.first;
    ListNode* tail = result.second;
    printForward(head);
    printBackword(tail);

    pair<ListNode*, ListNode*> newresult = reverseList1(head);
    ListNode* newhead = newresult.first;
    ListNode* newtail = newresult.second;
    printForward(newhead);
    printBackword(newtail);

    // std::cout << "Hello World" << std::endl;
    // system("pause");
    return 0;
}