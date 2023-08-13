<h2><a href="https://practice.geeksforgeeks.org/problems/mountain-subarray-problem/1?page=1&difficulty[]=0&difficulty[]=1&status[]=unsolved&category[]=Arrays&category[]=Recursion&sortBy=difficulty">Mountain Subarray Problem</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">We are given an array of integers and a range, we need to find whether the subarray which falls in this range has values in the form of a mountain or not. All values of the subarray are said to be in the form of a mountain if either all values are increasing or decreasing or first increasing and then decreasing. More formally a subarray [a1, a2, a3 … aN] is said to be in form of a mountain if there exists an integer K, 1 &lt;= K &lt;= N such that,<br>
a1 &lt;= a2 &lt;= a3 .. &lt;= aK &gt;= a(K+1) &gt;= a(K+2) …. &gt;= aN<br>
You have to process <strong>Q</strong>&nbsp;queries. In each query you are given two integer <strong>L</strong> and <strong>R,&nbsp;</strong>denoting starting and last index of the subarrays respectively.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 8
a[] = {2,3,2,4,4,6,3,2}
Q = 2
Queries = (0,2), (1,3)
<strong>Output:
</strong>Yes
No<strong>
Explanation: </strong>For L = 0 and R = 2, a0 = 2,
a1 = 3 and a2 = 2, since they are in the
valid order,answer is Yes.
For L = 1 and R = 3, a1 = 3, a2 = 2 and
a3 = 4, since a1 &gt; a2 and a2 &lt; a4 the
order isn't valid, hence the answer is
No.</span>
</pre>

<p><span style="font-size:18px"><strong>Your Task:</strong></span></p>

<p><span style="font-size:18px">Complete the function&nbsp;<strong>processQueries()&nbsp;</strong>which takes the array, size of array queries and number of queries as parameter. It should return a vector/ArrayList/array (depending upon language cpp/Java/Python) of boolean values, true if the subarray is in mountain form, false otherwise. The driver code will print "Yes" if the returned value is true, otherwise "No".</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N + Q).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(N).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N, Q &lt;= 10<sup>5</sup><br>
1 &lt;= a[i] &lt;= 10<sup>6</sup>, for each valid i<br>
0 &lt;= L &lt;= R &lt;= N-1</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Data Structures</code>&nbsp;