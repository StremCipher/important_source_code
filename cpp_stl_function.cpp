/*  CREATED BY
    STREAM_CIPHER
    03-apr-2020
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll; 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
/************************************************COMBINOTRICS**********************************************************************/
    .next_permutation(a.begin(),a.end());//change a to its's next permutation
    .prev_permutation(a.begin(),a.end());//change a to its's prev premutatio
    .is_permutation(a.begin(),a.begin()+range,b);//return true if 'b' is a premutation of 'a' (from start to range) 
                                                  // time complexity of above 3 is at most n/2 swaps

/************************************************SET in C++ STL ********************************************************************/
    .set always store data in sorted order so it can be used as min_heap or max_heap
    .as the name suggest it always store oly the uniq element 
    .set is a container to all the container function can be aplied on it like.iterator
                                                                              .max(),min()
                                                                              .lower_bound(),upper_bound()...etc
    .set<int>a;//creating a set
    .a.insert(value);//inserting a value to a
    .a.begin();//return pointer to first element
    .a.end();//return pointer to last element ,which is always null
    .a.rbegin();//return pointer to actual last element ,or it return 1 element previous to a.end()
    .a.crbegin();//return pointer to actual last element ,or it return 1 element previous to a.end()
                both are work same but i don''t know the exact difference
    .a.size();
    .a.empty();//return true if a is empty
    .a.erase(value);//delete only index having value=value
    .a.clear();//clear whole set
    .a.find(value)//to find if value is present or not
    .a.lower_bound(value);
    .a.upper_bound(value);

    .these are not available in set
    .a.sort();
    /************************************************MULTISET in C++ STL ********************************************************************/
     .MULTISET is same as set but it can store dublicates element also
      so what is difference between multiset and priority_queue
        .both are almost same but priority_queue is faster than multiset
        .in priority_queue u can delete element from top index only but in multiset set u can delete any element if it exist like sets.
    .multiset<int>a;//creating a set
    .a.insert(value);//inserting a value to a
    .a.begin();//return pointer to first element
    .a.end();//return pointer to last element ,which is always null
    .a.rbegin();//return pointer to actual last element ,or it return 1 element previous to a.end()
    .a.crbegin();//return pointer to actual last element ,or it return 1 element previous to a.end()
                both are work same but i don''t know the exact difference
    .a.size();
    .a.empty();//return true if a is empty
    .a.erase(value);//delete only index having value=value
    .a.clear();//clear whole set
    .a.find(value)//to find if value is present or not
    .a.lower_bound(value);
    .a.upper_bound(value);

    .these are not available in set
    .a.sort();
/************************************************queue in C++ STL ******************************************************************/
    .as we all know properties of queue it work on "FIFO"(first in first out)
                                                                              
    .queue<int>a;//creating a queue
    .a.push (value);//inserting a value to a
    .a.pop();
    .a.front();//return pointer to first element
    .a.back();//return pointer to last element
    
    .a.size();
    .a.empty();//return true if a is empty

    .these are not available in queue
    .a.erase(value);
    .a.clear();
    .a.sort();
    .a.lower_bound(value);
    .a.upper_bound(value);
    
/************************************************deque in C++ STL ******************************************************************/
    .in deque element can be added or deleted from both side
    
                                                                            
    .deque<int>a;//creating a deque
    .a.push_back(value);//inserting a value to a in back
    .a.push_front(value);//inserting a value to a in front
    .a.pop_back();//remove the last elment
    .a.pop_front();//remove the first elment
    .a.begin();//return pointer to first element
    .a.end();//return pointer to last element ,which is always null
    .a.rbegin();//return pointer to actual last element ,or it return 1 element previous to a.end()
    .a.crbegin();//return pointer to actual last element ,or it return 1 element previous to a.end()
                both are work same but i don''t know the exact difference
    .a.size();
    .a.empty();//return true if a is empty

    .these are not available in deque
    .a.erase(value);
    .a.clear();
    .a.find(value)
    .a.sort();
    .a.lower_bound(value);
    .a.upper_bound(value);

/************************************************priority_queue in C++ STL *********************************************************/ 
    .priority_queue always store data in sorted order so it can be used as min_heap or max_heap
    .priority_queue<int>a;//creating a priority_queue
    .priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp>q;//we can use compare to store inspesific order
    .a.push(value);//inserting a value to a 
    .a.pop();//remove the most prior element
    .a.size();
    .a.empty();//return true if a is empty

    .these are not available in priority_queue
    .a.begin();
    .a.end();
    .a.erase(value);
    .a.clear();
    .a.find(value)
    .a.sort();
    .a.lower_bound(value);
    .a.upper_bound(value);
