#include <iostream>
using namespace std;

typedef long long ll;  

ll a, b, c;  

// Function f(p) that defines the sequence 
ll f(ll p) {
    return (a * p + (p % b)) % c; 
}

int main() {
   
    cin >> a >> b >> c;
    
    // Ensure a is positive (for modulo operation)
    if (a < 0) a = (a % c + c) % c;

    // FLOYD'S CYCLE FINDING'S ALGORITHM:

    // Initialize two pointers: slow and fast pointers for finding cycle
    ll slow = f(1);      // First element in sequence
    ll fast = f(f(1));   // Second element in sequence
    int steps = 0;       // Counter for cycle detection

    // Runs for max 2,000,000 steps to prevent infinite loops
    for (; steps < 2000000; ++steps) {
        if (slow == fast) break;  // Cycle detected
        slow = f(slow);           // Move slow pointer one step
        fast = f(f(fast));        // Move fast pointer two steps
    }
    
    // If no cycle found within the limit
    if (steps == 2000000) {
        cout << "-1\n";  // Output -1 indicating no cycle
        return 0;
    }

    // Find the starting index of the cycle
    slow = 1;            // Reset slow to beginning
    int index = 0;       // Counter for prefix length
    while (slow != fast) {
        slow = f(slow);  // Move both pointers one step
        fast = f(fast);  // until they meet again, because by the proof of algorithm, they will at the start point of the cycle
        index++;
    }
    
    // Calculate cycle length
    int count = 1;
    ll p = f(slow);      // Start from first cycle element
    while (p != slow) {  // Count until we complete the cycle
        p = f(p);
        count++;
    }
    
    // Output length (prefix + cycle)
    cout << count + index << "\n";
    return 0;
}