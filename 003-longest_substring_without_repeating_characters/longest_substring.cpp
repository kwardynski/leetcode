#include <iostream>
#include <string>
#include <set>
#include <list>

using namespace std;


void substring_counter(string str) {

    size_t ptr_left = 0;            // left pointer -> beginning of substring
    size_t ptr_right = 0;           // right pointer -> end of substring
    size_t longest_substring = 0;   // longest substring encountered so far
    char current_char;              // current character being inspected (right pointer location)
    set<char> substring_chars;      // container to store characters of current substring

    while (ptr_right < str.length()) {
        
        current_char = str[ptr_right];
        
        // If character not yet encountered, add it to the set and increment ptr_right
        if (substring_chars.find(current_char) == substring_chars.end()){
            substring_chars.insert(current_char);
            ++ptr_right;
        }

        // If character already encountered, slide ptr_left up the string, removing the characters it
        // sees until the character is removed
        else {
            while (substring_chars.find(current_char) != substring_chars.end()) {
                substring_chars.erase(str[ptr_left]);
                ++ptr_left;
            }
        }

        // Compare surrent substring length and update as necessary
        if (ptr_right - ptr_left > longest_substring) {
            longest_substring = ptr_right - ptr_left;
        }
    }
    
    // Display results
    cout << "The longest substring of unique letters in \"" << str << "\" is " << longest_substring << " character(s) long" << endl;
}


int main() {

    list<string> word_list = {
        "abcabcbb",
        "bbbbb", 
        "pwwkew",
        "grapeape"};

    for (const auto& word : word_list) {
        substring_counter(word);
    }
    
    return 0;
}