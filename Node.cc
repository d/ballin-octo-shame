#include "Node.h"

Node *label(Node *list) {
    int cur_index = 1;
    Node *cur_node = list;
    while (cur_node != nullptr) {
        cur_node->data = cur_index;
        cur_node = cur_node->next;
        cur_index++;
    }
    return list;
}

Node *reverseNImpl(Node *list, int N, bool isNUsed) {
    if (N <= 1 || list == nullptr || list->next == nullptr)
        return list;
    Node *curNode = list, *nextNode = curNode->next;
    curNode->next = nullptr;
    int counter = 1;
    Node *lastNode = list, *prevLastNode = nullptr;
    bool isFirstHeadFound = false;
    Node *returnHead;

    while (nextNode != nullptr) {
        Node *temp = nextNode->next;
        if (!isNUsed || counter % N != 0) {
            nextNode->next = curNode;
            counter++;
        } else {
            lastNode->next = nextNode;
            if(!isFirstHeadFound) {
                returnHead = curNode;
                isFirstHeadFound = true;
            } else {
                prevLastNode->next = curNode;
            }
            prevLastNode = lastNode;
            lastNode = nextNode;

            counter = 1;

        }
        curNode = nextNode;
        nextNode = temp;
    }

    if(!isFirstHeadFound) {
        returnHead = curNode;
    }
    return returnHead;
}

Node *reverse(Node *list) {
    return reverseNImpl(list, 2, false);
}


Node *reverseN(Node *list, int N) {
    return reverseNImpl(list, N, true);

}
