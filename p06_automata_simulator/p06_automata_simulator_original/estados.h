#pragma once

#include <iostream>

class State {

	public:
		State(int);
		State(int, bool, bool);
		~State();

		int getIdentifier() const;
		bool isInitialState();
		bool isFinalState();

		void setInitialState();
		void setFinalState();

		bool operator<(const State) const;
		friend std::ostream &operator<<(std::ostream &, State &);
		friend std::ostream &operator<<(std::ostream &, const State &); 
		void operator=(const State);
		bool operator==(const State) const;

	private:
		int identifier_;
		bool initialState_;
		bool finalState_;
};
