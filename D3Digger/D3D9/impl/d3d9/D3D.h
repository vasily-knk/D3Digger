#pragma once

#include "gen/d3d9/D3D.h"
#include "HierElem.h"
#include "fwd.h"

namespace D3Digger
{
namespace D3D9
{
namespace D3D
{

struct ProxyImpl
    : ProxyBase
    , HierElemAux
{

    static ProxyImplPtr create(IBasePtr pimpl);

private:
    ProxyImpl(IBasePtr pimpl);
    void init();

public:
    ULONG STDMETHODCALLTYPE Release() override;
};

} // namespace Device

} // namespace D3D9

} // namespace D3Digger
