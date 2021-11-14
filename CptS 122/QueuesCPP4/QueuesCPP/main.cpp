// This example illustrates how to build a queue w/ a linked list
// implementation from the ground up. We'll use the queue to simulate
// print jobs.

// History: 10/1 - Implemented dequeue (), Queue destructor, 
//                 isEmpty (), destroyQueue (), introduced more
//                 file processing (reading all contents in a file
//                 and outputting to a file).
//			9/28 - Implemented setters, constructor, enqueue ()
//                 for class Queue. Started discussing 
//                 file objects.
//          9/26 - Started declaring the members of class Node.

#include <fstream>
#include "Queue.h"

using std::fstream;
using std::ifstream;
using std::ofstream;

int main(void)
{
	Node n1("PJ1");

	Queue printJobs;

	ifstream input;//input("printjobs.txt");

	input.open("printjobs.txt"); // note: we have not created a printjobs.txt yet!!!
	string pj;

	Queue q;
	//input >> pj;

	while (!input.eof()) // read all of the printjobs from the file
	{
		char line[100];
		input.getline(line, 100); // grab a complete line from the file!
		q.enqueue(line); // enqueue the printjob in the order they arrive
	}

	string s2 = "";
	s2 = q.dequeue(); // does the dequeue work?
	cout << "deleted item: " << s2 << endl;

	//ofstream
	fstream output;
	output.open("outputData.txt", std::ios::out); // assign the stream as output

	output << s2;

	input.close();
	output.close();



	return 0;
}