/* 
 * File:   main.cpp
 * Author: DangerousPirate
 *
 * Created on May 13, 2018, 6:48 PM
 */

#include <cstdlib>
#include <iostream>


using namespace std;

char status(bool);
void showTable();
void showWritten();
void lehrsTruthTable();

int main(int argc, char** argv) {

    cout<<"\nTruth Table\n";
    showTable();
    
    cout<<"\nLehr's Truth Table\n";
    lehrsTruthTable();
    
    cout<<"\nNice Looking Truth Table";
    showWritten();
    return 0;
}



void showTable(){
    bool p, q;
    string r[4][4];
    cout<<"P\tQ\t!P\t!Q |   P&Q     P|Q     P^Q    P^Q^Q   P^Q^P  !(P&Q)   !P|!Q  !(P|Q)   !P&!Q"<<endl;
    cout<<"-----------------------------------------------------------------"
        <<"----------------------------------------\n";
    for(int i = 0; i < 4; i++){
        if(i == 0){
            p = true;
            q = true;
        }else if(i == 1){
            p = true;
            q = false;
        }else if(i == 2){
            p = false;
            q = true;
        }else{
            p = false;
            q = false;
        }
        
        cout<<status(p)<<"\t"<<status(q)<<"\t"
            <<status(!p)<<"\t"<<status(!q)<<"  |\t"   
            <<status(p&&q)<<"\t"
            <<status(p||q)<<"\t"
            <<status(p^q)<<"\t"
            <<status(p^q^q)<<"\t"
            <<status(p^q^p)<<"\t"
            <<status(!(p&&q))<<"\t"
            <<status(!p||!q)<<"\t"
            <<status(!(p||q))<<"\t"
            <<status(!p&&!q)




           <<endl;
     
    } 
    cout<<endl;
}

char status(bool r){
        if(r == true)
            return 'T';
        else
            return 'F';
}

void showWritten(){
    cout<<endl;
    
    cout<<"*******************************************************************************"<<endl
        <<"* P  Q  !P  !Q  *  P&Q  P|Q   P^Q  P^Q^Q  P^Q^P  !(P&Q)  !P|!Q  !(P|Q)  !P&!Q *"<<endl
        <<"*******************************************************************************"<<endl
        <<"* T  T   F   F  *   T    T     F     T      T       F      F      F       F   *"<<endl
        <<"* T  F   F   T  *   F    T     T     T      F       T      T      F       F   *"<<endl
        <<"* F  T   T   F  *   F    T     T     F      T       T      T      F       F   *"<<endl
        <<"* F  F   T   T  *   F    F     F     F      F       T      T      T       T   *"<<endl
        <<"*******************************************************************************"<<endl;
            
}

void lehrsTruthTable(){
     cout << "P  Q  ~P  ~Q  P&Q P|Q  P^Q P^Q^Q P^Q^P ~(P&Q) ~P|~Q ~(P|Q) ~P&~Q" << endl; //header
     // Nested loop for boolean algorithim 
     for (int p=1; p>=0; p--){
        for (int q=1;q>=0; q--){
          cout << (p? 'T' : 'F')<<"  "
               << (q ? 'T' : 'F')<<"   "
               << (!p ? 'T' : 'F')<<"   "
               << (!q ? 'T' : 'F')<<"   "
               << (p&q ? 'T' : 'F')<<"   "
               << (p|q ? 'T' : 'F')<<"    "
               << (p^q ? 'T' : 'F')<<"    "
               << (p^q^q ? 'T' : 'F')<<"     "
               << (p^q^p ? 'T' : 'F')<<"      "
               << (!(p&q) ? 'T' : 'F')<<"     "
               << (!p||!q ? 'T' : 'F')<<"     "
               << (!(p|q) ? 'T' : 'F')<<"      "
               << (!p&!q ? 'T' : 'F')<<"    "
               << endl;
        }
     }
}