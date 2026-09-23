# 📌 C++ STL: Maps & Sets (Cheat Sheet)

## 1. Quick Selector Matrix
* **Map:** Stores `<Key, Value>` pairs. Use it to **count things** or link data (e.g., Name → Phone).
* **Set:** Stores single unique elements. Use it as a **checklist** to find duplicates.

| Container | 2 Data Types? | Speed (per item) | Order of Items |
| :--- | :--- | :--- | :--- |
| **`std::map`** | **Yes** | **\(O(\log n)\)** | Strictly Sorted (A-Z, 0-9) |
| **`std::set`** | **No** | **\(O(\log n)\)** | Strictly Sorted (A-Z, 0-9) |
| **`std::unordered_map`** | **Yes** | **O(1)** (Fastest) | Completely Random |
| **`std::unordered_set`** | **No** | **O(1)** (Fastest) | Completely Random |

---

## 2. Space Complexity
* **All 4 Containers:** **O(n)** space (scales linearly with data size).
* *Note:* Even if you store pairs like `<int, int>` (2n data items), Big-O drops the constant 2 and calls it **O(n)**.

---

## 3. Core Commands

### Maps (`map` & `unordered_map`)
```cpp
mp[key] = value;          // Add/Change data. If key is missing, it auto-starts value at 0!
mp.insert({key, value});  // Add data safely. Fails if key already exists.

if (mp.count(key)) { ... } // Returns 1 if key exists, 0 if it doesn't. (Fast check)
auto it = mp.find(key);    // Finds key position. Returns mp.end() if missing.
// (Use 'find' if you need to read it->second right after, so you don't search twice).

mp.erase(key);  // Delete item
mp.clear();     // Delete everything
```

### Sets (`set` & `unordered_set`)
*⚠️ Sets do **not** support `st[i] = value` because set items are read-only.*
```cpp
st.insert(element);  // Add item. Duplicates are blocked automatically.

if (st.count(element)) { ... } // Returns 1 if present, 0 if missing.
auto it = st.find(element);    // Finds item position. Returns st.end() if missing.

st.erase(element); // Delete item
// To change an item: st.erase(old); then st.insert(new);
```

---

## 4. Key Rules to Remember
* **Direct Comparison (`==`):** You can do `map1 == map2` or `set1 == set2`. C++ checks **all keys and all values**. If they match perfectly, it returns `true` (even if items were added in a different order). Both containers must be the same type.
* **Auto-Zero:** `mpp[arr[i]]++` works perfectly for frequency counting. C++ creates the missing number, sets its count to `0`, and then adds `1`.
* **Sorting Rules:** Ordered versions sort characters by **ASCII** (Uppercase `A-Z` comes *before* lowercase `a-z`) and strings by **dictionary order**. 
* **Tree Bonus:** Only ordered `map` and `set` support `lower_bound()` and `upper_bound()`.
