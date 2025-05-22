#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; // For parentheses
}
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0; // Invalid operator
    }
}
int evaluate(const string& post)
{
    stack<int> result;
    stack<char> opre;
    stack<char>extra;
    for(int i=0;post[i]<'\0';i++)
    {
        char c=post[i];
        if(c=' ')
        {continue;}
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            for(int j=0;j<i;j++)
            {
                if(post[j]==c)
                {
                    cout<<"enter value of"<<c<<endl;                    
                    cin>>c;
                    result.push(c);
                }
                else
                {
                    while(post[j]!=c)
                    {
                        int d=result.top();
                        result.pop();
                        extra.push(d);
                    }
                    c=result.top();
                    result.push(c);
                    while(!extra.empty())
                    {
                        int d=extra.top();
                        extra.pop();
                        result.push(d);
                    }
                }
                if(c >= '0' && c <= '9')
                {
                    result.push(c);
                }
                if(c == '+' || c == '-'||c == '*' || c == '/'||c == '^')
                {
                   opre.push(c);
                   int a=result.top();
                   result.pop();
                   int b=opre.top();
                   result.pop();
                   int d=result.top();
                   result.pop();
                   int ans= applyOperation(a,b,d);
                   result.push(ans);
                }
            }
        }
    }
   int ans= result.top();
   cout<<post<<"="<<ans;


}

void infix_postfix(const string& p) {
    stack<char> s;
    string post;

    for (char c : p) {
        // If the character is an operand, append it to the postfix expression
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            post += c;
        }
        // If the character is an opening parenthesis, push it onto the stack
        else if (c == '(') {
            s.push(c);
        }
        // If the character is a closing parenthesis, pop and append operators until '(' is encountered
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                post += s.top();
                s.pop();
            }
            s.pop(); // Pop the '('
        }
        // If the character is an operator
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            // Pop and append operators with higher or equal precedence
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                post += s.top();
                s.pop();
            }
            s.push(c); // Push the current operator onto the stack
        }
    }

    // Pop and append any remaining operators in the stack
    while (!s.empty()) {
        post += s.top();
        s.pop();
    }

    // Output the postfix expression
    cout << post;
    evaluate(post);
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: ";
    infix_postfix(infix);
    cout << endl;

    return 0;
}