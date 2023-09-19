<h2><a href="https://leetcode.com/problems/couples-holding-hands/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Bloomberg</div><div class="companyTagsContainer--tagOccurence">2</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>765. Couples Holding Hands</a></h2><h3>Hard</h3><hr><div><p>There are <code>n</code> couples sitting in <code>2n</code> seats arranged in a row and want to hold hands.</p>

<p>The people and seats are represented by an integer array <code>row</code> where <code>row[i]</code> is the ID of the person sitting in the <code>i<sup>th</sup></code> seat. The couples are numbered in order, the first couple being <code>(0, 1)</code>, the second couple being <code>(2, 3)</code>, and so on with the last couple being <code>(2n - 2, 2n - 1)</code>.</p>

<p>Return <em>the minimum number of swaps so that every couple is sitting side by side</em>. A swap consists of choosing any two people, then they stand up and switch seats.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> row = [0,2,1,3]
<strong>Output:</strong> 1
<strong>Explanation:</strong> We only need to swap the second (row[1]) and third (row[2]) person.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> row = [3,2,0,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> All couples are already seated side by side.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2n == row.length</code></li>
	<li><code>2 &lt;= n &lt;= 30</code></li>
	<li><code>n</code> is even.</li>
	<li><code>0 &lt;= row[i] &lt; 2n</code></li>
	<li>All the elements of <code>row</code> are <strong>unique</strong>.</li>
</ul>
</div>