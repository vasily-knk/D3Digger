#pragma once

#include "gen/d3d9/Device.h"
#include "HierElem.h"
#include "fwd.h"

namespace D3Digger
{
namespace D3D9
{
namespace Device
{

ProxyImplPtr createProxy(D3D::ProxyImplPtr parent, IBasePtr pimpl);

struct ProxyImpl
    : ProxyBase
    , HierElem
{

private:
    ProxyImpl(D3D::ProxyImplPtr parent, IBasePtr pimpl);

public:
    ULONG STDMETHODCALLTYPE Release() override;
};

} // namespace Device

} // namespace D3D9

} // namespace D3Digger
