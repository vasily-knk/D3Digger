#include "stdafx.h"
#include "d3d9/Methods.h"
#include "common/signals.h"

struct IFoo
{
	DECLARE_SIGNAL(Fucked, (int));
};

struct Foo
	: IFoo
{
	DEFINE_SIGNAL(Fucked, (int));
};

namespace D3D9
{

	void onFucked(int i)
	{
		std::cout << "Fucked: " << i << std::endl;
	}


	void Fuck()
	{
		shared_ptr<IFoo> foo = make_shared<Foo>();
		foo->subscribeFucked(onFucked);

		MethodId id = makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateIndexBuffer);
	}

}