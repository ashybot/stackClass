// =======================================================
// Ashley Jacobs
// Compiler:  g++ 
// Header file stack.h
//=======================================================

//----- Globally setting up the aliases ----------------

const int MAX = 10;   // The MAX number of elements for the stack
                      // MAX is unknown to the client

typedef int el_t;      // the el_t type is ** for now
                      // el_t is unknown to the client
//-------------------------------------------------------


class stack
{ 
  
 private: // to be hidden from the client
  
   el_t     el[MAX];       // el is  an array of el_t's
   int      top;           // top is index to the top of stack

 public:  // available to the client
  
  // Add exception handling classes here  
   class Underflow{};
   class Overflow{};
  
  // prototypes to be used by the client
  // Note that no parameter variables are given

  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object
  


  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  void push(el_t);
  


  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (by ref)     

  void pop(el_t&);
  


  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: **  provides a variable to receive the value of the top element (by ref)

  void topElem(el_t&);


  
  // ** Must add good comments for each function - See Notes1B


  //PURPOSE: ** if a given stack is empty, returns true
  //            if not, returns false
  //NOTES:      used in the pop function, no parameter
  bool isEmpty();


  //PURPOSE: ** if a given stack is full, returns true
  //            if not, returns false
  //NOTES:      used in the push function, no parameter
  bool isFull();


  //PURPOSE: ** if not empty, displays all elements (vertically from top to bottom)
  //            otherwise, throws an exception - Stack is empty
  //NOTES:      no parameter
  void displayAll();

  //PURPOSE: ** if not empty, removes all elements and decrements top
  //            else, throws an exception - Stack is empty
  //NOTES:      no parameter
  void clearIt();
  
};  


