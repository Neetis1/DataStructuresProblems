/*Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

class LRUCache {
	int capacity;
	list< pair<int, int> > lruList;     // key, value pair
	unordered_map< int, list<pair<int, int>>::iterator > hash;   // key to <key,val> iterator map

	void moveToFront(int key, int value) {
		// erase and add a new entry to front
		lruList.erase(hash[key]); // this is O(1) since we are using iterator
		lruList.push_front(make_pair(key, value));
		hash[key] = lruList.begin();
	}
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		if (hash.find(key) == hash.end())
			return -1;
		// move the key, value pair to front
		int value = (*hash[key]).second;
		moveToFront(key, value);
		return (*hash[key]).second;
	}

	void put(int key, int value) {
		if (hash.find(key) != hash.end()) {
			// when key is already in hash
			moveToFront(key, value);
		}
		else {
			// add to the cache
			lruList.push_front(make_pair(key, value));
			hash[key] = lruList.begin();
			if (hash.size() > capacity) {
				// erase
				hash.erase(lruList.back().first);
				lruList.pop_back();
			}
		}
	}
};