@mainpage Assignment Details
@tableofcontents

@section groupMembers Group Members

* Arjun Khandelwal - 2020B3A70848H
* Kanagarla Kushal Anurag - 2020B4A72168H
* Shreyash Mahapatra - 2020B3A71167H
* Jubil N S - 2020B3A70691H

@section taskDetails Task Details

Here is a brief overview of the programming oriented tasks in the assignment. For specifics regarding code implementation, please peruse through the code files, which can provide more clarity pertaining to the implementation. Also for further details pertaining to the classes and functions, please peruse through them as presented in the documentation. For information pertaining to the time and space complexity of the algorithms, please see the page for more: @ref TASC 

## Task 1: Converting an infix propositional logic expression to prefix form
This task has been performed through the implementation of a character stack. Please view the Stack Class Documentation to see the methods and their required functioning. The other functions defined for the conversion are setPrecedence() and reverseStr(string &expression). The conversion takes place through the function inordertoPreOrder(string inorder) which requires the initial conversion of the logic expression into postfix form (operators after propositional atoms), done by inorderToPostOrder(string inorder) and then performs additional operations to get the desired result.

## Task 2: Converting A Prefix Expression to a Binary Parse Tree
Through the preorder expression generated in task 1. We can now generate a Binary Parse Tree using the struct Node() and then applying the function tree(Node* root). The Tree generated can be verified for its existence through in-order and post-order traversal functions.

## Task 3: In-Order Traversal of Parse Tree
Upon generation of the parse tree, we can traverse it in order through recursively calling the function inorder(Node* root), on the left node, printing the data of the root and then calling the function again on the right node.

## Task 4: Height of the Parse Tree
The height of a parse tree is measured by recursively calling the function on the maximum height of each node of the root. Upon each successive recursive call, an increment of 1 is done to obtain the height. The function we have defined for this purpose is height(Node* root).


## Task 5: Evaluation of Propositional Logic Formula
After accepting the truth values of the propositional atoms in the string. When we apply post order traversal to the tree, we are simultaneously evaluating the sub-expressions of the tree in a bottom-up fashion. As we move up the tree recursively, we are able to assign a value to the root of the tree, thus giving us the truth value of the expression. The function utilized for this task is postorder(Node* root).

