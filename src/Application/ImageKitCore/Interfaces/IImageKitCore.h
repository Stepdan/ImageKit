#pragma once

#include "src/Application/ImageKitCore/Interfaces/IImageKitEffectApplier.h"
#include "src/Application/ImageKitCore/Interfaces/IImageKitIO.h"
#include "src/Application/ImageKitCore/Interfaces/IImageKitUndo.h"

namespace ImageKitCore::Interfaces {

class IImageKitCore
    : virtual public IImageKitEffectApplier
    , virtual public IImageKitIO
    , virtual public IImageKitUndo
{
public:
    virtual ~IImageKitCore() = default;

    static std::shared_ptr<IImageKitCore> Create();

    virtual IImageKitEffectApplier& GetEffectApplierEngine() = 0;
    virtual IImageKitIO& GetIOEngine() = 0;
    virtual IImageKitUndo& GetUndoEngine() = 0;

    const std::shared_ptr<Core::Interfaces::IDataImage> & GetDataImage() const;
};

}
