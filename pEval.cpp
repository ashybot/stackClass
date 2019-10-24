//=========================================================
// Name: Ashley Jacobs
// Complier:  g++
// Postfix expression evaluator client pEval.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: To evaluate post-fix expressions entered by the user
//Algorithm: Evaluating post-fix expressions
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
    
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop

  int number;

  bool flag=false;
 
  cout << endl << endl << endl; 
  cout << "Type a postfix expression to evaluate or enter EXIT:" << endl << "(Available Operators: +, -, *) " << endl << endl << "Your expression: ";
  cin >> expression;

  while (expression!="EXIT" && expression!="exit")
  {

  while (expression[i]!= '\0' && flag==false)
    {
     try
       {
	 item = expression[i];  // current char
	 
	 // ** do all the steps in the algorithm given in Notes-1
	 switch(item)
	   {
	   case '0':
	   case '1':
	   case '2':
	   case '3':
	   case '4':
	   case '5':
	   case '6':
	   case '7':
	   case '8':
	   case '9':

             number= item - '0'; //typecasting
             postfixstack.push(number);
             break;

	   case '+':           
	   postfixstack.pop(box1);
	   postfixstack.pop(box2);
	   postfixstack.push(box1+box2);
	   break;

	   case '-':
	     postfixstack.pop(box1);
	     postfixstack.pop(box2);
	     postfixstack.push(box2-box1);
	     break;

	   case '*':	 
	     postfixstack.pop(box1);
	     postfixstack.pop(box2);
	     postfixstack.push(box1*box2);
	     break;

	     default:
	     throw item;
	     break;
	   }
	 
       } // this closes try
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{

	  cout << endl << "--------------------------------------------------------";
	  cout << endl << "The expression is too long! " << endl;
	  cout << "--------------------------------------------------------" << endl;

	  flag=true;
	  postfixstack.clearIt();
	}

      catch (stack::Underflow)
	{
	  cout << endl << "--------------------------------------------------------";
	  cout << endl << "There is a missing operand/too many operators, " << endl << "so the expression could not be evaluated." << endl;
	  cout << "--------------------------------------------------------" << endl;

	  flag=true;
	  postfixstack.clearIt();
	}

      catch (char const& errormsg) // for invalid item case
	{
	  cout << endl << "--------------------------------------------------------";
	  cout << endl << errormsg << " is an invalid character! Unable to " << endl << "evaluate the expression."  << endl;
	  cout << "--------------------------------------------------------" << endl;

	  flag=true;
	  postfixstack.clearIt();
	}

      // go back to the loop after incrementing i
     i++;
    }// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.

  if (flag==false) //if no errors occurred, display result
    {
      int result;
      postfixstack.pop(result);
      cout << endl << "--------------------------------------------------------";
      cout << endl << "Result: " << result << endl;
      cout << "--------------------------------------------------------" << endl;

    }

 
 // If anything is left on the stack, an incomplete expression
 // was found so inform the user.
  if (postfixstack.isEmpty()==false)
    {
      cout << endl << "Incomplete expression!";
      cout << endl << "--------------------------------------------------------" << endl;
 
    }


  postfixstack.clearIt();
  i=0;
  flag=false;

  cout << endl << endl << endl << endl << "Type another postfix expression or enter EXIT:" << endl << endl << "Your expression: ";
  cin >> expression;

    } // end of user input loop

  cout << endl << "--------------------------------------------------------" << endl;

  cout << endl << "Have a nice day!" << endl << endl;
}// end of the program
