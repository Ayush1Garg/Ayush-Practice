<h2><a href="https://practice.geeksforgeeks.org/problems/recamans-sequence4856/1?page=1&difficulty[]=0&difficulty[]=1&difficulty[]=2&status[]=unsolved&category[]=Recursion&sortBy=difficulty">Recamans sequence</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an integer <strong>n</strong>. Print first n elements of&nbsp;<a href="http://mathworld.wolfram.com/RecamansSequence.html">Recaman’s sequence</a>.<br>
It is basically a function with domain and co-domain as natural numbers and 0. It is recursively defined as below:<br>
Specifically, let a(n) denote the (n+1)-th term. (0 being already there).<br>
The rule says:</span></p>

<p><span style="font-size:18px">a(0) = 0<br>
a(n) = a(n-1) - n&nbsp; &nbsp; &nbsp; if a(n-1) - n &gt; 0 and is not already present in the sequence<br>
&nbsp; &nbsp; &nbsp; &nbsp;=&nbsp; a(n-1) + n&nbsp; &nbsp; otherwise. </span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> n = 6
<strong>Output:</strong> 0 1 3 6 2 7
<strong>Explaination:</strong> Follow the rule and this 
will be the output.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> n = 3
<strong>Output:</strong> 0 1 3
<strong>Explaination:</strong> If the rule is followed, 
it will produce this output.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Your task is to complete the function <strong>recamanSequence()</strong> which takes n as the input parameter and returns the sequence.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(n)<br>
<strong>Expected Auxiliary Space:</strong> O(n)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ n ≤ 100</span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Hash</code>&nbsp;<code>Mathematical</code>&nbsp;<code>Recursion</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;