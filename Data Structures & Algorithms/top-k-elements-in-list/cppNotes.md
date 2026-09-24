# C++ Map & Unordered_Set Cheat Sheet

### 1. Unique Elements (`unordered_set`)
* **Behavior:** Duplicate insertions are completely ignored.
* **Underlying Structure:** Hash table.
* **Complexity:** O(1) average time for insertion/lookup.

```cpp
unordered_set<string> s;
s.insert("2"); // Inserted. Size = 1. Returns {iterator, true}
s.insert("2"); // Ignored.  Size = 1. Returns {iterator, false}
```

---

### 2. Map Sorting Order (`map`)
* **Behavior:** Keys are automatically sorted.
* **Underlying Structure:** Red-Black Tree (Self-balancing BST).
* **Complexity:** O(log n) time for insertion/lookup.
* **Performance Cost:** `greater<T>` incurs **zero** extra time or space overhead compared to default sorting.

```cpp
// Default: Ascending Order (1 to 9 / A to Z)
map<int, string> asc_map;

// Custom: Descending Order (9 to 1 / Z to A)
map<int, string, greater<int>> desc_map;
map<string, int, greater<string>> desc_string_map; // Z to A (ASCII based)
```

---

### 3. Iterating Backwards
Reverse iteration reads data from back to front with **zero** extra time or space overhead (lazy evaluation).

#### The Clean C++20 Way (No `::` Syntax)
Requires `#include <ranges>` and `using namespace views;`.

```cpp
using namespace std;
using namespace views;

map<int, string> my_map = {{1, "A"}, {2, "B"}};

// Loops backwards automatically using structured binding
for (const auto& [key, value] : reverse(my_map)) { //or views::reverse
    cout << key << ": " << value << "\n";
}
```

#### The Legacy Way (C++11 / C++14)
Uses constant reverse iterators if C++20 views are not supported.

```cpp
for (auto it = my_map.crbegin(); it != my_map.crend(); ++it) {
    cout << it->first << ": " << it->second << "\n";
}
```
