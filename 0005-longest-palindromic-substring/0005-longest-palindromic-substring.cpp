using char_addres = char *;
class Solution {
public:
void checks_possible_palindrome(char * left_, char * right_ , char **left_solution, char** right_solution)
{

    char *left;
    char *right;

    left = left_;
    right = right_;

    while (left < right)
    {
        if (*left == *right)
        {
            ++left;
            --right;
        }
        else return;
    }

    *left_solution = left_;
    *right_solution = right_;

    //*longest_pstring = string(left_, right_+1);
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
    
    char *left_current_solution= cota_left;
    char *right_current_solution = cota_left;
    
    left = cota_left;
    right = cota_right;

    size_t total_posible_size=right-left+1;
    size_t current_solution_size=right_current_solution - left_current_solution+1;

    while (right - left >= 0)
    {
        total_posible_size = right-left+1;
        
        
        if (total_posible_size <= current_solution_size) return string(left_current_solution, right_current_solution+1);
        
        
        while (right <= cota_right)
        {
            //cerr << "substring a checar " << substring << " contra el más grande " << longest_pstring <<"\n";

            // si el substring ya es más pequeño que el actual más grande, se retorna
            if (right-left+1 <= current_solution_size) return string(left_current_solution, right_current_solution+1);

            checks_possible_palindrome(left, right, &left_current_solution, &right_current_solution);
            current_solution_size = right_current_solution - left_current_solution+1;
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