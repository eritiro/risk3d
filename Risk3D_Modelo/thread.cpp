#include "thread.h"

Thread::Thread() : esta_corriendo(false){
}

void Thread::comenzar(){
	esta_corriendo = true;
	handler = CreateThread(NULL,0,Thread::ejecutar_thread,this,0,&tid);
	if(handler == NULL)
		throw ExcepcionDeConcurrencia("No se puede iniciar el hilo.");
}

#pragma warning(chequear como se hace para frenar a la fuerza un thread.)
void Thread::frenar(){
	BOOL ret;
	do{
		ret = GetExitCodeThread(handler,&tid);
		if (ret && (tid == STILL_ACTIVE))
			Sleep(50);
	}while(ret && (tid == STILL_ACTIVE));
	CloseHandle(handler);
}

void Thread::unir(){
	while(esta_corriendo){
		Sleep(50);
	}
	CloseHandle(handler);
}

Thread::~Thread(){
	if (esta_corriendo)
		this->frenar();
}

void Thread::dormir(unsigned long milisegundos){
	Sleep(milisegundos);
}
	
DWORD WINAPI Thread::ejecutar_thread(LPVOID arg){
	Thread* instancia = (Thread*) arg;
	instancia->ejecutar();
	instancia->esta_corriendo=false;
	return NULL;	
}
