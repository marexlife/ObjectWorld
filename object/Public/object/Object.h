#pragma once

#include "Macros.h"

class OObject {
    OOBJECT_ORIGIN(OObject)

  public:
    /// runs once at emerging of the object
    virtual void emerge() = 0;

    /// runs once per frame
    virtual void tick() = 0;

    virtual ~OObject() = default;
};