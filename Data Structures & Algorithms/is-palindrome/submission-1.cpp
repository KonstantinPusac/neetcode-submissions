#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        // Creating a string with only letters 
        string final = "";
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch >= 'a' && ch <= 'z')
                final += s[i];
            else if (ch >= 'A' && ch <= 'Z')
                final += tolower(s[i]);
            else if (ch >= '0' && ch <= '9')
                final += s[i];
        }

        cout << final << endl;
        
        // Checking palindrome
        int left = 0; int right = final.length() - 1;
        while (left < right)
        {
            if (final[left] != final[right])
                return false;

            left++; right--;
        }

        return true;
    }
};
