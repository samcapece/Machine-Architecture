Name: Samuel Capece

You should assume the following:
 * the letter grid parameter has width W and height H.
 * The word parameter has length L.
 * concatenating a letter to a string takes O(1) time
 * the get_size function takes O(1) time
 * accessing a list by index takes O(1) time

Your task:

#Q1
What is the Big-O runtime of the extract function in terms of W, H, and L (defined above)
O(c + L + c) -> remove c -> O(L) -> convert to N
 = O(N)

In my function I used an exception to get rid of the need to use length and width. So there was just a for loop with
the range between 0 and the max length and two if statements. Meaning there were two constants and a linear complexity function

(Please attempt to explain your reasoning. An incorrect answer with no stated reasoning will not be suject to partial credit)

#Q2 
What is the Big-O runtime of the find function in terms of W, H, and L (defined above)
O(H(W(c(L(2c))) -> remove c -> O(H(W(L))) -> convert to N
 = O(N^3)

There are three for loops nested together in my function meaning that the complexity could reach N * N * N
the first takes checks the rows, the second checks the columns, and the third checks the solution using the length and direction,
this means the complexity is cubic (or at least I assume that is the name).


(Please attempt to explain your reasoning. An incorrect answer with no stated reasoning will not be suject to partial credit)
