#include <string>
#include <regex>

class Loop {

	public:
		Loop(/* args */);
		~Loop();

		static bool isFor(std::string);
		static bool isWhile(std::string);
		static bool isLoop(std::string);

	private:
		int type_;
		int start_;
};
