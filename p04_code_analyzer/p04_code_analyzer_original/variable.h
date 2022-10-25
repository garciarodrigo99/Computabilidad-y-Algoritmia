#include <string>
#include <regex>

class Variable{

	public:
  Variable(std::string,int);
	~Variable();

	static bool isVariable(std::string);

	friend std::ostream &operator<<(std::ostream &, Variable &);

	private:
		static bool isInteger(std::string);
		static bool isDouble(std::string);

	private:
		int n_line_;
		std::string type_;
		std::string name_;
		int integerValue;
		double doubleValue;
		bool initialization_;
};
