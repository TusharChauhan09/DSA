#include<iostream>
#include<list>
using namespace std;
int main(){

    //(2) Declaration 
    list<int>list1 = {1,2,3,4};

    //(3) Iterator Function
    auto i = list1.begin();                       //(a)  
    auto j = list1.end();                         //(b)  
    // Or   list<int>::iterator i;
    cout<<*i<<"\n";                               // 1 - {1,2,3,4}
    cout<<*j<<"\n";                               // 4 - {1,2,3,4}

    auto k = list1.rbegin();                       //(c)  
    auto l = list1.rend();                         //(d)

    cout<<*k<<"\n";                                // 4 - {4,3,2,1}
    cout<<*l<<"\n";                                // 4 - {1,2,3,4}

    advance(i,2);                                  //(e)

    cout<<*i<<"\n";                                // 3 - {1,2,3,4}


    //(f) Triversal  

    for(auto itr: list1){      // USING RANGE                        
        cout<<itr<<" ";
    }
    cout<<"\n";

    for(auto itr = list1.begin(); itr != list1.end(); itr++){   // USING Itrator
        cout<<*itr<<" ";
    }
    cout<<"\n";
    for(auto itr = list1.rbegin(); itr != list1.rend(); itr++){   // reverse 
        cout<<*itr<<" ";
    }
    cout<<"\n";


    // (g) Insertion 
    
    // list1 = {1,2,3,4}

    // (g.i) 
    auto itr = list1.begin();                               
    advance(itr,2);
    list1.insert(itr,5);

    for(auto itr = list1.begin(); itr != list1.end(); itr++){   
        cout<<*itr<<" ";
    }
    cout<<"\n";

    // (g.ii)
    list1 = {1,2,3,4};
    itr = list1.begin();
    advance(itr,2);
    list1.insert(itr,2,5);

    for(auto itr = list1.begin(); itr!= list1.end(); itr++){   
        cout<<*itr<<" ";
    }
    cout<<"\n";

    // (g.iii)
    list1 = {1,2,3,4};
    itr = list1.begin();
    advance(itr,2);
    auto start_itr = list1.begin();
    auto end_itr = list1.begin();
    advance(end_itr,2);

    list1.insert(itr,start_itr,end_itr);

    for(auto itr = list1.begin(); itr != list1.end(); itr++){   
        cout<<*itr<<" ";
    }
    cout<<"\n";


    // (h) Deletion

    //(h.i)

    list1 = {1,2,3,4};
    itr = list1.begin();
    advance(itr,2);

    list1.erase(itr);

    for(auto itr = list1.begin(); itr != list1.end(); itr++){   
        cout<<*itr<<" ";
    }
    cout<<"\n";

    //(h.ii)

    list1 = {1,2,3,4};
    start_itr = list1.begin();
    end_itr = list1.begin();
    advance(end_itr,2);

    list1.erase(start_itr,end_itr);

    for(auto itr = list1.begin(); itr != list1.end(); itr++){   
        cout<<*itr<<" ";
    }
    cout<<"\n";

    // (j) Other Member Functions

    return 0;   
}