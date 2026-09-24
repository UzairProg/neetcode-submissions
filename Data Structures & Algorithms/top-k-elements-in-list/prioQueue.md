# C++ Priority Queue (Heap) Cheat Sheet

## 1. Core Concepts
*   **What it is:** A container adapter providing constant-time O(1) access to the highest (or lowest) priority element. It implements a **Binary Heap** under the hood.
*   **Traversal Limitation:** You **cannot** iterate through a priority queue using a loop or index. You can only check `top()` and `pop()` elements until it is empty.

## 2. The 3-Argument Anatomy (Under the Hood)
When configuring a custom priority queue, you must follow this exact signature:

```cpp
std::priority_queue< DataType, Container, Comparator >
```

| Parameter | What it represents | The Default Configuration (If you leave it blank) |
| :--- | :--- | :--- |
| **`DataType`** | The type of elements being stored (e.g., `int`, `pair`, custom structs). | *No default. Must always be provided.* |
| **`Container`** | The internal sequence container used to store the memory array. | **`std::vector<DataType>`** |
| **`Comparator`**| The strict weak ordering rule used to determine element priority. | **`std::less<DataType>`** (Creates a **Max-Heap**) |

---

## 3. Syntax Reference Guide

### Max-Heap (Default)
If you provide only one argument, C++ automatically fills in the defaults behind the scenes.
```cpp
// This:
std::priority_queue<int> maxHeap; 

// Is exactly equivalent to this:
std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
```

### Min-Heap (Smallest element on top)
To reverse the behavior, you must explicitly supply all 3 arguments and replace `less` with `greater`.
```cpp
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
```

### Min-Heap of Pairs
Highly utilized in Graph algorithms (Dijkstra) or Top-K tracking.
```cpp
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pairMinHeap;
```

---

## 4. Time Complexities
*   `push()` \(\rightarrow O(\log N)\) (Inserts item and re-heaps)
*   `pop()`  \(\rightarrow O(\log N)\) (Removes top item and re-heaps)
*   `top()`  → O(1)      (Looks at the root item)
*   `size()` / `empty()` → O(1)

---

## 5. Crucial Golden Rules

### Rule A: The Pair Ordering Trap ⚠️
When storing `std::pair<int, int>`, C++ automatically compares the elements by `.first`. It only checks `.second` if there is an exact tie.
* *Action:* Always put the metric you want to sort by into the `.first` slot of your pair.

### Rule B: Custom Sorting (Struct Comparator)
To sort custom objects, pass a struct that overloads the `()` operator. 
* **The Reverse Rule:** In the custom comparator, using `>` creates a **Min-Heap**, while `<` creates a **Max-Heap**.

```cpp
struct Task {
    int id;
    int priority;
};

// We want the absolute lowest priority value on top (Min-Heap)
struct CustomComp {
    bool operator()(const Task& a, const Task& b) {
        return a.priority > b.priority; // '>' swaps elements to put lower values on top
    }
};

// Full declaration syntax:
std::priority_queue<Task, std::vector<Task>, CustomComp> pq;
```

---

## 6. Complete Usage Pattern
```cpp
#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq; // Max-heap by default
    
    pq.push(10);
    pq.push(30);
    pq.push(20);
    
    while (!pq.empty()) {
        std::cout << pq.top() << " "; // Output: 30 20 10
        pq.pop();
    }
}
```
