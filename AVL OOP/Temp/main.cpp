#include <iostream>
#include"Pipeline.h"
#include"Prime.h"
#include"CoPrime.h"
#include"OddEven.h"
#include"EvenOddPair.h"
#include"AVL.h"
using namespace std;

int main()
{
	Pipeline pipe;
	Pipeline pipe2;
	pipe.setNextFunction(new Prime());
	pipe2.setNextFunction(new CoPrime());
	pipe.setNextFunction(new OddEven());
	pipe.setNextFunction(new EvenOddPair());
	AVL obj;
	cout << "\t\tWelcom to Pipelined AVL" << endl;
	system("pause");

	obj.avlInsert(30, pipe.nextFunction);
	cout << endl;
	obj.avlInsert(20, pipe.nextFunction);
	cout << endl;
	obj.avlInsert(35, pipe.nextFunction);
	cout << endl;
	obj.avlInsert(15, pipe.nextFunction);
	cout << endl;
	obj.avlInsert(25, pipe.nextFunction);
	cout << endl;
	obj.avlInsert(10, pipe.nextFunction);
	cout << endl;
	obj.avlInsert(15, pipe2.nextFunction);
	cout << endl;
	obj.avlInsert(3, pipe.nextFunction);
	cout << endl;
	cout << "Postorder: " << endl;
	obj.postOrder();

}
