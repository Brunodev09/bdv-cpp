#include <string>

namespace Bdv {
	template <typename T>
	class Component {
	private:
		const static int nextId = 0;
	public:
		Component(T arr[], int s);
		static int getId();
		static int getNextId();
	};

	template <typename T>
	Component<T>::Component(T arr[], int s)
	{

	}

	template <typename T>
	int Component<T>::getId() {
		return Component<T>::nextId;
	}

	template <typename T>
	int Component<T>::getNextId() {
		return Component<T>::nextId + 1;
	}
}