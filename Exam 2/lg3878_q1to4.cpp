/*
Luke Gearty
lg3878

1. 
Let P(n) be the proposition that for any positive integen n, 3 divides 
n^3 + 2n evenly.
I. Base Case: P(1)
Plugging in, 1^3 + 2(1) = 3
3 divides 3 evenly

II. Inductive Step:
Let P(k) be the proposition that for any positive integer k, k^3 + 2k is divided by 3 evenly. 
We will prove P(k+1), that is (k+1)^3 + 2(k+1) is also evenly divided by 3.

(k+1)^3 + 2(k+1) =
k^3 + 3k^2 + 3k + 1 + 2(k+1) =
k^3 + 3k^2 + 3k + 1 + 2k + 2 = 
(k^3 + 2k) + 3k^2 + 3k + 3 =
(k^3 + 2k) + 3(k^2 + k + 1)

By the inductive hypothesis, the first part of the equation, k^3 + 2k is divisible by 3. The second part of the equation, 3(k^2 + k + 1) is also divisible by 3, since it is 3 times an integer.

Therefore, if P(k) is true, P(k + 1) is also true.

2a. There are 2^7 total bit strings of length 7.
Bit strings beginning with 00, there are 2^5 remaining spaces.
For bit strings ending with 111, there are 2^4 remaining spaces.

So there are 2^5 + 2^4 bit strings that either start with 00 or end with 111.

2b. There are 9 total spots, 4 men. There are C(9, 4) ways to put the men in their spots, and then 5! ways to distribute the women.
C(9,4) * 5!


3a. Let q be the probability of failure, that is 1 - p
If there are n trials, and there needs to be exactly 1 success, then the probability of 1 success in n trials would be 
C(p, q) * (p)^1 * (q)^(n-1)

3b. 
Let X denote the points
There are seven total outcomes. The prime numbers between 3 and 9 are 3, 5, and 7.
P(+1) = 3/7
P(-1) = 4/7
E[X] = (1 * (3/7) + (-1 * (4/7)) = -1/7

4. For function1, the first while loop, the value of i is being multiplied by 2 each time the loop runs. The inner for loop will until j is the value of i. i can be 1, then 2, then 4, then 8... all the way until the outer while loop ends. 
The two loops together will run 1 + 2 + 4 + ... + n times.

The second two nested loops are the same thing, with the outer loop i being multiplied by 2 until it reaches n, and the inner j being incremented until it reaches the value of i.

Therefore, function1 runs in Theta(n).

In function2, the first for loop runs until i reaches n/2, and it is being increased by 2 each time the loop runs. This loop runs (n/2)

The second outer loop, i is being multiplied by 2 each time. The inner while loop, j is set to i, and is being divided by 2 each time. This loop will run (log n * log n) times, 

T(function2) = Theta(log^2 n)
*/

