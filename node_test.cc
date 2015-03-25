#include "Node.h"
#include "gtest/gtest.h"

Node* createList() {
    Node* list = new Node;
    list->data = 1000;
    list->next = nullptr;

    Node* prev = list;
    Node* cur;
    for(int i = 1; i < 1000; i++) {
        cur = new Node;
        cur->data = 1000-i;
        cur->next = nullptr;
        prev->next = cur;
        prev = cur;
    }
    return list;
}

void deleteList(Node* list) {
    while(list != nullptr) {
        Node* temp = list->next;
        delete list;
        list = temp;
    }
}

TEST(NodeTests, NullListLabel) {
    Node* list = nullptr;
    ASSERT_EQ(nullptr, label(list));
}

TEST(NodeTests, OneElementListLabel) {
    Node* list;
    list = new Node;
    list->data = 2;
    list->next = nullptr;
    ASSERT_EQ(1, label(list)->data);
    delete list;
}

TEST(NodeTests, MultiElementListLabel) {
    Node* list = createList();

    Node* new_list = label(list);
    Node* new_cur = new_list;
    for (int i = 1; i <=1000; i++) {
        ASSERT_EQ(i, new_cur->data);
        new_cur = new_cur->next;
    }

    deleteList(new_list);
}

TEST(NodeTests, NullListReverse) {
    Node* list = nullptr;
    ASSERT_EQ(nullptr, reverse(list));
}

TEST(NodeTests, TwoElementListReverse) {
    Node* second_element = new Node;
    second_element->data = 3;
    second_element->next = nullptr;
    Node* first_element = new Node;
    first_element->data = 2;
    first_element->next = second_element;

    Node *head = reverse(first_element);
    ASSERT_EQ(second_element, head);
    ASSERT_EQ(first_element, head->next);
    ASSERT_EQ(nullptr, head->next->next);

    deleteList(head);
}

TEST(NodeTests, MultiElementListReverse) {
    Node* list = createList();
    Node* new_list = reverse(list);
    Node* new_cur = new_list;
    for (int i = 1; i <=1000; i++) {
        ASSERT_EQ(i, new_cur->data);
        new_cur = new_cur->next;
    }
    ASSERT_EQ(nullptr, new_cur);
    deleteList(new_list);
}


TEST(NodeTests, NullListReverseN) {
    Node* list = nullptr;
    ASSERT_EQ(nullptr, reverseN(list, 1));
}

TEST(NodeTests, TwoElementListReverseN1) {
    Node* second_element = new Node;
    second_element->data = 3;
    second_element->next = nullptr;
    Node* first_element = new Node;
    first_element->data = 2;
    first_element->next = second_element;

    Node *head = reverseN(first_element, 1);
    ASSERT_EQ(first_element, head);
    ASSERT_EQ(second_element, head->next);
    ASSERT_EQ(nullptr, head->next->next);

    deleteList(head);
}

TEST(NodeTests, TwoElementListReverseN2) {
    Node* second_element = new Node;
    second_element->data = 3;
    second_element->next = nullptr;
    Node* first_element = new Node;
    first_element->data = 2;
    first_element->next = second_element;

    Node* head = reverseN(first_element, 2);
    ASSERT_EQ(second_element, head);
    ASSERT_EQ(first_element, head->next);
    ASSERT_EQ(nullptr, head->next->next);

    deleteList(head);
}

TEST(NodeTests, ThreeElementListReverseN2) {
    Node* third_element = new Node;
    third_element->data = 4;
    third_element->next = nullptr;
    Node* second_element = new Node;
    second_element->data = 3;
    second_element->next = third_element;
    Node* first_element = new Node;
    first_element->data = 2;
    first_element->next = second_element;

    Node* head = reverseN(first_element, 2);
    ASSERT_EQ(second_element, head);
    ASSERT_EQ(first_element, head->next);
    ASSERT_EQ(third_element, head->next->next);
    ASSERT_EQ(nullptr, head->next->next->next);

    deleteList(head);
}

TEST(NodeTests, ThreeElementListReverseN3) {
    Node* third_element = new Node;
    third_element->data = 4;
    third_element->next = nullptr;
    Node* second_element = new Node;
    second_element->data = 3;
    second_element->next = third_element;
    Node* first_element = new Node;
    first_element->data = 2;
    first_element->next = second_element;

    Node* head = reverseN(first_element, 3);
    ASSERT_EQ(third_element, head);
    ASSERT_EQ(second_element, head->next);
    ASSERT_EQ(first_element, head->next->next);
    ASSERT_EQ(nullptr, head->next->next->next);

    deleteList(head);
}

TEST(NodeTests, MultiElementListReverseN10) {
    Node* list = createList();
    Node* new_list = reverseN(list, 10);
    Node* new_cur = new_list;
    for (int i = 1; i <=1000; i++) {
        ASSERT_EQ(1001-(((i-1)/10 +1)*10-((i-1)%10)), new_cur->data);
        new_cur = new_cur->next;
    }
    ASSERT_EQ(nullptr, new_cur);
    deleteList(new_list);
}

