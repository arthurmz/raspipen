//Devido a um detalhe de implementacao de c++, classes com templates devem ser implementadas no proprio .h

#pragma once

#include <iostream>
#include <queue>
#include <pthread.h>
using namespace std;

template <class T> class Pipe {
  std::queue<T> buffer;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
  public:
    Pipe(std::queue<T> init_buffer){
      buffer = init_buffer;
      pthread_mutex_init(&mutex, 0);
      pthread_cond_init(&cond, 0);   
    }
    Pipe(){
      pthread_mutex_init(&mutex, 0);
      pthread_cond_init(&cond, 0);
    }
    ~Pipe(){
      pthread_mutex_destroy(&mutex);
      pthread_cond_destroy(&cond);
    }
    void write(T);
    T read();
    int size();
    std::queue<T> getBuffer();
};

template <class T> int Pipe<T>::size(){
	return buffer.size();
}

template <class T> std::queue<T> Pipe<T>::getBuffer(){
	return buffer;
}

template <class T> T Pipe<T>::read(){
  
  pthread_mutex_lock(&mutex);
  while(buffer.size() == 0) {
    pthread_cond_wait(&cond, &mutex);
  }
  
  T item = buffer.front();
  buffer.pop();
  pthread_mutex_unlock(&mutex);
  return item;
}


template <class T> void Pipe<T>::write(T data){
  pthread_mutex_lock(&mutex);
  buffer.push(data);
  pthread_cond_signal(&cond);
  pthread_mutex_unlock(&mutex);
}

