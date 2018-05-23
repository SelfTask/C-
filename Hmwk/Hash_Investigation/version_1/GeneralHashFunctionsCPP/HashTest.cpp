/* Filename: HashTest.cpp
 * Name: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Hash Investigation
 * Purpose: Investigate how soon a collision occurs, and how small the maximum number of collisions are when hashing.
 *          Using the hashes provided.  Prove these properties as a function of N.
 * Date: May 15, 2018
 */

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
#include <ctime>

using namespace std;

int main(int argc, char* argv[])
{
    for(int k = 0; k < 4; k++){
        int start = time(0);
    int maxNumCol = 0;
    int checkFirst = 0;
    int i = 0;
    bool first = false;
    int numTrial = 1000000;
    
    if(k == 0)
        numTrial = 1000000;
    else if(k == 1)
        numTrial = 2000000;
    else if(k == 2)
        numTrial = 4000000;
    else if(k == 3)
        numTrial = 8000000;
    
    //Declaring set for each hash to avoid collision from one hash to another
    set<int> rs;
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
    
   //Counts number of collisions for each hash
   int cntRS = 0; 
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
   
       
   //Seed for RNG in generating random string
   srand(time(NULL));
   
   cout<<"Number of Trails Set to: "<<numTrial<<" loops.\n";
   cout<<"Running Collision test with the attached hash functions...\n";
   
   for(i = 0; i < numTrial; i++){
        //cout<<"\ni = "<< i<<endl;
        //string key = "abcdefghijklmnopqrstuvwxyz1234567890";

        //Assigns string key to randomly generated string
        string key = randString();

        //cout<<"\nKey = "<<key<<endl;
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
        
        //Obtain hash keys from each type of hash
        int nRS = RSHash(key);
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
 
        //Check for collisions in all the 
        if(rs.count(nRS) != 0)
            cntRS++;

        if(js.count(nJS) != 0)
            cntJS++;

        if(pjw.count(nPJW) != 0)
            cntPJW++;

        if(elf.count(nELF) != 0)
            cntELF++;

        if(bkdr.count(nBKDR) != 0)
            cntBKDR++;

        if(sdbm.count(nSDBM) != 0)
            cntSDBM++;

        if(djb.count(nDJB) != 0)
            cntDJB++;

        if(dek.count(nDEK) != 0)
            cntDEK++;

        if(fnv.count(nFNV) != 0)
            cntFNV++;

        if(bp.count(nBP) != 0)
            cntBP++;

        if(ap.count(nAP) != 0)
            cntAP++;
        
        
        //Check for first collision
        if(first == false)
            checkFirst = cntRS+cntJS+cntPJW+cntELF+cntBKDR+cntSDBM+
                    cntDJB+cntDEK+cntFNV+cntBP+cntAP;
        
        //Insert a hash value into its corresponding container for that hash
        //to avoid cross collision from one hash function to another
        rs.insert(nRS);
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

        //Alerts when the collision has occurred 
        if(checkFirst > 0 && first == false){
            cout<<"\n****** First Collision has occurred when Iteration = "<<i
                <<", key = "<<key<<" ******\n\n\n";
            first = true;
        }
   }
   
   //Calculates max collision
   maxNumCol = cntRS+cntJS+cntPJW+cntELF+cntBKDR+cntSDBM+
                    cntDJB+cntDEK+cntFNV+cntBP+cntAP;
   
   //Displays Max collision & number of collisions from each Hash type
    
    cout << " 1. RS-Hash   Number of Collisions: " <<setw(15)<< cntRS   <<endl;
    cout << " 2. JS-Hash   Number of Collisions: " <<setw(15)<< cntJS   <<endl;
    cout << " 3. PJW-Hash  Number of Collisions: " <<setw(15)<< cntPJW  <<endl;
    cout << " 4. ELF-Hash  Number of Collisions: " <<setw(15)<< cntELF  <<endl;
    cout << " 5. BKDR-Hash Number of Collisions: " <<setw(15)<< cntBKDR <<endl;
    cout << " 6. SDBM-Hash Number of Collisions: " <<setw(15)<< cntSDBM <<endl;
    cout << " 7. DJB-Hash  Number of Collisions: " <<setw(15)<< cntDJB  <<endl;
    cout << " 8. DEK-Hash  Number of Collisions: " <<setw(15)<< cntDEK  <<endl;
    cout << " 9. FNV-Hash  Number of Collisions: " <<setw(15)<< cntFNV  <<endl;
    cout << "10. BP-Hash   Number of Collisions: " <<setw(15)<< cntBP   <<endl;
    cout << "11. AP-Hash   Number of Collisions: " <<setw(15)<< cntAP   <<endl;
    
    cout<<endl<<"----------------------------------------\n\n";
    
    cout<<"\nMAX Number of Collisions from every Hash Function = "<<maxNumCol<<endl<<endl;
    
    cout<<"Number of Iterations = "<<i<<endl;
    
    cout<<"\nTime = "<<time(0) - start<<endl;
    }
   return 0;
}
