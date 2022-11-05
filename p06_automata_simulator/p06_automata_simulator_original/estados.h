
class State {

	public:
		State(int, bool, bool);
		~State();

		int getIdentifier();
		bool isInitialState();
		bool isFinalState();

	private:
		int identifier_;
		bool initialState_;
		bool finalState_;
};
