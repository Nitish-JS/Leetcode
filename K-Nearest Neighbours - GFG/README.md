# K-Nearest Neighbours
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:20px">K-Nearest Neighbours is one of the most basic yet essential classification algorithms in Machine Learning. It belongs to the supervised learning domain and finds intense application in pattern recognition, data mining and intrusion detection.</span></p>

<pre><span style="font-size:20px">For Example:
Consider the following table of data points containing two 
features/groups "Red and Green":
<img alt="" src="https://contribute.geeksforgeeks.org/wp-content/uploads/graph1-8.png" style="height:351px; width:608px">
Given another set of data points (testing data), allocate 
these points a feature/group by analyzing the training set.
White Point represents an unclassified point
<img alt="" src="https://contribute.geeksforgeeks.org/wp-content/uploads/graph2-2.png" style="height:363px; width:643px">

<strong>Intuition</strong>
If we plot these points on a graph, we may be able to locate 
some clusters, or groups. Now, given an unclassified point, 
we can assign it to a group by observing what group its 
nearest neighbours belong to. This means, a point close to a 
cluster of points classified as ‘Red’ has a higher probability
of getting classified as ‘Red’.Intuitively, we can see that the
first point (2.5, 7) should be classified as ‘Green’ and the 
second point (5.5, 4.5) should be classified as ‘Red’.
</span></pre>

<p><span style="font-size:20px">Your are required&nbsp;to complete the function <strong>classifyAPoint()</strong>, which should return that to which feature/group will be the test data&nbsp;belong.</span></p>

<p><span style="font-size:20px"><strong>Input:</strong><br>
The function takes four&nbsp;arguments as input, an array of structure <strong>(arr[])</strong> whose each element represents the coordinates and the type of the feature/group to which the point belong, an integer <strong>N </strong>denoting the total number of points, an integer <strong>K </strong>denoting the number of neighbours to consider and an test data (test) whom which needed to be classified.<br>
There will be <strong>T</strong> test cases and for each test case the function will be called separately.&nbsp;&nbsp;<br>
<br>
<strong>Output:</strong><br>
For each test case function should return the group to which the test data would belong.<br>
<br>
<strong>Constraints:</strong><br>
1&lt;=T&lt;=100<br>
1&lt;=N&lt;=100<br>
-100.00&lt;=X,Y&lt;=100<br>
<br>
<strong>Example:<br>
Input:</strong><br>
5<br>
1 2 1 1 3 1 2 3 0 0 1 0 0 0 0<br>
1 1 3<br>
5<br>
1 2 0 1 3 1 2 3 0 0 1 1 0 0 1&nbsp;<br>
1 1 4<br>
<strong>Output:</strong><br>
0<br>
1</span></p>

<p><strong>Note:</strong>The <strong>Input/Ouput</strong> format and <strong>Example</strong> given are used for system's internal purpose, and should be used by a user for <strong>Expected Output</strong> only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.</p>
</div>