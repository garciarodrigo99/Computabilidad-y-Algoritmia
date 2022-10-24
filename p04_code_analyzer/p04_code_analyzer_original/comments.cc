#include "comments.h"

#include <iostream>

Comments::Comments(std::string paramString,int paramStart) : 
									start_(paramStart) {
	comments_.push_back(paramString);
}

Comments::Comments(std::string paramString) {
	comments_.push_back(paramString);
	description_ = true;
	start_ = 0;
}

Comments::~Comments() {}

int Comments::GetEnd() { return end_; }

int Comments::GetStart() { return start_; }

bool Comments::isDescription() { return description_; }

void Comments::SetEnd(int paramEnd) { end_ = paramEnd; }

bool Comments::isMultiComment(std::string stringParam) {
	std::regex rexp("(\\/\\*.*)");
	return (std::regex_search(stringParam, rexp));
}

bool Comments::isSingleComment(std::string stringParam) {
	std::regex rexp("(\\/\\/.*)");
	return (std::regex_search(stringParam, rexp));
}

void Comments::AddString(std::string paramString) {
	comments_.push_back(paramString);
}

void Comments::WriteAsReference(void) {
	if (isDescription()) {
		std::cout << "[Line " << start_ << "-" << end_ << "] "
		"DESCRIPTION\n";
	} else {
		std::cout << *this << std::endl;
	}
}

std::ostream &operator<<(std::ostream & os, Comments & paramComments) {
	os << "[Line " << paramComments.start_;
	if (paramComments.comments_.size() > 1) {
		os << "-" << paramComments.end_;
	}
	os << "] ";
	for (size_t i = 0; i < paramComments.comments_.size(); i++) {
		os << paramComments.comments_.at(i) << std::endl;
	}
	return os;
}