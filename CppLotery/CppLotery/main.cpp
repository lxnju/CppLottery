//
//  main.cpp
//  lotery
//
//  Created by liang xin on 13-2-7.

//  Copyright (c) 2013 liang xin. All rights reserved.
//

#include <iostream>
#include "encapsulate.h"
#include <vector>
#include <set>
#include <time.h>

using namespace std;

extern bool Josephus(int, int);
extern bool parseFile(int);
extern set<int> lotery;

extern vector<myarray> redset;


int main(int argc, const char * argv[])
{

    // insert code here...
    
    // call srand here, only once.
    srand((unsigned)time(NULL));
    
    parseFile(6);
    
    bool retry = false;
    int retryCnt = 0;
    
#if 1
    
    do {
        retry = false;
        Josephus(33, 6);
        myarray random(lotery);
        
        for (vector<myarray>::iterator iter = redset.begin(); iter != redset.end(); ++iter) {
            if (random.isConflict(*iter, 5)) {
                retry = true;
                ++retryCnt;
                
                // very important!!! clear the random set before retry!
                lotery.clear();
                break;
            }
        }
    } while (retry);
    
    cout << endl << "##################################" << endl << "final result:" << endl;
	for (set<int>::iterator iter = lotery.begin(); iter != lotery.end(); ++iter)
		cout << *iter << "\t";
    cout << endl << "retry times:\t" << retryCnt << endl;
#endif
    
#if 1
    retryCnt = 0;
    for (vector<myarray>::iterator iter = redset.begin(); iter != redset.end(); ++iter) {
        for (vector<myarray>::iterator it = redset.begin(); it != redset.end(); ++it) {
            if (iter->isConflict(*it, 5) && iter != it) {
                ++retryCnt;
                break;
            }
        }
    }
    
    cout << endl << "the total count is:\t" << redset.size() << endl;
    
    cout << retryCnt << " of them are conflict with another" << endl;
    
#endif

	system("pause");
    
    return 0;
}
