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
		void ReadFile();
		void FillContent();

	private:
		std::string program_name_;
		std::string out_file_;
		//fMain main_;
		bool main_;
		std::vector<Comments> comments_;
		std::vector<Loop> loops_;
		std::vector<Variable> variable_;
		std::vector<std::string> lines_;
};