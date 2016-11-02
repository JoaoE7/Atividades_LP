template <class Object>
class AbsStack {
	public:
		AbsStack() {}
		virtual ~AbsStack(){}

		virtual void push(const Object & o) = 0;
		virtual Object pop() = 0;
		virtual Object top() const = 0;

		virtual bool isEmpty() const = 0;
		virtual void makeEmpty() = 0;

	private:
		AbsStack (const AbsStack<Object> & k) {}
};