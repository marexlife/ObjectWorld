#pragma once

#include "object/Macros.h"
#include "object/Object.h"

class PPlayer : public OObject {
    OOBJECT(PPlayer, OObject)

  public:
    void emerge() override {}
    void tick() override {}

    virtual ~PPlayer() override {}
};