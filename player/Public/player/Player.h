#pragma once

#include "object/Macros.h"
#include "object/Object.h"

class PPlayer : public OObject {
    OOBJECT(PPlayer, OObject)

  public:
    /// runs once at emerging of the object
    void emerge() override { Super::emerge(); }

    /// runs once per frame
    void tick() override { Super::tick(); }

    virtual ~PPlayer() override {}
};