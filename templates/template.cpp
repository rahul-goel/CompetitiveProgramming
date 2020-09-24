/*
	Created by Rahul Goel.
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1000000007;
const int INF = 1000000000;

#define pii pair < int, int >
#define vi vector < int >
#define vvi vector < vector < int > >
#define vpii vector < pair < int, int > >
#define vvpii vector < vector < pair < int, int > > >
#define pb push_back
#define f first
#define s second
#define mp make_pair

int main()
{

	return 0;
}

/*
USE OF SORT FUNCTION - library is algorithm
syntax for ascending order:-
	sort(arr, arr + n);		n is the number of elements; sort(a,b) sort [a,b);
syntax for descending order:-
	sort(arr, arr + n, greater< int >());	//here we have written int, for others the datatype will be entered
we can change the range to do a partial sort
syntax:-
	sort(arr+a, arr+b+1); will sort the elements in range [a, b] or [a, b+1) in ascending order;

sorting vector:-
	sort(vec.begin(), vec.end());

sorting vector of pairs:-
	ascending:-
		sort(vec.begin(), vec.end());
	descending:-//declare this function
		bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) 
		{ 
	    	return (a.second < b.second); 
		} 
		//then calll this from main-
		sort(vect.begin(), vect.end(), sortbysec);
*/

/*
USE OF VECTORS - library is vector
vector<int> vec_name; to declares 1D vector of name 'vec_name' and stores int values;
vec_name.resize(n) resizes the vector to size n;
vec_name.size() returns the number of elements in the vector;
vec_name.push_back(value) adds the 'value' to the end of the vector;
vec_name.pop_back(value) deletes the element at the end of the vector;
vec_name.clear() deletes all the elements and clears the vector;  
vec_name.empty() returns whether the vector is empty or not;
*/

/*
USE OF MEMSET - library is cstring
memset(str, c, sizeof(str));
*/

/*
USE OF STRING - library is string
string str; declares the a string of name 'str' of dynamic size i.e. we do not have to the memoery size;
use getline to take input of a string with the spaces;
Syntax of getline():-
	getline(cin, str);
str.push_back(c) take in character c and appends it to the end of the string;
str.pop_back() removes the last character in the string str;
str.lenght() returns the length of the string. It is like strlen(str);
str.compare(st) returns integer after lexicograpicall comparing str and st; similar to strcmp(str, st);
str = str + st concatinates st to str
*/

/*
USE OF PAIRS - library is utility
declaration syntax is:-
	pair <datatype1, datatype2> pair_name;
pair.first is used to access the first element;
pair.second is used to access the second element;
initialisation of pair:-
	pair <datatype1, datatype2> pair_name (value1, value2);
the function make_pair is used to directly initialise the pair without declaring the data_type;
use of make_pair:-
	pair_name = make_pair(value1, value2);
comparison operators in pairs:-
pair_name1 == pair_name2 returns true or false value by comparing the two pairs, similar for !=;
pair1.swap(pair2) swaps the pairs i.e. both elements of pair1 go to pair2 and vice a versa

declaring vector of pairs:-
	vector< pair<int, int> > vec_name;
*/

/*
USE OF QUEUE - library is queue
declaraion syntax is :-
	queue < int > queue_name;
queue_name.size() returns the size of the queue;
queue_name.empty() returns whether the queue is empty or not;
queue_name.clear() empties the entire queue;
queue_name.push(value) pushed in 'value' at the end of the queue;
queue_name.pop() pops out the value from the front of the queue; 
queue_name.front() returns the value at the front of the queue;
queue_name.back() returns the value at the end of the queue;
*/

/*
USE OF DEQUE - library is deque
declaration syntax is :-
	deque < int > deque_name;
deque_name.size() returns the size of the deque;
deque_name.empty() returns whether the deque is empty or not;
deque_name.clear() empties the entire deque;
deque_name.push_front(value) pushes 'value' at the front of the deque;
deque_name.pop_front() pops the value from the front of the deque;
deque_name.push_back(value) pushes 'value' at the back of the deque;
deque_name.pop_back() pops out the value from the back of the deque;
deque_name.front() returns the value at the front of the deque;
deque_name.back() returns the value at the back of the deque;
*/

/*
USE OF PRIORITY QUEUES - library is queue
for max heap declaration syntax is :-
	priority_queue < int > pq_name;
for min heap declaration syntax is :-
	priority_queue < int, vector < int >, greater < int > > pq_name; //weird syntax, i know;
pq_name.size() returns the size of the priority queue;
pq_name.empty() returns whether the priority queue is empt or not;
pq_name.push(value) pushes in the value in the prority queue;
pq_name.pop(value) pops out the value in the priority queue(depends on the type of heap);
pq_name.top() returns the value at the top of the queue but does not pop it out;

most probably the priority queues are implemented using heaps so:-
	push = O(log n)
	pop = O(log n)
	top = O(1)
*/

/*
USE OF STACK - library is stack
declaration syntax :-
	stack < int > s;
s.size() returns the size of the stack;
s.empty() returns whether the stack is empty or not;
s.push(value) pushes the value at the top of the stack;
s.pop() pops the value at the top of the stack;
s.top() returns the value at the top of the stack;
*/