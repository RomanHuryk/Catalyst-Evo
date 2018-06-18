#include "LoggerGroup.h"
#include <algorithm>

namespace Logging {

LoggerGroup::LoggerGroup(Level level) : CommonLogger(level) {
}
//------------------------------------------------------------- Seperator Code -------------------------------------------------------------//
void LoggerGroup::addLogger(ILogger& logger) {
  loggers.push_back(&logger);
}
//------------------------------------------------------------- Seperator Code -------------------------------------------------------------//
void LoggerGroup::removeLogger(ILogger& logger) {
  loggers.erase(std::remove(loggers.begin(), loggers.end(), &logger), loggers.end());
}
//------------------------------------------------------------- Seperator Code -------------------------------------------------------------//
void LoggerGroup::operator()(const std::string& category, Level level, boost::posix_time::ptime time, const std::string& body) {
  if (level <= logLevel && disabledCategories.count(category) == 0) {
    for (auto& logger : loggers) {
      (*logger)(category, level, time, body);
    }
  }
}
//------------------------------------------------------------- Seperator Code -------------------------------------------------------------//
}
