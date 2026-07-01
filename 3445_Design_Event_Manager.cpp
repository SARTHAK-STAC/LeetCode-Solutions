#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/*
LeetCode - Design Event Manager

Approach:
Use a Max Heap (Priority Queue) along with a Hash Map.
- Store each event's current priority in an unordered_map.
- Store {priority, -eventId} in a max heap so that:
    - Higher priority comes first.
    - If priorities are equal, smaller eventId comes first.
- During updates, push the new priority into the heap.
- While polling, discard outdated entries using lazy deletion.
- Return the highest-priority valid event.

Time Complexity:
Constructor: O(n log n)
updatePriority(): O(log n)
pollHighest(): O(log n) (amortized)

Space Complexity: O(n)
*/

class EventManager {
public:
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> mp;

    EventManager(vector<vector<int>>& events) {

        for (auto &e : events) {
            int id = e[0];
            int priority = e[1];

            mp[id] = priority;
            pq.push({priority, -id});
        }
    }

    void updatePriority(int eventId, int newPriority) {

        mp[eventId] = newPriority;
        pq.push({newPriority, -eventId});
    }

    int pollHighest() {

        while (!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int priority = top.first;
            int eventId = -top.second;

            if (mp.count(eventId) && mp[eventId] == priority) {
                mp.erase(eventId);
                return eventId;
            }
        }

        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId, newPriority);
 * int param_2 = obj->pollHighest();
 */