#include <bits/stdc++.h>
using namespace std;

class TaskManager {
    // taskInfo: Maps taskId → {userId, priority}
    //   This allows O(1) lookup of any task’s details (needed for edit and rmv).
    unordered_map<int, pair<int, int>> taskInfo;

    // tasks: Stores all tasks in a sorted manner, so we can always fetch the "best" task quickly.
    //   Each element is a tuple { -priority, -taskId, userId }.
    //   Why negatives? Because std::set sorts in ascending order.
    //   By storing -priority, higher priority comes first.
    //   By storing -taskId, larger taskId wins in case of tie.
    //   userId is stored to know which user owns the task.
    set<tuple<int, int, int>> tasks;

public:
    // Constructor: Initialize with a list of {userId, taskId, priority}
    TaskManager(vector<vector<int>>& initTasks) {
        for (auto &t : initTasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            add(userId, taskId, priority);
        }
    }

    // Add a new task: O(log n) due to set insertion
    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = {userId, priority};
        tasks.insert({-priority, -taskId, userId});
    }

    // Edit an existing task's priority: O(log n)
    void edit(int taskId, int newPriority) {
        auto [userId, oldPriority] = taskInfo[taskId];
        // Remove old entry from set
        tasks.erase({-oldPriority, -taskId, userId});
        // Update in map
        taskInfo[taskId] = {userId, newPriority};
        // Insert updated entry into set
        tasks.insert({-newPriority, -taskId, userId});
    }

    // Remove a task completely: O(log n)
    void rmv(int taskId) {
        auto [userId, priority] = taskInfo[taskId];
        // Remove from both data structures
        tasks.erase({-priority, -taskId, userId});
        taskInfo.erase(taskId);
    }

    // Execute the "top" task (highest priority, tie → highest taskId)
    // After execution, the task is removed from the system.
    int execTop() {
        if (tasks.empty()) return -1; // No tasks available

        // Get best task (first element in set due to sorting rules)
        auto [negPriority, negTaskId, userId] = *tasks.begin();

        // Remove from both data structures
        tasks.erase(tasks.begin());
        taskInfo.erase(-negTaskId);

        // Return the userId of executed task
        return userId;
    }
};


// steps
// 📝 Step-by-Step Explanation of Design Choices
// 1. Why unordered_map<int, pair<int, int>> taskInfo?

// Problem requires:

// edit(taskId, newPriority) → We must find the task in O(1).

// rmv(taskId) → Same, need O(1) lookup.

// A simple array wouldn’t work (taskId can be up to 1e5 but sparse).

// So we use a hash map (unordered_map) where:

// Key = taskId

// Value = {userId, priority}

// This gives instant access to any task’s details.

// 2. Why set<tuple<int,int,int>> tasks?

// We need to always get the best task efficiently:

// Highest priority first.

// If tie, task with highest taskId wins.

// Once chosen, must be removed.

// std::set:

// Stores elements in sorted order.

// Always allows O(1) access to the smallest element (*begin()).

// Insert, erase in O(log n).

// But since set sorts in ascending order, we negate priority and taskId:

// Store -priority → higher priority becomes "smaller".

// Store -taskId → larger taskId becomes "smaller".

// Thus, the "best" task is always at *tasks.begin().

// 3. Why a tuple?

// We need to store and sort by multiple fields:

// priority

// taskId

// userId

// Instead of writing a custom comparator, a tuple automatically provides lexicographic comparison:

// Compare -priority first.

// If equal, compare -taskId.

// If still equal, compare userId.

// Super clean solution.

// 4. Why remove from both map and set?

// taskInfo → stores metadata (fast lookup).

// tasks → maintains global ordering.

// If you remove from only one, the structures get out of sync → wrong results.

// So every operation (add, edit, rmv, execTop) must update both.