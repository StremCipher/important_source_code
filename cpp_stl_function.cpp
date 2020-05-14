 /*  CREATED BY
    STREAM_CIPHER
    03-apr-2020
*/
//important c++ stl library function
#include<bits/stdc++.h>
typedef long long  ll ;
using namespace std;
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