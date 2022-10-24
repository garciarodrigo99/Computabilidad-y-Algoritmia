#include "variable.h"
#include "loop.h"
#include "fMain.h"
#include "comments.h"

class CodeStructurer {

	public:
		CodeStructurer(std::string, std::string);
		~CodeStructurer();
		void Write(void);

	private:
		std::string program_name_;
		std::string out_file_;
		std::vector<Comments> comments_;
		std::vector<Loop> loops_;
		std::vector<Variable> variable_;
};