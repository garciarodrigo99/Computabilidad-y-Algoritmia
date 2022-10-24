#include <vector>
#include <string>
#include <regex>

class Comments {

	public:
    Comments(/* args */);
    ~Comments();
		static bool isDescription(std::string);
		static bool isComment(std::string);

	private:
    bool description_;
		int start_;
		int end_;
		std::vector<std::string> text_;
};