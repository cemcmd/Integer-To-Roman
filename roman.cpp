#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		cout << "Error: No arguments" << endl;
		return 1;
	}
	int inLength, numValue, indexStart, inIndex;
	string roman, input;

			      // 0   1   2   3   4   5   6   7
	const char symbols[] = {'I','V','X','L','C','D','M','U'};

	input = argv[1];
	
	inLength = input.length();

	if(inLength == 1) // think theres a way to make this beter?
		indexStart = 0;
	else if(inLength == 2)
		indexStart = 2;
	else if(inLength == 3)
		indexStart = 4;
	else if(inLength == 4)
		indexStart = 6;
	else
	{
		if(inLength <= 0)
			cout << "Error: Input too small" << endl;
		else if(inLength > 5)
			cout << "Error: Input too big" << endl;
		else
			cout << "Error: Something to do with size of input" << endl;
		return 1;
	}

	inIndex = 0;

	while(inIndex < inLength)
	{
		switch(input[inIndex])
		{
			case '4':
				roman += symbols[indexStart];
				roman += symbols[indexStart+1];
				break;
			case '9':
				roman += symbols[indexStart];
				roman += symbols[indexStart+2];
				break;
			default:
				numValue = (int)input[inIndex] - '0'; // Aparently this works as 48
				if(numValue >= 5) //uses loop anyway
				{
					roman += symbols[indexStart+1];
					numValue -= 5;
				}
				if(numValue < 4)
				{
					for(int i = 0; i < numValue; i++)
						roman += symbols[indexStart];
				}
				break;
		}
		inIndex++;
		indexStart -= 2;
	}

	cout << roman << endl;

	return 0;
}
