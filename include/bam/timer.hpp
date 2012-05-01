// (C) Copyright Stephan Dollberg 2012. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef TIMER_H
#define TIMER_H

#include <chrono>

namespace bam {

template<class resolution = std::chrono::milliseconds>
class timer {
private:
  std::chrono::time_point<std::chrono::high_resolution_clock> start_point;
  std::chrono::time_point<std::chrono::high_resolution_clock> last_epoch;

public:
  timer() : start_point(std::chrono::high_resolution_clock::now()), last_epoch(std::chrono::high_resolution_clock::now()) {}

  typename resolution::rep elapsed() {
    last_epoch = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<resolution>(last_epoch - start_point).count();
  }

  typename resolution::rep since_last_epoch() {
    auto ret = last_epoch;
    last_epoch = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<resolution>(std::chrono::high_resolution_clock::now() - ret).count();
  }

};

}


#endif // TIMER_H
