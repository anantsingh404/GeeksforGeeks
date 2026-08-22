class Solution {
  public:
    vector<string> findPrefixes(vector<string>& arr) {
        unordered_map<std::string, int> prefix_count;

                    // Step 1: Populate the map with counts of all possible prefixes
                    for (const std::string& word : arr) {
                        std::string current_prefix = "";
                        for (char ch : word) {
                            current_prefix += ch;
                            prefix_count[current_prefix]++;
                        }
                    }

                    std::vector<std::string> result;

                    // Step 2: For each word, find its shortest prefix with a frequency of 1
                    for (const std::string& word : arr) {
                        std::string current_prefix = "";
                        for (char ch : word) {
                            current_prefix += ch;
                            if (prefix_count[current_prefix] == 1) {
                                result.push_back(current_prefix);
                                break;
                            }
                        }
                    }

                    return result;
        
    }
};