#include "logger.h"
#include "asserts.h"

// TODO: replace 
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

bool8 init_logging()
{
  //TODO: create log file
  return TRUE;
}

void shutdown_logging()
{
  //TODO: cleanup logging & write queued entries
}

void logger(log_level level, const char* msg, ...) 
{
  const char* level_strings[6] = {
    "[FATAL]: ",
    "[ERROR]: ",
    "[WARN]: ",
    "[INFO]: ",
    "[DEBUG]: ",
    "[TRACE]: "
  };

  char outmsg[32000];
  memset(outmsg, 0, sizeof(outmsg));

  __builtin_va_list arg_ptr;
  va_start(arg_ptr, msg);
  vsnprintf(outmsg, sizeof(outmsg), msg, arg_ptr);
  va_end(arg_ptr);

  char msgbuffer[32000];
  sprintf(msgbuffer, "%s%s\n", level_strings[level], outmsg);
  printf("%s", msgbuffer);
}

void report_assert_failure(const char* expr, const char* msg, const char* filename, int32 line)
{
  logger(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: %s, in file: %s, at line: %d\n", expr, msg, filename, line);
}