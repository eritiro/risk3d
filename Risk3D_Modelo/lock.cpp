#include "lock.h"

Lock::Lock(Mutex& mutex) : mutex(mutex){
	mutex.bloquear();
}

Lock::~Lock(){
	mutex.desbloquear();
}
