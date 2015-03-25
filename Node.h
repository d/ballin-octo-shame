//
// Created by Pivotal Data on 3/24/15.
//

#ifndef _BALLIN_OCTO_SHAME_NODE_H_
#define _BALLIN_OCTO_SHAME_NODE_H_


struct Node {
    int data;
    Node* next;
};

Node* label(Node* list);

Node* reverse(Node* list);

Node* reverseN(Node* list, int N);

#endif //_BALLIN_OCTO_SHAME_NODE_H_
