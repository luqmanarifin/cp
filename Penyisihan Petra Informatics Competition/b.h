Counting

Time Limit : 3s

<i>Supervin likes counting. In this problem, he invites you to count together</i>

Supervin has just learned how to count. But he will not be able to count huge numbers. Right now, he only be able to count numbers from 0 to 2M-1. If he encountered a number X which is larger than or equal to 2M, he will consider that number is equal to X % 2M.

He also just learned fibonaci sequence, which is defined as follow.
f(1) = 1
f(2) = 1
f(x) = f(x-1) + f(x-2) for x>=3

He has a set S consists of the first N fibonaci sequence, and would like to separate S into two sets A and B, such that A is a subset of S, and B = S - A. 
He also wants the total of the numbers in both set is equal, according to how he compute.

Given N and M, determine whether it is possible to do so.

Format Input
First line is an integer T (1 <= T <= 200), the number of cases
For each testcases, there will be two integers N and M separated by a space. (1 <= N <= 10^6, 1 <= M <= 10^9)

Format Output
For each case, output "YES" if it is possible to separate S into A and B, or "NO" otherwise.

Sample Input
2
5 2
1 4

Sample Output
YES
NO

Explanation
For the first example, S = {1,1,2,3,1}.
If we choose A = {1,1,3,1} and B = {2}, Supervin will count the total of A is equal to 2, as 6 % 4 = 2. Therefore, the total of the numbers in both set is equal according to Supervin.

In the second example, S = {1} will not be able to be separated.



