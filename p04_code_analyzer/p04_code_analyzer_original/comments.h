#include <vector>
#include <string>
#include <regex>

class Comments {

	public:
		// Constructores y destructores
    Comments(std::string,int);	// No descripcion
		Comments(std::string);			// Descripcion
    ~Comments();

		// Getters y setters
		int GetEnd(void);
		int GetSize();
		int GetStart(void);
		bool isDescription(void);
		void SetEnd(int);

		// Funciones estáticas
		// static bool isMultiComment(std::string);
		// static bool isSingleComment(std::string);
		static bool isComment(std::string);
		static int Type(std::string);

		// Operaciones
		void AddString(std::string);
		void WriteAsReference(void);
		int BuildMultiComment();
		friend std::ostream &operator<<(std::ostream &, Comments &);

	private:
		bool isMultiCommentEnding(std::string);

	private:
    bool description_;
		int start_;
		int end_;
		std::vector<std::string> comments_;
};