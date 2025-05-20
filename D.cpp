#include <iostream>
#include <vector>
#include <string>

int max_substring(const std::string& s) {
    int n = s.length();
    if (n == 0) {
        return 0;  
    }
    std::vector<int> pi(n);  // Prefix function array 
    // Each element represents for the length of longest proper prefix is also suffix
    // Compute prefix function (pi) for the string
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];  // Initialize j with previous prefix length
        
        
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        
        // If match found, extend the prefix length
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;  // Store the computed prefix length
    }

    // Length of smallest possible repeating substring
    int sml = n - pi.back();  
    // This is because the non-overlapping part of the string (after the longest prefix-suffix match) is the smallest unit that can be repeated to reconstruct the string.
    // Check if entire string is made of repetitions
    if (n % sml == 0) {
        return n / sml;  // Return repetition count
    }
    return 1;  // No repetition found
}

int main() {
    // Disable sync for faster I/O (safe for competitive programming)
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::string> inputs;
    std::string s;
    
    // Read input lines until "." is encountered
    while (std::getline(std::cin, s)) {
        if (!s.empty()) {
            // Trim whitespace from both ends
            int start = s.find_first_not_of(" \t\n\r\f\v");
            if (start != std::string::npos) {
                int end = s.find_last_not_of(" \t\n\r\f\v");
                std::string new_s = s.substr(start, end - start + 1);
                
                // Exit condition
                if (new_s == ".") {
                    break;
                }
                
                // Store non-empty trimmed strings
                if (!new_s.empty()) inputs.push_back(new_s);
            }
        }
    }

    // Process each input string
    for (const auto& str : inputs) {
        std::cout << max_substring(str) << '\n';
    }

    return 0;
}