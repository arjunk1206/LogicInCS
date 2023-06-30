@page TASC Time and Space Complexity of Algorithms
@tableofcontents

The time and space complexity of our algorithms can be explained through the number of operations required in each task, proportional to the elements of the input.

@section listoftasks Analysis

## Task 1: Converting an infix propositional logic expression to prefix form

The **time complexity** of the algorithm to convert infix to prefix form is dependent on the number of elements in the input expression. As we iterate through the string in a single for loop, and functions such as STACK::push(char a) and STACK::pop() are independent of the input. *We can state that the time taken by the algorithm is linearly dependent on number of elements in the expression.*

Since the stack implementation in our program is based on a predefined character array of a size dependent on a macro. The *auxillary space used by the algorithm is constant*.

## Task 2: Converting A Prefix Expression to a Binary Parse Tree

The **time complexity** of the algorithm to generate a binary parse tree from a prefix expression, assuming the input is in prefix format will be *linearly dependent on the number of elements in the expression*. Since the expression is scanned iteratively through a for loop, and then the tree is generated through each subsequent node from the root. 

With respect the the **space complexity** of the algorithm, the *space taken by the generated tree **linearly depends** on its height*. This is because subsequent nodes will keep being generated recursively till we reach a node that points only to propositional atoms.


## Task 3: In-Order Traversal of Parse Tree

The **time complexity** of the traversal of a parse tree will depend on the number of nodes in the tree, since the function is called recursively on each node. Thus, *the time taken by the algorithm **linearly depends** on the number of inputs in the expression, since the tree takes each input as a node*.

Whenever an operation is done on a  tree, the **space complexity** of the algorithm *depends on the height, which is a **linear function** of the number of characters in the expression* since, the tree is generated recursively each time.

## Task 4: Height of the Parse Tree

The **time complexity** of the height algorithm depends on the number of nodes in the tree, since the function is called recursively on the node with the maximum height. Thus, *the time taken by the algorithm **linearly depends** on the number of inputs in the expression, since the tree takes each input as a node*.

The **space complexity** of the algorithm *depends on the height of the tree itself, which is a **linear function** of the number of characters in the expression* since, the tree is generated recursively each time in the programming stack.


## Task 5: Evaluation of Propositional Logic Formula

Similiar to Task 3, the **time complexity** of evaluation of propositional atoms will depend on the number of nodes in the tree, since the algorithm used involves Post-Order Traversal, and evaluation begins at the bottom nodes of the tree. Thus, *the time taken by the algorithm **linearly depends** on the number of inputs in the expression*.

The **space complexity** of the algorithm *depends on the height, which is a **linear function** of the number of characters in the expression* since, the tree is generated recursively each time.
