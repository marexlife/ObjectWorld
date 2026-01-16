#pragma once

#include "Macros.h"
#include <print>

class OObject {
    OOBJECT_ORIGIN(OObject)

  public:
    /// runs once at emerging of the object
    virtual void emerge() {
        std::println("{}: emerge", getObjectName());
    }

    /// runs once per frame
    virtual void tick() { std::println("{}: tick", getObjectName()); }

    virtual ~OObject() = default;
};