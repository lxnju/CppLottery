// joseph-ring.cpp : 
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <set>

using namespace std;

typedef struct LNode{
	int data;
	LNode *next;
} *List; 

set<int> lotery;

bool Josephus(int n, int times)
{
	if (n < 1)
		return false;

	List head, tail, p, h;

	// create head node.
	p = (List) malloc(sizeof(LNode));
	p->data = 1;
	head = tail = p;

	// build list
	for (int i = 2; i <= n; ++i)
	{
		p = (List) malloc(sizeof(LNode));
		p->data = i;
		tail->next = p;
		tail = p;
	}
    
    // loop back
	tail->next = head;

	int cnt = 0;
	int gap;
    
    h = tail;   // make sure h->next = p
    p = head;   // random from head
    
    //we can't call srand here. it will make rand remain same every time
    //srand((unsigned)time(NULL));
	
	while (p->next != p && cnt < times)
	{
		gap = rand()%(n-cnt);
		
        // jump the gap
		for (int i = 0; i < gap; ++i)
		{
			h = p;
			p = p->next;
		}
        
        // pick this number
		h->next = p->next;
		lotery.insert(p->data);
		free(p);
		p = h->next;

		++cnt;
	}

	//cout << endl << "result:" << endl;
	//for (set<int>::iterator iter = lotery.begin(); iter != lotery.end(); ++iter)
	//	cout << *iter << "\t";
 //   cout << endl;
		
    // do clear
    head = p;
    while (head != p->next) {
        h = p;
        p = p->next;
        free(h);
    }
    // now clear the last one
    free(p);
    
    return true;
}


