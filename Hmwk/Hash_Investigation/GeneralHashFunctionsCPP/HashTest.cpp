/*
 **************************************************************************
 *                                                                        *
 *           General Purpose Hash Function Algorithms Test                *
 *                                                                        *
 * Author: Arash Partow - 2002                                            *
 * URL: http://www.partow.net                                             *
 * URL: http://www.partow.net/programming/hashfunctions/index.html        *
 *                                                                        *
 * Copyright notice:                                                      *
 * Free use of the General Purpose Hash Function Algorithms Library is    *
 * permitted under the guidelines and in accordance with the most current *
 * version of the Common Public License.                                  *
 * http://www.opensource.org/licenses/cpl1.0.php                          *
 *                                                                        *
 **************************************************************************
*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include "GeneralHashFunctions.h"
#include <set>  //Use store hash values to find collisions

using namespace std;

int main(int argc, char* argv[])
{
    int maxNumCol = 0;
    int i = 0;
    bool first = false;

    //int cntRS = 0;
    
    multiset<int> rs;
   /*
   int cntJS = 0;
   int cntPJW = 0;
   int cntELF = 0;
   int cntBKDR = 0;
   int cntSDBM = 0;
   int cntDJB = 0;
   int cntDEK = 0;
   int cntFNV = 0;
   int cntBP = 0;
   int cntAP = 0;
   */
       
   //Seed for RNG in generating random string
   srand(time(NULL));
   
   while(i < 1000000){
        //cout<<"\ni = "<< i<<endl;
        //string key = "abcdefghijklmnopqrstuvwxyz1234567890";

        //Assigns string key to randomly generated string
        string key = randString();

        /*
        cout << "General Purpose Hash Function Algorithms Test" <<endl;
        cout << "By Arash Partow - 2002        " <<endl;
        cout << "Key:     " <<key<<endl;
        cout << " 1. RS-Hash Function Value:   " <<setw(15)<< RSHash(key)   <<endl;
        cout << " 2. JS-Hash Function Value:   " <<setw(15)<< JSHash(key)   <<endl;
        cout << " 3. PJW-Hash Function Value:  " <<setw(15)<< PJWHash(key)  <<endl;
        cout << " 4. ELF-Hash Function Value:  " <<setw(15)<< ELFHash(key)  <<endl;
        cout << " 5. BKDR-Hash Function Value: " <<setw(15)<< BKDRHash(key) <<endl;
        cout << " 6. SDBM-Hash Function Value: " <<setw(15)<< SDBMHash(key) <<endl;
        cout << " 7. DJB-Hash Function Value:  " <<setw(15)<< DJBHash(key)  <<endl;
        cout << " 8. DEK-Hash Function Value:  " <<setw(15)<< DEKHash(key)  <<endl;
        cout << " 9. FNV-Hash Function Value:  " <<setw(15)<< FNVHash(key)  <<endl;
        cout << "10. BP-Hash Function Value:   " <<setw(15)<< BPHash(key)   <<endl;
        cout << "11. AP-Hash Function Value:   " <<setw(15)<< APHash(key)   <<endl;
        */

        /*
        set<int> js;
        set<int> pjw;
        set<int> elf;
        set<int> bkdr;
        set<int> sdbm;
        set<int> djb;
        set<int> dek;
        set<int> fnv;
        set<int> bp;
        set<int> ap;
        */
        int nRS = RSHash(key);
        
        /*
        int nJS = JSHash(key);
        int nPJW = PJWHash(key);
        int nELF = ELFHash(key);
        int nBKDR = BKDRHash(key);
        int nSDBM = SDBMHash(key);
        int nDJB = DJBHash(key);
        int nDEK = DEKHash(key);
        int nFNV = FNVHash(key);
        int nBP = BPHash(key);
        int nAP = APHash(key);
        */

        if(rs.count(nRS) != 0)
            maxNumCol++;
        /*
         js.count(nJS)


         pjw.count(nPJW)


         elf.count(nELF)


         bkdr.count(nBKDR)


         sdbm.count(nSDBM)


         djb.count(nDJB)


         dek.count(nDEK)

         fnv.count(nFNV) 


         bp.count(nBP)


         ap.count(nAP) 


        maxNumCol = cntRS+cntJS+cntPJW+cntELF+cntBKDR+cntSDBM+
                    cntDJB+cntDEK+cntFNV+cntBP+cntAP;
        */

        rs.insert(nRS);


        /*
        js.insert(nJS);
        pjw.insert(nPJW);
        elf.insert(nELF);
        bkdr.insert(nBKDR);
        sdbm.insert(nSDBM);
        djb.insert(nDJB);
        dek.insert(nDEK);
        fnv.insert(nFNV);
        bp.insert(nBP);
        ap.insert(nAP);
        */



        if(maxNumCol == 1 && first == false){
            cout<<"\n****** First Collision has occured when i = "<<i<<", key = "
                <<key<<", RS-Hash Value = "<<nRS<<endl<<endl<<" ******\n";
            first = true;
        }
        
        i++;
   };
   cout<<"\nMax Number of Collisions = "<<maxNumCol<<endl;
   cout<<"Number of Loops Iterated = "<<i<<endl;

   return true;
}
