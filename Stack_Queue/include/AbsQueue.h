template <class Object>
class AbsQueue {
	public:
		AbsQueue() {}
		virtual ~AbsQueue() {}

		virtual void enqueue (const Object & x) = 0;
		virtual Object dequeue() = 0;
		virtual Object getFront() const = 0;

		virtual bool isEmpty() const = 0;
		virtual void makeEmpty() = 0;

	private:
		AbsQueue (const AbsQueue<Object> & k) {}
};