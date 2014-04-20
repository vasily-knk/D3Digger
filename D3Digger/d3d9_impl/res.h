#pragma once

namespace D3Digger
{

namespace D3D9
{

typedef shared_ptr<IDirect3DResource9> IResPtr;

struct IResShare;
typedef shared_ptr<IResShare> IResSharePtr;

struct IResShare
{
    virtual ~IResShare() {}
    virtual IResPtr getSharedRes() = 0;
};


} // namespace D3D9
    
} // namespace D3Digger