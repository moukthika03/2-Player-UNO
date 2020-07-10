#ifndef NODE_H
#define NODE_H

#include "card.h"

class Node
{
private:
    Card* card;
    Node* link;
public:
    Node(Card*);
    friend class List;
};

#endif // NODE_H
