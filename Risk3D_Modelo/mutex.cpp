#include "mutex.h"

Mutex::Mutex(){
	InitializeCriticalSection(&cs);
}

void Mutex::bloquear(){
	EnterCriticalSection(&cs);
}

void Mutex::desbloquear(){
	LeaveCriticalSection(&cs);
}

Mutex::~Mutex(){
	DeleteCriticalSection(&cs);
}
