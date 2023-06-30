@page Algorithm Algorithm Details
@tableofcontents

This is a program to validate a proof sequence. We are taking our input and storing it in an array  of vectors. Each element of a vector is a string. we have used a loop to find a delimiter, here \ to enter data into the vectors.
We used function calcIndex(string s,char c) to find the index of the outermost operand. 
We calculate the variable  \p prem, which is the count of premises.
We used string manipulation and appending to compare the correct sequent to the given sequent.

@section rulewisesplit Rules 

## AND Introduction

Test case line looks like this:
**(a^b)/^i/1/2** is an entry in the array, which is being stored in the vector, a temporary string \p temp is created.

*temp = "(" + (string)arr[1][0] + "^" + arr[2][0] + ")";*  which is compared with the 0th Element of the Test Case Vector.

## AND Elimination

A priority function calcIndex(string s,char c) is used to select the outermost and symbol. For ^e1, the substring till that ^ is compared by dropping the first. (For ^e2, the substring after ^ is compared by popping the last ).


## OR Introduction

If it's **v1** the left half of the test case after dropping the first '(' is compared to the string *(string)arr[2][0]*.

If it's **v1** the left half of the test case after dropping the first '(' is compared to the string *(string)arr[2][0]*.


## Implication Elimination

**(a)/>e/1/2** is an entry in the array, which is being stored in the vector, a temporary string \p temp is created.

*temp = "(" + (string)arr[2][0] + "^" + a + ")";*  which is compared with the 0th Element of the Test Case Vector.

## Modus Tollens
**(~a)/MT/1/2**
In Modus Tollen, we dissected the *arr[1][0]* into 2 temporary strings and checked if the right half's negation exists at position 'a' and the negation of the substring before > is the test case.


Here is an image of our algorithm

## Future Implementation

The code can be easily expanded to double negation elimination, or elimination.

In all the pure assumption type formal proofs, or elimination based can be done as both assumptions are given in the line. The boxes can be tracked using a counter variable like we have done in our calc index.

LEM can be used since LEM is also a type of Or elimination

