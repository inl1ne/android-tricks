#include "BackgroundThread.h"

BackgroundThread::BackgroundThread()
    : mRunning(false) {
}

BackgroundThread::~BackgroundThread()
{
  if(mRunning.load(std::memory_order_acquire)) {
    stop();
  }
}

int BackgroundThread::run(BackgroundThread::threadfunc_t fn) {
  if (mRunning.load(std::memory_order_acquire)) {
    return E_ALREADY;
  }

  mRunning.store(false, std::memory_order_release);
  mThread = std::thread([=]{
    while (mRunning.load(std::memory_order_acquire)) {
      fn();
    }
  });
  return OK;
}

int BackgroundThread::stop() {
  if (!mRunning.load(std::memory_order_acquire)) {
    return E_ALREADY;
  }

  mRunning.store(false, std::memory_order_release);
  mThread.join();
  return OK;
}
