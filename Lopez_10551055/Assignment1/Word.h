#include <iostream>
#include <string>
using namespace std;

class Word
{
private:
	string name;
	string type;
	string definition;

public:
	Word() {};
	Word(string name, string type, string definition)
	{
		this->name = name;
		this->type = type;
		this->definition = definition;
	};
	void setName(string name) { this->name = name; }
	void setType(string type) { this->type = type; }
	void setDefinition(string defintion) { this->definition = defintion; }
	string getName() { return this->name; }
	string getType() { return this->type; }
	string getDefinition() { return this->definition; }

};