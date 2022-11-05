#pragma once

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
		bool operator==(const State) const;
	private:
		int identifier_;
		bool initialState_;
		bool finalState_;
};
