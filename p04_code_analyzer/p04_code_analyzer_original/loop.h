#include <string>
#include <regex>

class Loop {

	public:
		Loop(/* args */);
		~Loop();

		static bool isFor(std::string);
		static bool isWhile(std::string);

	private:
		int start_;
};
