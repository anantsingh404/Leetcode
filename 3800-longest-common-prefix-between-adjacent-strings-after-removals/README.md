<h2><a href="https://leetcode.com/problems/longest-common-prefix-between-adjacent-strings-after-removals">Longest Common Prefix Between Adjacent Strings After Removals</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given an array of strings <code>words</code>. For each index <code>i</code> in the range <code>[0, words.length - 1]</code>, perform the following steps:</p>

<ul>
	<li>Remove the element at index <code>i</code> from the <code>words</code> array.</li>
	<li>Compute the <strong>length</strong> of the <strong>longest common <span data-keyword="string-prefix">prefix</span></strong> among all <strong>adjacent</strong> pairs in the modified array.</li>
</ul>

<p>Return an array <code>answer</code>, where <code>answer[i]</code> is the length of the longest common prefix between the adjacent pairs after removing the element at index <code>i</code>. If <strong>no</strong> adjacent pairs remain or if <strong>none</strong> share a common prefix, then <code>answer[i]</code> should be 0.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">words = [&quot;jump&quot;,&quot;run&quot;,&quot;run&quot;,&quot;jump&quot;,&quot;run&quot;]</span></p>

<p><strong>Output:</strong> <span class="example-io">[3,0,0,3,3]</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Removing index 0:
	<ul>
		<li><code>words</code> becomes <code>[&quot;run&quot;, &quot;run&quot;, &quot;jump&quot;, &quot;run&quot;]</code></li>
		<li>Longest adjacent pair is <code>[&quot;run&quot;, &quot;run&quot;]</code> having a common prefix <code>&quot;run&quot;</code> (length 3)</li>
	</ul>
	</li>
	<li>Removing index 1:
	<ul>
		<li><code>words</code> becomes <code>[&quot;jump&quot;, &quot;run&quot;, &quot;jump&quot;, &quot;run&quot;]</code></li>
		<li>No adjacent pairs share a common prefix (length 0)</li>
	</ul>
	</li>
	<li>Removing index 2:
	<ul>
		<li><code>words</code> becomes <code>[&quot;jump&quot;, &quot;run&quot;, &quot;jump&quot;, &quot;run&quot;]</code></li>
		<li>No adjacent pairs share a common prefix (length 0)</li>
	</ul>
	</li>
	<li>Removing index 3:
	<ul>
		<li><code>words</code> becomes <code>[&quot;jump&quot;, &quot;run&quot;, &quot;run&quot;, &quot;run&quot;]</code></li>
		<li>Longest adjacent pair is <code>[&quot;run&quot;, &quot;run&quot;]</code> having a common prefix <code>&quot;run&quot;</code> (length 3)</li>
	</ul>
	</li>
	<li>Removing index 4:
	<ul>
		<li>words becomes <code>[&quot;jump&quot;, &quot;run&quot;, &quot;run&quot;, &quot;jump&quot;]</code></li>
		<li>Longest adjacent pair is <code>[&quot;run&quot;, &quot;run&quot;]</code> having a common prefix <code>&quot;run&quot;</code> (length 3)</li>
	</ul>
	</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">words = [&quot;dog&quot;,&quot;racer&quot;,&quot;car&quot;]</span></p>

<p><strong>Output:</strong> <span class="example-io">[0,0,0]</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Removing any index results in an answer of 0.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10<sup>4</sup></code></li>
	<li><code>words[i]</code> consists of lowercase English letters.</li>
	<li>The sum of <code>words[i].length</code> is smaller than or equal <code>10<sup>5</sup></code>.</li>
</ul>
