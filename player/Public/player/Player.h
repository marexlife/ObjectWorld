#pragma once

#include "object/Macros.h"
#include "object/Object.h"

class OPlayer final : public OObject {
    OOBJECT(OPlayer)

  public:
    void emerge() override {}
    void tick() override {}

    ~OPlayer() override {}
};