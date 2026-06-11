using char_addres = char *;
class Solution {
public:
void checks_possible_palindrome(char * left_, char * right_, string *longest_pstring)
{

    char *left;
    char *right;

    left = left_;
    right = right_;

    while (left < right)
    {
        //cerr << *left << *right << "\n";
        if (*left == *right)
        {
            ++left;
            --right;
        }
        else return;
    }

    *longest_pstring = string(left_, right_+1);
}

string longestPalindrome(string s)
{

    if (s.size() == 2)
    {
        string sub = (s.size() == 2 && s[0] == s[1]) ? s : string(1, s[0]);
        return sub;
    }

    string longest_pstring = string(1, s[0]);

    char *cota_left;
    char *left;
    char *cota_right;
    char *right;

    size_t window_size_reducer = 0;

    cota_left = &(*(s.begin()));
    cota_right = &(*(s.end()-1));

    left = cota_left;
    right = cota_right;
    size_t total_posible_size=0;

    while (right - left > 0)
    {
        total_posible_size = right-left +1;
        if (total_posible_size <= longest_pstring.size()) return longest_pstring;
        //cerr << total_posible_size << "\n";
        
        while (right <= cota_right)
        {

            // si el substring ya es más pequeño que el actual más grande, se retorna
            if (right-left+1 <= longest_pstring.size()) return longest_pstring;

            checks_possible_palindrome(left, right, &longest_pstring);

            ++left;
            ++right;
        }

        left = cota_left;
        right = cota_right - (++window_size_reducer);
    }

    return longest_pstring;
}
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna