/**Convert infix expressions to postfix using stack data structure*/
#include <iostream>
#include <string>

#define MAX_SIZE 100

class arrStack {
private:
  char stack[MAX_SIZE];
  int len;
  int top;

public:
  arrStack() {
    len = 0;
    top = -1;
  }

  void push(char element) {
    stack[++top] = element;
    len++;
  }

  char pop() {
    len--;
    return stack[top--];
  }

  char peek() { return stack[top]; }

  void display() {
    for (int i = 0; i < len; i++)
      std::cout << stack[i];
    std::cout << '\n';
  }

  bool isEmpty() { return len == 0; }
};

bool isOperator(char possible_operator) {
  return (possible_operator == '%' || possible_operator == '^' ||
          possible_operator == '*' || possible_operator == '/' ||
          possible_operator == '+' || possible_operator == '-');
}

int precedence(char _operator) {
  if (_operator == '%' || _operator == '^')
    return 3;
  if (_operator == '/' || _operator == '*')
    return 2;
  if (_operator == '+' || _operator == '-')
    return 1;
  return -1;
}

int main() {
  arrStack operandStack = arrStack();
  std::string infixExpression;
  std::string postfixExpression = "";

  std::cout << "Enter an expression: ";
  std::cin >> infixExpression;

  for (char loop1 : infixExpression) {
    if (loop1 == '(') {
      operandStack.push('(');

    } else if (loop1 == ')') {
      while (operandStack.peek() != '(')
        postfixExpression += operandStack.pop();
      operandStack.pop();

    } else if (isOperator(loop1)) {
      while (!operandStack.isEmpty() &&
             precedence(loop1) <= precedence(operandStack.peek())) {
        postfixExpression += operandStack.pop();
      }

      operandStack.push(loop1);
    } else {
      postfixExpression += loop1;
    }
  }

  while (!operandStack.isEmpty())
    postfixExpression += operandStack.pop();

  std::cout << postfixExpression << '\n';
  operandStack.display();
  return 0;
}