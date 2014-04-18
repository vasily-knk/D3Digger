#pragma once

#include "../d3d9_gen/Texture.h"
#include "HierElem.h"
#include "fwd.h"

namespace D3Digger
{
namespace D3D9
{
namespace Texture
{

struct ProxyImpl
    : IHierElem
    , ProxyBase
    , enable_shared_from_this<ProxyImpl>
{
    static ProxyImplPtr create(IBasePtr pimpl);
    ULONG STDMETHODCALLTYPE Release() override;

public:
    ProxyImplPtr getShared();

private:
    ProxyImpl(IBasePtr pimpl);

private:
    HierElemKeeper keeper_;
};

} // namespace Texture

} // namespace D3D9

} // namespace D3Digger
