class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();

        // 'start' = starting index of the longest palindrome found
        int start = 0;
        int maxlen = 1;

        // We consider EVERY index as a possible center
        // i = 0, 1, 2, ... and we try each position as a
        // possible center of a palindrome.
        for (int i = 0; i < n; i++) {

            // Case 1: ODD length palindrome
            
            int len1 = expand(s, i, i);


            // Case 2: EVEN length palindrome
          
            // Therefore left = i and right = i + 1.
            int len2 = expand(s, i, i + 1);

            // For this particular center i,
            // choose whichever palindrome is longer:
            // odd palindrome or even palindrome.
            int len = max(len1, len2);

            if (len > maxlen) {

                maxlen = len;

               
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxlen);
    }


   
    int expand(string& s, int l, int r) {

      
        while (l >= 0 &&
               r < s.size() &&
               s[l] == s[r]) {

           
            l--;

            r++;
        }

        // When the while loop stops, l and r have already
        // moved ONE step outside the actual palindrome.
        //
        // Example:
        //
        // String:  b a b
        //          0 1 2
        //
        // After matching "bab":
        //
        // l = -1
        // r = 3
        //
        // So palindrome length is:
        //
        // r - l - 1
        // = 3 - (-1) - 1
        // = 3
        //
        // Hence return the length of the palindrome.
        return r - l - 1;
    }
};