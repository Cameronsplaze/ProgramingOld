/*
	Cameron Showalter
	OS 321
	Homework 2
	Feb 13, 2018

*/

#include "sa2a.h"
#include <thread>
#include <vector>
#include <queue>
#include <iostream>
#include <mutex>

void run(std::queue<int> &userInput, std::queue<int> &output, std::vector<bool> &threadDone, std::mutex &userinput_mutex, std::mutex &output_mutex, std::mutex &doneVec_mutex, int id)
{
	bool allDone = false;
	while(!allDone)
	{
	    userinput_mutex.lock();
	    int savedValue;
	    int calculatedValue;
	    if(userInput.size() != 0)
	    {
	    	savedValue = userInput.front();
	    	userInput.pop();
	    	userinput_mutex.unlock();

	    	calculatedValue = sa2a(savedValue);

	    	output_mutex.lock();
	    	output.push(id);
	    	output.push(savedValue);
	    	output.push(calculatedValue);
	    	output_mutex.unlock();

	    }
	    else
	    {
	    	allDone = true;
	    	userinput_mutex.unlock();

	    	doneVec_mutex.lock();
	    	threadDone[id] = true;
	    	doneVec_mutex.unlock();
	    }
	}
}



int main()
{
	int numThreads = 6;

	std::mutex userinput_mutex;
	std::mutex output_mutex;
	std::mutex doneVec;

	// queue of all input from user
	std::queue<int> userInput;
	// queue for printing output when threads prossess it
	std::queue<int> output;
	// each element says if that thread is completely done. 
	std::vector<bool> threadDone(numThreads, false);

	bool inputDone = false;
	while(!inputDone)
	{
		int currInput = 0;
		std::cout << "Enter a positive integer (or 0 to end input): ";

		std::cin >> currInput;

		if(currInput != 0)
		{
			userInput.push(currInput);
		}
		else
		{
			inputDone = true;
		}
	}

	// User Input Done
	std::vector<std::thread> threads;
	for(int i=0; i<numThreads; ++i)
	{
		threads.push_back( std::thread(run, std::ref(userInput), std::ref(output), std::ref(threadDone), std::ref(userinput_mutex), std::ref(output_mutex), std::ref(doneVec), i) );
	}

	bool allWorkDone = false;
	while(!allWorkDone)
	{
		output_mutex.lock();
		while(output.size() > 0)
		{
			// Threads will lock output, then push on in mults of 3
			int id = output.front();
			output.pop();
			int savedValue = output.front();
			output.pop();
			int calculatedValue = output.front();
			output.pop();

			std::cout << "Thread " << id << " ran sa2a.h(" << savedValue << ") returned: " << calculatedValue << std::endl;
		}
		output_mutex.unlock();

		bool threadNotDone = false;
		doneVec.lock();
		for(int i=0; i<threadDone.size(); ++i)
		{
			if(threadDone[i] == false)
			{
				threadNotDone = true;
			}
		}
		doneVec.unlock();

		output_mutex.lock();
		// Once all the threads are done, and nothing is left to print, you can quit
		if(threadNotDone == false && output.size() == 0)
		{
			allWorkDone = true;
		}
		output_mutex.unlock();

	}

	// Join everything back together
	for(int i=0; i<numThreads; ++i)
	{
		threads[i].join();
	}

	return 0;
}