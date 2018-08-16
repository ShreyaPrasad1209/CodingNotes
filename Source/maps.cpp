//map, multimap, unordered map, unordered multimap
//In a hashmap or unordered_map the data input (key) is hashed to convert in some hash value which modulo is then taken
//To make that big hash number fit into a list. It is a linked list so if any other data gets the same modulo it gets appended
//To the linked list.

#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

int main ()
{
    //In ordered map data gets stored in sorted manner
    //In map one value for a key wheras multimap can have many values for a key
    //Unordered map are stored as hash map whearas map are balanced binary tree.
    //Unordered map complexity is constant
    map<int, string> mp;
    mp.insert(make_pair<int, string>(5, "ANUKRIIT"));
    mp[1] = "ANKIT";
    mp[2] = "GAURAV";
    mp[3] = "NAKUL";

    for(auto it = mp.begin(); it != mp.end(); it++)
        cout << it -> first << " " << it -> second << endl;
    //Iterator gives a pair here, in pair we use ourpair.first here -> because itterator are simmilar to pointers
    
    return 0;
}