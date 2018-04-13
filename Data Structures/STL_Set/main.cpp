/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kevin
 *
 * Created on April 4, 2018, 11:06 PM
 */

#include <cstdlib>
#include <iostream>
#include <set>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout<<"\t\t\t\tSet (No REPEAT)"<<endl<<endl;
    set<int> c;
   
    c.insert(1);
    c.insert(2);
    c.insert(4);
    c.insert(5);
    c.insert(6);
    
    
    /*
    c.insert(val) Inserts a copy of val and returns the position of the new
    element and, for sets, whether it succeeded
    c.insert(pos,val) Inserts a copy of val and returns the position of the new
    element (pos is used as a hint pointing to where the insert
    should start the search)
    c.insert(beg,end) Inserts a copy of all elements of the range [beg,end)
    (returns nothing)
    c.insert(initlist) Inserts a copy of all elements in the initializer list initlist
    (returns nothing; since C++11)
    c.emplace(args...) Inserts a copy of an element initialized with args and
    returns the position of the new element and, for sets,
    whether it succeeded (since C++11)
    c.emplace_hint(pos,args...) Inserts a copy of an element initialized with args and
    returns the position of the new element (pos is used as a
    hint pointing to where the insert should start the search)
    c.erase(val) Removes all elements equal to val and returns the
    number of removed elements
    c.erase(pos) Removes the element at iterator position pos and returns
    the following position (returned nothing before C++11)
    c.erase(beg,end) Removes all elements of the range [beg,end) and returns
    the following position (returned nothing before C++11)
    c.clear() Removes all elements (empties the container)
     
     */
    
    cout << "nth location of first node (iterator) = " << *c.begin() << endl;
    cout << "nth  location of last node (iterator) = " << *c.end() << endl;
    cout << "size     of the set = " << c.size() << endl;
    cout << "max size of the set = " << c.max_size() << endl;
    cout << "find position of node value 3 is found: " << *c.find(3) << endl;
    cout << "count for the value 1 = " << c.count(1) << endl;
    cout << "is it empty?: " << c.empty() <<" <--- 0 means FALSE" << endl;
    cout <<endl;
    
    //Returns back the first or last position of where the value will be injected on the set
    cout << "lower_bound(3): " << *c.lower_bound(3) << endl;
    cout << "upper_bound(3): " << *c.upper_bound(3) << endl;
    cout << "equal_range(3): " << *c.equal_range(3).first << " "<< *c.equal_range(3).second << endl;
    cout << endl;
    cout << "lower_bound(5): " << *c.lower_bound(5) << endl;
    cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
    cout << "equal_range(5): " << *c.equal_range(5).first << " "<< *c.equal_range(5).second << endl;
    
    cout<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\tMultiSet (ALLOWS REPEATS)"<<endl<<endl;
    
    multiset<int> m;
    m.insert(1);
    m.insert(1);
    m.insert(2);
    m.insert(3);
    m.insert(4);
    m.insert(5);
    m.insert(6);

    cout << "size     of the set = " << m.size() << endl;
    cout << "max size of the set = " << m.max_size() << endl;
    cout << "find position of node value 3 is found: " << *m.find(3) << endl;
    cout << "count for the value 1 = " << m.count(1) << endl;
    cout << "is it empty?: " << m.empty() <<" <--- 0 means FALSE" << endl;
    
    //Returns back the first or last position of where the value will be injected on the set
    cout << "lower_bound(3): " << *m.lower_bound(3) << endl;
    cout << "upper_bound(3): " << *m.upper_bound(3) << endl;
    cout << "equal_range(3): " << *m.equal_range(3).first << " "<< *c.equal_range(3).second << endl;
    cout << endl;
    cout << "lower_bound(5): " << *m.lower_bound(5) << endl;
    cout << "upper_bound(5): " << *m.upper_bound(5) << endl;
    cout << "equal_range(5): " << *m.equal_range(5).first << " "<< *c.equal_range(5).second << endl;
    
    // print all elements
    for (int elem : c) {
        cout << elem << "’ ’";
    }
    cout << endl;
    
    return 0;
}

