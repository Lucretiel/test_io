#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int do_some_work(istream& istr)
{
	unsigned num_ints = 0;
	istr >> num_ints;

	vector<int> ints(num_ints, 0);

	for(int& i : ints)
		istr >> i;

	int sum = 0;
	for(int& i : ints)
		sum += i;

	return sum;
}

void print_some_work(int i, unsigned c, ostream& ostr)
{
	ostr << "Case #" << c + 1 << ": " << i << endl;
}

void do_all_the_work(istream& istr, ostream& ostr)
{
	unsigned num_work = 0;
	istr >> num_work;
	for(unsigned i = 0; i < num_work; ++i)
		print_some_work(do_some_work(istr), i, ostr);
}

int main(int argc, const char** argv)
{
	vector<string> args{argv, argv + argc};

	string infile;
	string outfile;

	for(string& arg : args)
	{
		if(arg.compare(0, 2, "-i") == 0)
			infile = arg.substr(2);
		else if(arg.compare(0, 2, "-o") == 0)
			outfile = arg.substr(2);
	}

	ifstream istr;
	ofstream ostr;

	if(!infile.empty())
		istr.open(infile);

	if(!outfile.empty())
		ostr.open(outfile);

	do_all_the_work(
		istr.is_open() ? istr : cin,
		ostr.is_open() ? ostr : cout);
}
