#include <string>
#include <regex>

class fMain{

	public:
    fMain(/* args */);
    ~fMain();
	static bool isMain(std::string);

	private:
    std::string main_;
};