#pragma once

template<typename T>
struct IProxyExt
{

};


template<>
struct IProxyExt<IDirect3DTexture9>
{
    virtual void invalidate() = 0;
    virtual optional<int> lastUpdateFrame() const = 0;
};

template<>
struct IProxyExt<IDirect3DSurface9>
{
    virtual void invalidate() = 0;
};

template<>
struct IProxyExt<IDirect3DDevice9>
{
    virtual bool getDisableVBLocks() const = 0;
    virtual int getCurrentFrame() const = 0;
    virtual optional<int> getLastAllowedLockFrame() const = 0;

    virtual void appendVBLock(size_t size) = 0;
    virtual void appendTexLock(size_t size) = 0;
};
