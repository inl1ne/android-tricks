#ifndef BACKGROUNDTHREAD_H
#define BACKGROUNDTHREAD_H

#include <atomic>
#include <functional>
#include <thread>

/** Convenient abstraction around std::thread.
 *
 * std::thread seems to be oriented toward relatively
 * short-lived threads that have well-defined join
 * points. This class wraps the still-common case of
 * a thread that loops until it's told not to.
 */
class BackgroundThread
{
public:
  typedef std::function<void ()> threadfunc_t;
  enum errors {
    E_ALREADY = 0x80000000,
    OK = 0,
  };

  BackgroundThread();
  ~BackgroundThread();

  int run(threadfunc_t fn);
  int stop();

  bool isRunning() {return mRunning.load();}
private:
  std::atomic<bool> mRunning;
  std::thread mThread;
};

#endif // BACKGROUNDTHREAD_H
