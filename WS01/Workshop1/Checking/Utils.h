#ifndef _244_UTILS_H
#define _244_UTILS_H

namespace sdds {
  void flushkeys();
  bool ValidYesResponse(char ch);
  bool yes();
  void readCstr(char cstr[], int len);
  int readInt(int min, int max);
}

#endif // !244_UTILS_H