/************************************************stack in C++ STL ******************************************************************/
    .as we all know properties of queue it work on "LIFO"(last in first out)
    .stack<int>a;//creating a stack
    .a.push(value);//inserting a value to a 
    .a.pop();//remove the top element
    .a.size();
    .a.top();//acces top elemnt
    .a.empty();//return true if a is empty

    .these are not available in stack
    .a.begin();
    .a.end();
    .a.erase(value);
    .a.clear();
    .a.find(value)
    .a.sort();
    .a.lower_bound(value);
    .a.upper_bound(value);
/************************************************vector in C++ STL *****************************************************************/
    .vector is nothing but dynamic array
    .all the container function are apllicable on it like.sort()
                                                        .lower_bound()
                                                        .upper_bound()
                                                        .etc....
                                                        .stack<int>a;//creating a priority_queue
    .a.push_back(value);//inserting a value to a 
    .a.pop_back();//remove the last element
    .a.pop_front();//remove the front element
    .a.size();
    .a.front();//acces firsr elemnt
    .a.back();//acces alst elemnt
    .a.empty();//return true if a is empty
    .a.begin();//return pointer 
    .a.end();//return ponter
    .a.rbegin();//return pointer to actual last element ,or it return 1 element previous to a.end()
    .a.crbegin();//return pointer to actual last element ,or it return 1 element previous to a.end()
                both are work same but i don''t know the exact difference
    .a.erase(value);
    .a.clear();
    .a.sort();
    .a.reverse();
    .a.lower_bound(value);
    .a.upper_bound(value);

    .these are not available in vector
    .a.find(value)
/************************************************MAP in C++ STL ********************************************************************/
    struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
    }; 
    .unordered_map<pair<int,int>,int,hash_pair>mp;//use hash_pair template otherwise u will get error
    .map<int,int>a;
    .a.insert({val1,val2});
    .a.size();
    .a.empty();//return true if a is empty
    .a.begin();//return pointer to first index
    .a.end();//return pointer to last index 
    .a.rbegin();//return pointer to actual last element ,or it return 1 element previous to a.end()
    .a.crbegin();//return pointer to actual last element ,or it return 1 element previous to a.end()
                both are work same but i don''t know the exact difference
    .a.erase(value);
    .a.clear();//clear all 
    .a.lower_bound(value);
    .a.upper_bound(value);
    .a.find(value)
    .a.count(value)//return number of element equal to value

    .these are not available in map
    .a.sort();
    .a.reverse();
/************************************************ARRAY in C++ STL ******************************************************************/
    
/************************************************LIST in C++ STL *******************************************************************/

/************************************************NUMBER_THEORY**********************************************************************/
    .max(a,b);
    .min(a,b);
    .max_element(a.begin(),a.end());// in case of vector 
    .max_element(a,a+n)//in case of array//return pointer to the max elemnt
    .min_element(a.begin(),a.end());// in case of vector 
    .min_element(a,a+n)//in case of array//return pointer to the max elemnt
    .abs(a,b);//return |a-b| for integer type number
    .fabs(a,b);//retrun |a-b| for floating point number
    .swap(a,b);
    .__gcd(a,b);
    .a*b/(__gcd(a,b);//LCM(a,b)
    .ceil(a/b);
    .floor(a/b);
    .sort(a.begin(),a.end());
    .reverse(a.begin(),a.end());
    .is_sorted(a.begin(),a.end());//return true if given range is sorted in ascending order,else return false
    .sort(a.begin()+start,a.start()+last);//to sort a particular range :NOTE considering only element lying in range
    .parial_sort(a.begin(),a.begin()+range,a.end());//used to sort particular rnage :NOTE considering all elements
    .upper_bound(a.begin(),a.end(),val);//upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’.
    .lower_bound(a.begin(),a.end(),val);//lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’
                                          // if val is not present then it points to a.end(),which denotes end of vector
    .binary_search(a.begin(),a.end(),value);//return true if element found else return false
    .equal_range(a.begin(),a.end(),value);//return a pair of pointer first for lower_bound and second for upper bound
    .stol(dec_num,nullptr,10);//to convert string into decimal number of base 10
    .stoll(dec_num,nullptr,10);//for long long
    .stol(binary_num,nullptr,10);//to convert string into binay number of base 2

/***************************************************Bit_Manupulation**********************************************************************/
    .a<<y//a*2^y;
    .a>>y//a/(2^y);
    ._builtin_popcount(x)//retuen number of set bits in x;


/***************************************************Memory_Allocation**********************************************************************/
    .memset(array,0,sizeof array);//assining 0
    .memset(array,-1,sizeof array);//assining -1 
    .memset(array,0x3f3f3f3f,sizeof array);//assining 64 bit num

}