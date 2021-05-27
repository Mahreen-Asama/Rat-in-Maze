#include<iostream>
#include<fstream>
#include"Pair.h"
#include"MyStack.h"
#include"MyStack.cpp"
using namespace std;

bool visited(MyStack<Pair>& s1, int i, int j)
{
	/*
	* function checks whether pair q(i,j) already exists in stack s1 or not
	* arguments: stack(to be traversed), i,j(pair)
	* return: true(if pair exists) / false(if not)
	*/
	Pair q(i, j);
	bool rr = false;						//assume pair not exists in s1
	int size = s1.getSize();
	MyStack<Pair> s2(size);					//to store stack s1 elements,(traverse/scan s1 for checking) 
	for (int i = 0; i < size; i++)
	{
		Pair n = s1.pop();
		if (n == q)								//operator overloaded, if n==q,
		{
			s2.push(n);
			rr = true;							//pair exists in stack s1
			break;
		}
		s2.push(n);								//storing s1 elements
	}
	while (!s2.isEmpty())
	{
		s1.push(s2.pop());						//put all data again in s1 that was poppped to scan
	}
	return rr;
}

bool findPath(char **arr, int size, Pair source, Pair destination)
{
	/*
	* function returns true if path available, returns false otherwise, also displays path if found
	* arguments: 2D maze array, source position, destination position
	* return: true/false
	*/
	MyStack<Pair> s1;
	MyStack<Pair> deadEnds;
	fstream f;
	//.................checking and start entring path into stack..................;
	s1.push(source);							//push source positin 
	bool v1, v2, check = true;
	Pair p = source;
	while (!(p == destination))					//while reach at destination (if path available)
	{
		int i, j, bol = 1;						//'bol' to handle if else
		if (bol && p.gety() >= 0 && p.gety() < size - 1)		//RIGHT
		{
			i = p.getx();
			j = p.gety() + 1;
			v1 = visited(s1, i, j);				//check if this cell already visited(present in stack)
			if (deadEnds.isEmpty())				
				v2 = false;
			else
				v2 = visited(deadEnds, i, j);	//check if this pair is some dead-end or not

			if ((v1 == false) && (v2 == false) && (arr[i][j] == '0' || arr[i][j] == 'c'))
			{
				p.setValues(i, j);				
				s1.push(p);						//push path
				bol = 0;
			}
		}
		if (bol && p.getx() >= 0 && p.getx() < size - 1)			//DOWN
		{
			i = p.getx() + 1;
			j = p.gety();
			v1 = visited(s1, i, j);				//check if this cell already visited(present in stack)
			if (deadEnds.isEmpty())			
				v2 = false;
			else
				v2 = visited(deadEnds, i, j);	//check if this pair is some dead-end or not
			if ((v1 == false) && (v2 == false) && (arr[i][j] == '0' || arr[i][j] == 'c'))
			{
				p.setValues(i, j);				
				s1.push(p);
				bol = 0;
			}
		}
		if (bol && p.gety() > 0 && p.gety() < size)				//LEFT
		{
			i = p.getx();
			j = p.gety() - 1;
			v1 = visited(s1, i, j);				//check if this pair is already present in stack
			if (deadEnds.isEmpty())
				v2 = false;
			else
				v2 = visited(deadEnds, i, j);	//check if this pair is some dead-end or not

			if ((v1 == false) && (v2 == false) && (arr[i][j] == '0' || arr[i][j] == 'c'))
			{
				p.setValues(i, j);			
				s1.push(p);
				bol = 0;
			}
		}
		if (bol && p.getx() > 0 && p.getx() < size)				//UP
		{
			i = p.getx() - 1;
			j = p.gety();
			v1 = visited(s1, i, j);			//check if this pair is already present in stack or not
			if (deadEnds.isEmpty())			//check if this pair is some dead-end or not
				v2 = false;
			else
				v2 = visited(deadEnds, i, j);

			if ((v1 == false) && (v2 == false) && (arr[i][j] == '0' || arr[i][j] == 'c'))
			{
				p.setValues(i, j);			
				s1.push(p);
				bol = 0;
			}
		}
		if (bol == 1)						//means non movement done in 4 direc, it is a dead end, 
		{
			deadEnds.push(s1.pop());		//backtrack
			if (s1.isEmpty())				//means no path to go from source in either 4 directions
			{
				check = false;				//# end everything
				break;
			}
			p = s1.Top();					//back to previous visited(present in stack) cell
		}
	}
	//cout << "s1 size: " << s1.getSize() << endl;
	//........................output to console and file side by side................
	f.open("out.txt", ios::out);
	f << size << endl;							//write to file
	f << source.getx() << " " << source.gety() << endl;
	f << destination.getx() << " " << destination.gety() << endl;
	cout << size << endl;							//write to console
	cout << source.getx() << " " << source.gety() << endl;
	cout << destination.getx() << " " << destination.gety() << endl;
	if (check)
	{
		MyStack<Pair> s2;
		while (!s1.isEmpty())
		{
			s2.push(s1.pop());						//pushing path in reverse order(source to destination)
		}
		while (!s2.isEmpty())
		{
			Pair path = s2.pop();
			int m = path.getx();
			int n = path.gety();
			f << "(" << m << "," << n << ")";		//write to file
			cout << "(" << m << "," << n << ")";	//write to console
			arr[m][n] = '*';
		}
		arr[source.getx()][source.gety()] = 'm';						//to identify start_end
		arr[destination.getx()][destination.gety()] = 'c';
	}
	else
	{
		f << "\nThere is no path from source to destination";
		cout << "\nThere is no path from source to destination";
	}
	f << "\n\n";						
	cout << "\n\n";
	for (int i = 0; i < size; i++)				//now print matrix with path
	{
		for (int j = 0; j < size; j++)
		{
			f << arr[i][j] << " ";
			cout << arr[i][j] << " ";
		}
		f << endl;
		cout << endl;
	}
	f.close();
	return check;								//path founded and printed successfully
}

int main()
{
	fstream f;
	int size, x, y;
	char c;
	f.open("in.txt", ios::in);
	f >> size;								//read order/size of matrix
	f >> x >> y;							//read source location from file
	Pair source(x, y);
	f >> x >> y;
	Pair destination(x, y);					//read destination location from file
	char** arr = new char* [size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new char[size];			//2D dynamic array to store binary matrix
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			f >> c;
			arr[i][j] = c;					//initializing 2D matrix
		}
	}
	f.close();
	/*........print to check (data read correct from file).......
	cout << "size: " << size << endl;
	cout << "source: " << source.x << " " << source.y << endl;
	cout << "destination: " << destination.x << " " << destination.y << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	*/
	if (!findPath(arr, size, source, destination))		//if path not found
	{
		cout << "\nRat cannot escape |,():>|\n";
	}
	for (int i = 0; i < size; i++)						//2D matrix deleted
		delete[]arr[i];
	delete[]arr;
	return 0;
}