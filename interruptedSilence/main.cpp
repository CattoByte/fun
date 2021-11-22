#define REPEAT_TIMES(times,symbol) for (size_t symbol = 0; symbol < times; symbol++)

#define PATH_TO_SFX "SFX"
#define MIN_TIME 1000
#define MAX_TIME 60000

#include <filesystem>
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <random>
#include <thread>

using namespace std;

size_t getRandom()
{
	uniform_int_distribution<> distributor(MIN_TIME, MAX_TIME);
	/* Info:
	 * 	Having nothing makes the generator recreate everytime, which in turn gets the same seed and the same number every time
	 * 	Having "thread_local" makes each thread have their own generator, but they all have the same starting value so they give different numbers, but not different between threads
	 *	Having "static" creates the generator one time for all threads, so when one wants to generate a number it changes the seed automatically (or whatever mt19937 does to change)
	 *	You could do "static thread_local", but that's only needed in C, as there you needed to specify "static" or "extern", but in C++ it is automatically "static"*/
	static mt19937 generator(time(NULL));
	return distributor(generator);
}

void audioLoop(filesystem::directory_entry entry)
{
	while (true) {
		size_t random = getRandom();
		cout << entry.path().native() << "\t Next in " << random << "ms" << endl;
		this_thread::sleep_for(chrono::milliseconds(random));
		string command = "aplay -q ";
		command.append(entry.path().native());
		command.append(" &");	//End result should be "aplay -q (path) &"
		system(command.c_str());
	}
}
		

int main()
{
	vector<thread>				audioThreads;
	vector<filesystem::directory_entry>	entries;

	for (filesystem::directory_entry entry : filesystem::recursive_directory_iterator(PATH_TO_SFX)) if (!entry.is_directory()) entries.push_back(entry);
	audioThreads.resize(entries.size());
	cout << "Starting SFX threads..." << endl;
	REPEAT_TIMES(entries.size(), i) {
		audioThreads[i] = thread(audioLoop, entries[i]);
		audioThreads[i].detach();
		this_thread::sleep_for(100ms);		//Do this so the thread couts dont interefere
	}
	cout << endl << "Finished loading SFX threads!" << endl << "Halting main thread, exit with Ctrl+C" << endl << endl;
	while (true) {}
	return 0;
}
