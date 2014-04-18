#pragma once

#include "../d3d9_gen/Device.h"
#include "HierElem.h"
#include "fwd.h"

namespace D3Digger
{
namespace D3D9
{
namespace Device
{

struct ProxyImpl
    : IHierElem
    , ProxyBase
{
    static ProxyImplPtr create(IBasePtr pimpl);
    ULONG STDMETHODCALLTYPE Release() override;

private:
    ProxyImpl(IBasePtr pimpl);

private:
    HierElemKeeper keeper_;
};

} // namespace Device

} // namespace D3D9

} // namespace D3Digger
