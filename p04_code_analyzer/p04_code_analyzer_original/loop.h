#include <string>
#include <regex>

class Loop {

	public:
		Loop(std::string,int);
		~Loop();

		static bool isFor(std::string);
		static bool isWhile(std::string);
		static bool isLoop(std::string);
		friend std::ostream &operator<<(std::ostream &, Loop &);
	private:
		std::string type_;
		int start_;
};
