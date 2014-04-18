#pragma once

namespace D3Digger
{

    
struct IHierElem;
typedef shared_ptr<IHierElem> IHierElemPtr;

struct IHierElem
{
    virtual ~IHierElem() {}

    DECLARE_EVENT(detach, ());
};

struct HierElemKeeper;

struct HierElemKeeper
{
    typedef set<IHierElemPtr> ChildrenSet;

public:
    void addChild(IHierElemPtr child) 
    {
        children_.insert(child);
        holder_ << child->subscribe_detach(bind(&HierElemKeeper::removeChild, this, child));
    }

private:
    void removeChild(IHierElemPtr child)
    {
        children_.erase(child);
    }

private:
    ChildrenSet children_;
    connection_holder holder_;
};

} // namespace D3Digger