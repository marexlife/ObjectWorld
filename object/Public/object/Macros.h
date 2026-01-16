#pragma once

#define OOBJECT_ORIGIN(OBJECT_NAME)                                  \
  private:                                                           \
    using This = OBJECT_NAME;                                        \
                                                                     \
  public:                                                            \
    virtual const char *getObjectName() { return #OBJECT_NAME; }     \
                                                                     \
  private:

#define OOBJECT(OBJECT_NAME)                                         \
  private:                                                           \
    using This = OBJECT_NAME;                                        \
                                                                     \
  public:                                                            \
    virtual const char *getObjectName() override {                   \
        return #OBJECT_NAME;                                         \
    }                                                                \
                                                                     \
  private:

#define OPROEPERTY()