class Solution {
public:
    // Function to reverse words in a given string.
    std::string reverseWords(std::string &s) {
        std::stringstream ss(s);
        std::vector<std::string> words;
        std::string word;

        // Step 1: Split string into words
        while (ss >> word) {
            words.push_back(word);
        }

        // Step 2: Reverse the vector of words
        std::reverse(words.begin(), words.end());

        // Step 3: Join them back into a single string
        std::string result;
        for (size_t i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i != words.size() - 1) {
                result += " ";
            }
        }

        return result;
    }
};
