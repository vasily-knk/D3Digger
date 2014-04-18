#pragma once

namespace D3Digger
{

struct HierElem;
typedef shared_ptr<HierElem> HierElemPtr;
typedef weak_ptr<HierElem> HierElemWPtr;

struct HierElem
    : enable_shared_from_this<HierElem>
{
    typedef set<HierElemPtr> ChildrenSet;
    friend struct HierElemAux;

    HierElem(HierElemWPtr parent)
        : parent_(parent)
    {

    }

protected:
    void addChild(HierElemPtr child)
    {
        children_.insert(child);
    }

    void removeChild(HierElemPtr child)
    {
        children_.erase(child);
    }

    void detach()
    {
        if (HierElemPtr parent = parent_.lock())
        {
            parent->removeChild(shared_from_this());
        }
    }

public:
    HierElemWPtr parent() const
    {
        return parent_;
    }

    ChildrenSet const &children() const
    {
        return children_;
    }

private:
    HierElemWPtr parent_;
    ChildrenSet children_;
};

struct HierElemAux
    : HierElem
{
    HierElemAux(HierElemWPtr parent)
        : HierElem(parent)
    {

    }

    void setParent(HierElemWPtr parent)
    {
        parent_ = parent;
    }
};

} // namespace D3Digger