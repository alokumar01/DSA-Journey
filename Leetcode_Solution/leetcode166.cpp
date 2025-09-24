#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // Step 1: Handle zero numerator
        if (numerator == 0) return "0";

        string result;

        // Step 2: Handle the sign
        // If one is negative (but not both), answer is negative
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }

        // Step 3: Convert to long long (to avoid overflow)
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        // Step 4: Add the integer part (before the decimal point)
        result += to_string(n / d);

        // Step 5: Find remainder after integer division
        long long remainder = n % d;
        if (remainder == 0) {
            // If perfectly divisible, return result
            return result;
        }

        // Step 6: Add decimal point for fractional part
        result += ".";

        // Step 7: Map to store remainders and their position in result string
        // Key = remainder, Value = position in result where it first appeared
        unordered_map<long long, int> remainderPosition;

        // Step 8: Long division simulation
        while (remainder != 0) {
            // If we already saw this remainder, it's repeating
            if (remainderPosition.count(remainder)) {
                int pos = remainderPosition[remainder];
                result.insert(pos, "("); // insert '(' where repetition started
                result += ")";           // add ')' at the end
                break;
            }

            // Store current remainder position
            remainderPosition[remainder] = result.size();

            // Multiply remainder by 10 (long division step)
            remainder *= 10;

            // Append quotient digit to result
            result += to_string(remainder / d);

            // Update remainder
            remainder %= d;
        }

        return result;
    }
};

// How to Explain to Your Junior
// Handle simple cases first:

// If numerator = 0 → answer is "0".

// If denominator divides evenly → just return integer part.

// Take care of negative signs:

// Use XOR ^ to check if signs differ.

// Use long long:

// To avoid overflow when numerator = INT_MIN and denominator = -1.

// Do integer division:

// Example: 4/333 = 0, remainder = 4.

// Save "0" in result.

// Simulate long division:

// Multiply remainder by 10 each time.

// Divide by denominator → gives next digit.

// Keep updating remainder.

// Detect repeating decimals:

// If the same remainder appears again → decimal part starts repeating.

// Insert ( at the first occurrence, and ) at the end.

//  Example Walkthrough (numerator = 4, denominator = 333)
// 4 / 333 = 0 → result = "0", remainder = 4.

// Add "." → "0.".

// remainder = 4 → multiply by 10 = 40 → 40 / 333 = 0, remainder = 40.
// → result = "0.0".

// remainder = 40 → multiply by 10 = 400 → 400 / 333 = 1, remainder = 67.
// → result = "0.01".

// remainder = 67 → multiply by 10 = 670 → 670 / 333 = 2, remainder = 4.
// → result = "0.012".

// remainder = 4 again! Already seen at step 3 → repeating starts here.
// Insert ( before first 012 and ) at end → "0.(012)".

// Output examples:

// 1/2 → "0.5"

// 2/1 → "2"

// 4/333 → "0.(012)"

// 1/6 → "0.1(6)"