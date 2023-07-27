# Thief trying to escape
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">A thief trying to escape from a jail has to cross <strong>N</strong>&nbsp;walls whose heights&nbsp;are given in&nbsp;<strong>arr[]</strong> each with varying heights. He climbs <strong>X</strong> feet every time. But, due to the slippery nature of those walls, every time he slips back by <strong>Y</strong>&nbsp;feet. &nbsp;Now the task is to calculate the total number of jumps required to cross all walls and escape from the jail.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> X = 10, Y = 1, N = 1
arr = {5}
<strong>Output:</strong> 1
<strong>Explaination:</strong> He jumps 10 feet and cross 
the walls.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> X = 4, Y = 1, N = 5
arr = {6, 9, 11, 4, 5}
<strong>Output:</strong> 12
<strong>Explaination:</strong> He will have to jump 2, 3, 4, 1 
and 2 times to cross all the walls.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Your task is to complete the function <strong>totalJumps()</strong> which takes X, Y, N, and arr as input parameters and returns the total number of jumps to cross all the walls.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤&nbsp;N ≤ 100<br>
X &gt; Y<br>
1 ≤ arr[i], X, Y ≤ 1000&nbsp;&nbsp;</span></p>
</div>