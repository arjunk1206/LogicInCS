
#include <iostream>
#include <string.h>
using namespace std;

///the macro for size of character stack can be changed, 100 has been set to ensure the stack does not occupy too much space.
#define SIZE 100
/// @brief String to accept infix expression from the user.
string s;
/// @brief An index variable used for counting.
int i=0;
/// @brief An array to store ASCII Values of propositional atoms, to enable us to record truth values for a proposition.
int arr[150];

///A stack class allows us to iteratively store the necessary operators and operands in order to enable expression conversion.
class STACK
{
    private:
        char expression[SIZE]; //default space allocated for expression
        
    public:
        STACK();
        ///Represents index of Top of Stack
        int tos; 
        char push(char);
        char pop();
        int isEmpty();
        int isFull();
        char topElement();
        
};
///constructor of empty stack, default value of tos is -1 to prevent pop being called if empty.
STACK::STACK() 
{
    tos=-1; 
}
/// Method to return top element of stack.
/// @return expression[tos] The top element of stack.
char STACK::topElement()
{
    return expression[tos];   
}
///Verifies if stack is empty.
int STACK::isEmpty()
{
    if(tos==-1)
        return 1;
    else
        return 0;   
}
///Verifies if stack is full.
int STACK::isFull()
{
    if(tos==(SIZE-1))
        return 1;
    else
        return 0;
}
///Adds element to the end of character array.
char STACK::push(char n)
{
    
    ++tos;
    expression[tos]=n;
    return n;
}
/// Removes the last element of the character array used to implement stack.
/// @return temp Refers to the element removed from the stack.
char STACK::pop()
{
    char temp;
    temp=expression[tos];
    --tos;
    return temp;
}
// Stack Implementation Ends



///function to verify whether we have encountered an operator when we iterate through the expression's character.
/// @param c character of a string.
/// @return Truth Value for whether character is an operator or not.
bool checkOperator(char c) 
{
    return (!isdigit(c) && !isalpha(c));
}

///function to determine operator precedence, order is negation > AND/OR > implication
int setPrecedence(char op) 
{
    if (op == '~')
        return 1;
    else if (op == '*' || op == '+')
        return 2;
    else if (op == '>')
        return 3;
    return 0;
}

///Function to convert Infix to Postfix representation.
///
/// @param inorder The function requires a paranthesized in-order expression to be passed through.
/// @attention The parantheses are of critical importance to utilized ordering functions, since the precedence of operators is set accordingly.
string inorderToPostOrder(string inorder)
{
    int l = inorder.size();
    STACK char_stack;  //space to store atoms during traversal
    string output;

    //iterating through the infix expression
    for (int i = 0; i < l; i++) {

        //If element is an atom, we can directly move it to the output string
        if (isalpha(inorder[i]) || isdigit(inorder[i]))
            output += inorder[i];

        // If the scanned character is an ‘(‘, push it to the stack.
        else if (inorder[i] == '(')
            char_stack.push('(');

        // If the scanned character is an ‘)’, pop elements from the char_stack to the output until an ‘(‘ is encountered.
        else if (inorder[i] == ')') {
            while (char_stack.topElement() != '(') {
                output += char_stack.topElement();
                char_stack.pop();
            }

            // removing '(' from the stack
            char_stack.pop();
        }

        // Upon finding an operator
        else
        {
            if (checkOperator(char_stack.topElement()))
            {
                //character found is implication
                if(inorder[i] == '>')
                {
                    while (setPrecedence(inorder[i]) <= setPrecedence(char_stack.topElement())) 
                    {
                        output += char_stack.topElement();
                        char_stack.pop();
                    }
                    
                }
                //other operator found that is greater
                else
                {
                    while (setPrecedence(inorder[i]) < setPrecedence(char_stack.topElement()))
                    {
                        output += char_stack.topElement();
                        char_stack.pop();
                    }
                    
                }

                // push current Operator on stack
                char_stack.push(inorder[i]);
            }
        }
    }

    //putting remaining elements left on the stack into the final expression
    while(char_stack.tos!=-1){
        output += char_stack.topElement();
        char_stack.pop();
    }
    return output;
}

///Function to reverse a string, is used in conversion from Postfix to Prefix Expressions.
/// @return The reversed expression.
string reverseStr(string& expression)
{
    int n = expression.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        {
            char temp;
            temp = expression[i];
            expression[i]= expression[n-i-1];
            expression[n-i-1]=temp;
        }
        return expression;
}

///Function to generate prefix, involves reversing postfix expression. 
///For generating a postfix expression, refer to inordertoPostOrder(string inorder).
///@param inOrder Function accepts an inorder expression as a string.
///@return  Function returns preorder expression as a string.
///@attention The parantheses are of critical importance to utilized ordering functions, since the precedence of operators is set accordingly.

