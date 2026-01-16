#pragma once

#define OOBJECT(OBJECT_NAME)                \
  private:                                  \
    using This = OBJECT_NAME;               \
                                            \
  public:                                   \
    const char *getName() {                 \
        return #OBJECT_NAME;                \
    }                                       \
                                            \
  private:

#define OPROEPERTY()