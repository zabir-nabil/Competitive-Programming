# Editorial

---------------------------------------------------------------------------------------------

## Problem A

> Tags : Bitmask, permutation, sieve

> Difficulty : Easy

**Solution idea :**

 * Generate all possible numbers from the 'digit list' and check if it's prime.
 * To generate all possible numbers, first use bitmask to choose a set of digits and then permute them.
 
*In my case, Bitwise sieve was too slow to pass*
   
   
   
---------------------------------------------------------------------------------------------

## Problem B

> Tags : Segment tree, parenthesis property

> Difficulty : Easy - medium

**Solution idea :**

 * Lets define a property *P* for a balanced parenthesis.
 * Before that, say, an opening bracket == '(' == -1 and a closing bracket == ')' == 1
 * Check some cases, SUM { () } = -1 + 1 = 0; SUM { ()()(()()) } = -1 +1 -1 +1 -1 -1 +1 -1 +1 +1 = 0
 * It's obvious, for a balanced parenthesis *p* SUM { *p* } = 0
 * But, SUM { ())( } = -1 +1 +1 -1 = 0, but it's not balanced.
 * A closing bracket shouldn't appear before the appearance of it's opening counterpart. 
 * Study, the cumulative sum at each point and it can observed that, for a balanced parenthesis *cum_sum[i] <= 0*
 * Now, lets come to the solution.
 * There are four cases, 1. replace '(' with '(' -> No change in the parenthesis, so ans = Y
 * 2. replace ')' with ')' -> No change in the parenthesis, so ans = Y 
 * 3. replace ')' with '(' -> say, paren[i] = ')' and paren[j] = '(' where, *i < j*
      from property *P*, if an opening bracket replaces a closing bracket at *i*, then cum_sum[i] will decrease by 1, and cum_sum[j] will be unchanged
	  so, ans = Y
	  
 * 4. replace '(' with ')' -> This is a tricky case, after testing some cases you can see, for this case, cum_sum increases in the range [i,j-1] by 2.
      so, if in the interval [i,j-1] there exists some $i$ such that cum_sum[i]>-2 then, after swapping, we will have positive cumulative sum there
	  making ans = N
 * To, check if there's a number greater than -2 in the range [i,j] efficiently you can use a segment tree/sparse table.
 * Build segment tree with each node keeping max{..cum_sum[i]..}
     
   
---------------------------------------------------------------------------------------------

## Problem C

> Tags : Dfs and similar

> Difficulty : Medium

**Solution idea :**



---------------------------------------------------------------------------------------------

## Problem D

> Tags : Modular arithmetic

> Difficulty : Easy

**Solution idea :**

 * Keep a cumulative sum % MOD array 
 * Keep a map/array and mark exists[0] = 1;
 * Now, for each value in the array, ans += exists[value]; exists[value]++;
 
 
---------------------------------------------------------------------------------------------

## Problem E

> Tags : Simulation

> Difficulty : Easy

**Solution idea :**

 * Just simulate
 
 
 
---------------------------------------------------------------------------------------------

## Problem F

> Tags : Graph

> Difficulty : Easy

**Solution idea :**

 * Just check the given properties
 
 
---------------------------------------------------------------------------------------------

## Problem J

> Tags : Combinatorics, counting

> Difficulty : Medium

**Solution idea :**

 * At first lets see some cases,
 
```
     n = 3, '456'
     i |  j  |  number
	 1    1       456
	 1    2       546
	 1    3       654
	 2    2       456
	 2    3       465
	 3    3       456
	 ----------------
	       sum = 3033
```

   