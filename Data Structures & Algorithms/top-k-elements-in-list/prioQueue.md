# C++ Priority Queue (Heap) Cheat Sheet

## 1. Core Concepts
*   **What it is:** A container adapter that provides constant-time O(1) access to the highest (or lowest) priority element. It implements a **Binary Heap** under the hood.
*   **Default Behavior:** Max-Heap (largest element is always at the top).
*   **Traversal Limitation:** You **cannot** use a standard loop or iterators to look through a priority queue. You must check `top()` and `pop()` until it is empty.

## 2. Time Complexities
*   `push()` \(\rightarrow O(\log N)\) (Inserts item and re-heaps)
*   `pop()`  \(\rightarrow O(\log N)\) (Removes top item and re-heaps)
*   `top()`  → O(1)      (Looks at the root item)
*   `size()` / `empty()` → O(1)

---

## 3. Syntax Reference Guide

### Max-Heap (Default)
```cpp
std::priority_queue<int> maxHeap; // Largest int is at the top
```

### Min-Heap (Smallest element on top)
Requires the full 3-argument signature: `<DataType, Container, Comparator>`.
```cpp
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
```

### Min-Heap of Pairs
Highly used in Graph algorithms (Dijkstra) or Top-K tracking.
```cpp
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pairMinHeap;
```

---

## 4. Crucial Golden Rules

### Rule A: The Pair Ordering Trick ⚠️
When storing `std::pair<int, int>`, C++ automatically compares the elements by `.first`. It only checks `.second` if there is a tie. 
* *Action:* Always put the value you want to sort by into the `.first` slot.

### Rule B: Custom Sorting (Struct Comparator)
To sort custom objects (like structural data), overload the `()` operator. 
* **Counter-intuitive Rule:** In the custom comparator, using `>` creates a **Min-Heap**, while `<` creates a **Max-Heap**.

```cpp
struct Task {
    int id;
    int priority;
};

// We want the absolute lowest priority value on top (Min-Heap)
struct CustomComp {
    bool operator()(const Task& a, const Task& b) {
        return a.priority > b.priority; // '>' swaps elements to put lower priority on top
    }
};

// Declaration syntax
std::priority_queue<Task, std::vector<Task>, CustomComp> pq;
```

---

## 5. Complete Usage Pattern
```cpp
#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;
    
    pq.push(10);
    pq.push(30);
    pq.push(20);
    
    while (!pq.empty()) {
        std::cout << pq.top() << " "; // 30 20 10
        pq.pop();
    }
}
```
