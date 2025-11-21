// class TimeMap {
// public:
//     unordered_map<string, vector<pair<int, string>>> m;

//     TimeMap() {}
    
//     void set(string key, string value, int timestamp) {
//         m[key].push_back({timestamp, value}); 
//         // timestamps are always increasing for each key
//         // Time:  O(1)
//         // Space: O(1)

//     }
    
//     string get(string key, int timestamp) {
//     // Time:  O(log n)
//     // Space: O(1)

//         // key does not exist or has no entries
//         if (!m.count(key)) return "";

//         auto &vec = m[key];
//         if (vec.empty()) return "";
        
//         int left = 0, right = vec.size() - 1, ansIdx = -1;

//         // Binary search for last timestamp <= target
//         while (left <= right) {
//             int mid = left + (right - left) / 2;

//             if (vec[mid].first <= timestamp) {
//                 ansIdx = mid;       
//                 left = mid + 1;  
//             } else {
//                 right = mid - 1;
//             }
//         }

//         // If no timestamp <= target
//         if (ansIdx == -1) return "";

//         return vec[ansIdx].second;    
//     }
// };






// // Store: key → vector of (timestamp, value)
// // set: push_back
// // get: binary search for last timestamp ≤ target

// // Time:  set O(1), get O(log n)
// // Space: O(total entries)