string inorderToPreOrder(string inOrder)
{
    int l = inOrder.size();

    // Reverse infix
    inOrder = reverseStr(inOrder);

    // swapping brackets in the reversed infix expression
    for (int i = 0; i < l; i++) {

        if (inOrder[i] == '(') {
            inOrder[i] = ')';
        }
        else if (inOrder[i] == ')') {
            inOrder[i] = '(';
        }
    }
 
    string preOrder = inorderToPostOrder(inOrder);

    //reverse postfix to generate prefix
    preOrder = reverseStr(preOrder);

    return preOrder;
}

/// Structure to enable construction of a Binary Tree. 
///
/// This will be utilized to generate our parse tree, the left and right nodes can point to subsequent structures in the parse tree.
struct Node{
    
    /// Left Pointer of the tree node.
    Node* left=NULL;
    /// Right Pointer of the tree node.
    Node* right=NULL;
    /// This stores the operator/propositional atom in the expression.
    char data;
    /// This is used to store the truth value of a propoitional atom in the node. It has a default value set to -1.
    int value =-1;
};

/// @brief Function to Determine the height of a binary parse tree, it recursively calls itself till it arrives at a node pointing to a null pointer
/// @param root The function takes a parse tree as input.
/// @return the height of the tree is returned. 
int height(Node *root){
    if(root==NULL){
        return 0;
    }
    int h = max(height(root->left),height(root->right))+1;
    return h;
}
/// @brief This function generates the parse tree recursively.
/// @param root The root of the parse tree used to initialize the tree, the first node, is the root and taken from the preorder expression. s[0]
void tree(Node* root){
    root->data=s[i];
    root->value = arr[root->data];
    bool opr=false;
    if(s[i]=='~'||s[i]=='>'||s[i]=='*'||s[i]=='+') opr = true;
    
    if(!opr){
        i++;
        return ;
    }
    char r=s[i];
    i++;
    if(r=='~'){
        Node* l=new Node();
        root->right=l;
        tree(l);
        return;
    }
    Node* u=new Node();
    root->left=u;
    tree(u);

    Node* q=new Node();
    root->right=q;
    tree(q);
    return;
}

/// @brief Traverses tree in  in-rder and Evaluates the truth value of the propositional atoms, in a bottom up fashion.
/// @param root The root of the binary tree generated is taken as input.
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}

/// @brief Traverses tree in Post Order and evaluates the truth value of the propositional atoms, in a bottom up fashion.
/// @param root The root of the binary tree generated is taken as input.
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left); 
    postorder(root->right);
    cout<<root->data;
    if(root->value == -1 && root->data == '*')
        {
            if (root->left->value == 1 && root->right->value==1) root->value = 1;
            else if(root->left->value == 0 || root->right->value==0) root->value = 0;
        }
    else if(root->value == -1 && root->data == '+')
        {
            if (root->left->value == 1 || root->right->value==1) root->value = 1;
            else if(root->left->value == 0 && root->right->value==0) root->value = 0;
        }
    else if(root->value == -1 && root->data == '>')
        {
            if (root->left->value == 1 && root->right->value==0) root->value = 0;
            else root->value = 1;
        }
    else if(root->value == -1 && root->data == '~')
        root->value = 1 - (root->right->value);
}

///Final Implementation of Developed Functions.
int main()
{

    cout << "Enter your expression in brackets" << endl;

    for (int i = 0; i < 150; ++i)arr[i]=-1;
    cin>>s; //accepting expression input

    cout << "The Prefix form of the expression is " << inorderToPreOrder(s) << std::endl;
    
   
    
    // converting the expression to preorder for tree generation.
    s = inorderToPreOrder(s);       

    Node *root=new Node();

    //Accepting truth values for propositional atoms
    cout<< "Enter Values of Propositional Atoms " << endl;
    //here s should be a preorder string
    for (int i = 0; i < s.size(); ++i)
    {
        if (isalpha(s[i])){
            if (arr[s[i]]==-1)
            {
                cout<<s[i]<<": ";
                cin>>arr[(int)s[i]];
            }
        }
    }

    //Task 2: generating binary parse tree.
    tree(root);
    
    //Task 3: Inorder Traversal of tree.
    cout<<"inorder traversal: ";
    inorder(root);
    cout<<"\n";

    //Task 4: Height of the tree.
    cout<<"height: "<< height(root)<<"\n";
   
    //used for the evaluation of propositional truth table
    cout<<"postorder traversal: ";
    postorder(root);
   
    cout<<"\n";
    
    // Task 5: Evaluation of Expression.
    cout<<"evaluated answer of expression in terms of truth value: "<<root->value<<"\n";
    return 0;
}