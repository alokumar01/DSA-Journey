🚀 The 5-Second Trick to Identify Subset / Knapsack Problems

Ask yourself 3 questions.

1️⃣ Is there an array of numbers?
Example:

nums = [2,3,7,8,10]
Almost all subset problems start with a list of numbers.

2️⃣ Do you need to choose some elements?
Keywords interviewers use:

pick / not pick
include / exclude
subset
combination
partition
sign (+ / -)

Example statements:

Choose elements whose sum = target
Split array into equal sum subsets
Assign + or - signs
3️⃣ Is there a target value?

Example:

target = 11
capacity = W
sum = S

If the problem asks something like:

Can we reach this target?
Maximum value within capacity?
Number of ways to reach target?

👉 It is almost always Knapsack / Subset Sum.

🧠 The Master Recursion Pattern

Whenever you see this pattern:

For every element we have two choices
include element
exclude element

That means Subset/Knapsack DP.

Template:

solve(i, target)

include → solve(i-1, target-arr[i])
exclude → solve(i-1, target)