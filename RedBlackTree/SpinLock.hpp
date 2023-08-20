#include <mutex>

using namespace std;
class Spinlock {
public:
	void Lock()
	{
		while (lock.test_and_set(memory_order_acquire)) {

		}
	}
	bool TryLock()
	{
		return !lock.test_and_set(memory_order_acquire);
	}
	void Unlock()
	{
		lock.clear(memory_order_release);
	}

private:
	atomic_flag lock = ATOMIC_FLAG_INIT;
};