# Effective STL
(http://apachetechnology.in/ati/www/KC/dw/Scott%20Mayer%20-%20Effective%20STL.pdf)

Containers: More powerful and flexible than arrays, they grow (and often shrink) dynamically, manage their own memory, keep track of how many objects they hold, etc.

standard STL sequence containers, vector, string, deque, and list.<br>
standard STL associative containers, set, multiset, map and multimap.<br>
nonstandard sequence containers slist and rope. slist is a singly linked list, and rope is essentially a heavy-duty string<br>
nonstandard associative containers hash_set, hash_multiset, hash_map, and hash_multimap<br>
vector<char> as a replacement for string.

- Do you need to be able to insert a new element at an arbitrary position in the container? If so, you need a sequence container: associative containers won't do.
- Do you care how elements are ordered in the container? If not, a hashed container becomes a viable choice. Otherwise, you'll want to avoid hashed containers.
- Must the container be part of standard C++? If so, then eliminates hashed containers, slist, and rope.
- What category of iterators do you require? If they must be random access iterators, you're technically limited to vector, deque, and string, but you'd probably want to consider rope, too. If bidirectional iterators are required, you must avoid slist as well as one common implementation of the hashed containers.
- Is it important to avoid movement of existing container elements when insertions or erasures take place? If so, you'll need to stay away from contiguous-memory containers
- 