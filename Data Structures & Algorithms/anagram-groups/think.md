# 049. Group Anagrams

### 💡 The Core Intuition
An anagram is just a word with the same letters shuffled. Think of it like a grocery recipe:
- `"eat"` = 1 `a`, 1 `e`, 1 `t`
- `"tea"` = 1 `a`, 1 `e`, 1 `t`

No matter the letter order, the **recipe** is identical. If we turn that recipe into a unique label (**fingerprint**), all matching words can be dropped into the same folder in a hash map:
`{ fingerprint -> [words] }`

---

### 🛠️ The 2 Approaches

| Approach | How the Fingerprint is Made | Time | Space | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **1. Sort Each String** | Sort letters alphabetically (`"eat"` $\to$ `"aet"`) | $O(N \cdot K \log K)$ | $O(N \cdot K)$ | Simple, standard interview choice. |
| **2. 26-Letter Count** | Count frequencies of `a-z` (`[1, 0, ..., 1, ...]`) | $O(N \cdot K)$ | $O(N \cdot K)$ | Faster if words are very long ($K$ is large). |

*($N$ = number of words, $K$ = max word length)*

---

### ⚠️ Traps to Avoid
1. **Length check fails:** `"cat"` and `"dog"` have the same length but are not anagrams. Length alone cannot be the key.
2. **Copying strings:** Looping `for (string s : strs)` creates expensive copies. Always use `for (const string& s : strs)`.
3. **Delimiter issue (Count method):** Converting counts `[1, 11]` and `[11, 1]` both become `"111"` without separators. Separate counts with a delimiter (e.g., `#` or `,`).

---

### 💻 Reference Solution (Sorting Pattern)

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }

        vector<vector<string>> result;
        result.reserve(groups.size());
        for (auto& [_, group] : groups) {
            result.push_back(move(group));
        }

        return result;
    }
};
