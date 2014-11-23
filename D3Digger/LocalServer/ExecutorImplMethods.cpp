#include "stdafx.h"
#include "ExecutorImpl.h"

namespace D3D9
{
namespace Client
{

vector<vector<ExecutorImpl::Method>> ExecutorImpl::getMethods() const
{
    vector<vector<Method>> methods(static_cast<size_t>(D3D9::Interfaces::TOTAL));

#define ADD_PROC(name) \
    methods.at(static_cast<size_t>(D3D9::Interfaces::name)) = getMethods##name();

    ADD_PROC(BASE)
    D3D9_LIST_INTERFACES(ADD_PROC)

#undef ADD_PROC

    return methods;
}

vector<ExecutorImpl::Method> ExecutorImpl::getMethodsBASE() const
{
    vector<ExecutorImpl::Method> methods = 
    {
        make_pair(boost::bind(&ExecutorImpl::Direct3DCreate9, this, _1, _2), "Direct3DCreate9"),
    };
    return methods;
};


#include "d3d9/undef.h"

#define MY_BEGIN_INTERFACE(name) \
    vector<ExecutorImpl::Method> ExecutorImpl::getMethods##name() const \
    { \
        typedef D3D9::Server::IProc<name> IProc; \
        typedef D3D9::Methods_##name MethodsEnum; \
        auto proc = proc##name##_; \
        vector<ExecutorImpl::Method> methods(static_cast<size_t>(MethodsEnum::TOTAL)); 


#define MY_BEGIN_INTERFACE_(name, parent) MY_BEGIN_INTERFACE(name)   

#define MY_END_INTERFACE \
        return methods; \
    }

#define MY_STDMETHOD(name, args) methods.at(static_cast<size_t>(MethodsEnum::name)) = make_pair(bind(&IProc::name, proc, _1, _2), #name);
#define MY_STDMETHOD_(ret_type, name, args) MY_STDMETHOD(name, args)

#include "d3d9/decl.h"
#include "d3d9/undef.h"

    

} // namespace Client

} // namespace D3D9