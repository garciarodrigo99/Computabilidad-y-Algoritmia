#include <string>
#include <regex>

class Variable{

	public:
  Variable(/* args */);
	~Variable();

	static bool isInteger(std::string);
	static bool isDouble(std::string);

	private:
		int line_;
		std::string type_;
};
