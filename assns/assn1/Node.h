#ifndef __NODE_H_
#define __NODE_H_

class Node {
  friend class MyList;
private:
  Node* next;
  char value;
//public:
  //~Node(){};
};
#endif /* NODE_H_ */