MIDL_INTERFACE("9B7E4C00-342C-4106-A19F-4F2704F689F0")
    ID3D10DeviceChild : public IUnknown
    {
    public:
        virtual void STDMETHODCALLTYPE GetDevice( 
            __out  ID3D10Device **ppDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPrivateData( 
            __in  REFGUID guid,
            __inout  UINT *pDataSize,
            __out_bcount_opt(*pDataSize)  void *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPrivateData( 
            __in  REFGUID guid,
            __in  UINT DataSize,
            __in_bcount_opt(DataSize)  const void *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface( 
            __in  REFGUID guid,
            __in_opt  const IUnknown *pData) = 0;
        
    };
MIDL_INTERFACE("2B4B1CC8-A4AD-41f8-8322-CA86FC3EC675")
    ID3D10DepthStencilState : public ID3D10DeviceChild
    {
    public:
        virtual void STDMETHODCALLTYPE GetDesc( 
            __out  D3D10_DEPTH_STENCIL_DESC *pDesc) = 0;
        
    };
MIDL_INTERFACE("EDAD8D19-8A35-4d6d-8566-2EA276CDE161")
    ID3D10BlendState : public ID3D10DeviceChild
    {
    public:
        virtual void STDMETHODCALLTYPE GetDesc( 
            __out  D3D10_BLEND_DESC *pDesc) = 0;
        
    };
MIDL_INTERFACE("A2A07292-89AF-4345-BE2E-C53D9FBB6E9F")
    ID3D10RasterizerState : public ID3D10DeviceChild
    {
    public:
        virtual void STDMETHODCALLTYPE GetDesc( 
            __out  D3D10_RASTERIZER_DESC *pDesc) = 0;
        
    };
MIDL_INTERFACE("9B7E4C01-342C-4106-A19F-4F2704F689F0")
    ID3D10Resource : public ID3D10DeviceChild
    {
    public:
        virtual void STDMETHODCALLTYPE GetType( 
            __out  D3D10_RESOURCE_DIMENSION *rType) = 0;
        
        virtual void STDMETHODCALLTYPE SetEvictionPriority( 
            __in  UINT EvictionPriority) = 0;
        
        virtual UINT STDMETHODCALLTYPE GetEvictionPriority( void) = 0;
        
    };
MIDL_INTERFACE("9B7E4C02-342C-4106-A19F-4F2704F689F0")
    ID3D10Buffer : public ID3D10Resource
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Map( 
            __in  D3D10_MAP MapType,
            __in  UINT MapFlags,
            __out  void **ppData) = 0;
        
        virtual void STDMETHODCALLTYPE Unmap( void) = 0;
        
        virtual void STDMETHODCALLTYPE GetDesc( 
            __out  D3D10_BUFFER_DESC *pDesc) = 0;
        
    };
MIDL_INTERFACE("9B7E4C03-342C-4106-A19F-4F2704F689F0")
    ID3D10Texture1D : public ID3D10Resource
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Map( 
            __in  UINT Subresource,
            __in  D3D10_MAP MapType,
            __in  UINT MapFlags,
            __out  void **ppData) = 0;
        
        virtual void STDMETHODCALLTYPE Unmap( 
            __in  UINT Subresource) = 0;
        
        virtual void STDMETHODCALLTYPE GetDesc( 
            __out  D3D10_TEXTURE1D_DESC *pDesc) = 0;
        
    };
MIDL_INTERFACE("9B7E4C04-342C-4106-A19F-4F2704F689F0")
    ID3D10Texture2D : public ID3D10Resource
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Map( 
            __in  UINT Subresource,
            __in  D3D10_MAP MapType,
            __in  UINT MapFlags,
            __out  D3D10_MAPPED_TEXTURE2D *pMappedTex2D) = 0;
        
        virtual void STDMETHODCALLTYPE Unmap( 
            __in  UINT Subresource) = 0;
        
        virtual void STDMETHODCALLTYPE GetDesc( 
            __out  D3D10_TEXTURE2D_DESC *pDesc) = 0;
        
    };
MIDL_INTERFACE("9B7E4C05-342C-4106-A19F-4F2704F689F0")
    ID3D10Texture3D : public ID3D10Resource
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Map( 
            __in  UINT Subresource,
            __in  D3D10_MAP MapType,
            __in  UINT MapFlags,
            __out  D3D10_MAPPED_TEXTURE3D *pMappedTex3D) = 0;
        
        virtual void STDMETHODCALLTYPE Unmap( 
            __in  UINT Subresource) = 0;
        
        virtual void STDMETHODCALLTYPE GetDesc( 
            __out  D3D10_TEXTURE3D_DESC *pDesc) = 0;
        
    };
MIDL_INTERFACE("C902B03F-60A7-49BA-9936-2A3AB37A7E33")
    ID3D10View : public ID3D10DeviceChild
    {
    public:
        virtual void STDMETHODCALLTYPE GetResource( 
            __out  ID3D10Resource **ppResource) = 0;
        
    };
MIDL_INTERFACE("9B7E4C07-342C-4106-A19F-4F2704F689F0")
    ID3D10ShaderResourceView : public ID3D10View
    {
    public:
        virtual void STDMETHODCALLTYPE GetDesc( 
            __out  D3D10_SHADER_RESOURCE_VIEW_DESC *pDesc) = 0;
        
    };
MIDL_INTERFACE("9B7E4C08-342C-4106-A19F-4F2704F689F0")
    ID3D10RenderTargetView : public ID3D10View
    {
    public:
        virtual void STDMETHODCALLTYPE GetDesc( 
            __out  D3D10_RENDER_TARGET_VIEW_DESC *pDesc) = 0;
        
    };
MIDL_INTERFACE("9B7E4C09-342C-4106-A19F-4F2704F689F0")
    ID3D10DepthStencilView : public ID3D10View
    {
    public:
        virtual void STDMETHODCALLTYPE GetDesc( 
            __out  D3D10_DEPTH_STENCIL_VIEW_DESC *pDesc) = 0;
        
    };
MIDL_INTERFACE("9B7E4C0A-342C-4106-A19F-4F2704F689F0")
    ID3D10VertexShader : public ID3D10DeviceChild
    {
    public:
    };
MIDL_INTERFACE("6316BE88-54CD-4040-AB44-20461BC81F68")
    ID3D10GeometryShader : public ID3D10DeviceChild
    {
    public:
    };
MIDL_INTERFACE("4968B601-9D00-4cde-8346-8E7F675819B6")
    ID3D10PixelShader : public ID3D10DeviceChild
    {
    public:
    };
MIDL_INTERFACE("9B7E4C0B-342C-4106-A19F-4F2704F689F0")
    ID3D10InputLayout : public ID3D10DeviceChild
    {
    public:
    };
MIDL_INTERFACE("9B7E4C0C-342C-4106-A19F-4F2704F689F0")
    ID3D10SamplerState : public ID3D10DeviceChild
    {
    public:
        virtual void STDMETHODCALLTYPE GetDesc( 
            __out  D3D10_SAMPLER_DESC *pDesc) = 0;
        
    };
MIDL_INTERFACE("9B7E4C0D-342C-4106-A19F-4F2704F689F0")
    ID3D10Asynchronous : public ID3D10DeviceChild
    {
    public:
        virtual void STDMETHODCALLTYPE Begin( void) = 0;
        
        virtual void STDMETHODCALLTYPE End( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetData( 
            __out_bcount_opt(DataSize)  void *pData,
            __in  UINT DataSize,
            __in  UINT GetDataFlags) = 0;
        
        virtual UINT STDMETHODCALLTYPE GetDataSize( void) = 0;
        
    };
MIDL_INTERFACE("9B7E4C0E-342C-4106-A19F-4F2704F689F0")
    ID3D10Query : public ID3D10Asynchronous
    {
    public:
        virtual void STDMETHODCALLTYPE GetDesc( 
            __out  D3D10_QUERY_DESC *pDesc) = 0;
        
    };
MIDL_INTERFACE("9B7E4C10-342C-4106-A19F-4F2704F689F0")
    ID3D10Predicate : public ID3D10Query
    {
    public:
    };
MIDL_INTERFACE("9B7E4C11-342C-4106-A19F-4F2704F689F0")
    ID3D10Counter : public ID3D10Asynchronous
    {
    public:
        virtual void STDMETHODCALLTYPE GetDesc( 
            __out  D3D10_COUNTER_DESC *pDesc) = 0;
        
    };
MIDL_INTERFACE("9B7E4C0F-342C-4106-A19F-4F2704F689F0")
    ID3D10Device : public IUnknown
    {
    public:
        virtual void STDMETHODCALLTYPE VSSetConstantBuffers( 
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot )  UINT NumBuffers,
            __in_ecount(NumBuffers)  ID3D10Buffer *const *ppConstantBuffers) = 0;
        
        virtual void STDMETHODCALLTYPE PSSetShaderResources( 
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot )  UINT NumViews,
            __in_ecount(NumViews)  ID3D10ShaderResourceView *const *ppShaderResourceViews) = 0;
        
        virtual void STDMETHODCALLTYPE PSSetShader( 
            __in_opt  ID3D10PixelShader *pPixelShader) = 0;
        
        virtual void STDMETHODCALLTYPE PSSetSamplers( 
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot )  UINT NumSamplers,
            __in_ecount(NumSamplers)  ID3D10SamplerState *const *ppSamplers) = 0;
        
        virtual void STDMETHODCALLTYPE VSSetShader( 
            __in_opt  ID3D10VertexShader *pVertexShader) = 0;
        
        virtual void STDMETHODCALLTYPE DrawIndexed( 
            __in  UINT IndexCount,
            __in  UINT StartIndexLocation,
            __in  INT BaseVertexLocation) = 0;
        
        virtual void STDMETHODCALLTYPE Draw( 
            __in  UINT VertexCount,
            __in  UINT StartVertexLocation) = 0;
        
        virtual void STDMETHODCALLTYPE PSSetConstantBuffers( 
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot )  UINT NumBuffers,
            __in_ecount(NumBuffers)  ID3D10Buffer *const *ppConstantBuffers) = 0;
        
        virtual void STDMETHODCALLTYPE IASetInputLayout( 
            __in_opt  ID3D10InputLayout *pInputLayout) = 0;
        
        virtual void STDMETHODCALLTYPE IASetVertexBuffers( 
            __in_range( 0, D3D10_1_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_1_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - StartSlot )  UINT NumBuffers,
            __in_ecount(NumBuffers)  ID3D10Buffer *const *ppVertexBuffers,
            __in_ecount(NumBuffers)  const UINT *pStrides,
            __in_ecount(NumBuffers)  const UINT *pOffsets) = 0;
        
        virtual void STDMETHODCALLTYPE IASetIndexBuffer( 
            __in_opt  ID3D10Buffer *pIndexBuffer,
            __in  DXGI_FORMAT Format,
            __in  UINT Offset) = 0;
        
        virtual void STDMETHODCALLTYPE DrawIndexedInstanced( 
            __in  UINT IndexCountPerInstance,
            __in  UINT InstanceCount,
            __in  UINT StartIndexLocation,
            __in  INT BaseVertexLocation,
            __in  UINT StartInstanceLocation) = 0;
        
        virtual void STDMETHODCALLTYPE DrawInstanced( 
            __in  UINT VertexCountPerInstance,
            __in  UINT InstanceCount,
            __in  UINT StartVertexLocation,
            __in  UINT StartInstanceLocation) = 0;
        
        virtual void STDMETHODCALLTYPE GSSetConstantBuffers( 
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot )  UINT NumBuffers,
            __in_ecount(NumBuffers)  ID3D10Buffer *const *ppConstantBuffers) = 0;
        
        virtual void STDMETHODCALLTYPE GSSetShader( 
            __in_opt  ID3D10GeometryShader *pShader) = 0;
        
        virtual void STDMETHODCALLTYPE IASetPrimitiveTopology( 
            __in  D3D10_PRIMITIVE_TOPOLOGY Topology) = 0;
        
        virtual void STDMETHODCALLTYPE VSSetShaderResources( 
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot )  UINT NumViews,
            __in_ecount(NumViews)  ID3D10ShaderResourceView *const *ppShaderResourceViews) = 0;
        
        virtual void STDMETHODCALLTYPE VSSetSamplers( 
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot )  UINT NumSamplers,
            __in_ecount(NumSamplers)  ID3D10SamplerState *const *ppSamplers) = 0;
        
        virtual void STDMETHODCALLTYPE SetPredication( 
            __in_opt  ID3D10Predicate *pPredicate,
            __in  BOOL PredicateValue) = 0;
        
        virtual void STDMETHODCALLTYPE GSSetShaderResources( 
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot )  UINT NumViews,
            __in_ecount(NumViews)  ID3D10ShaderResourceView *const *ppShaderResourceViews) = 0;
        
        virtual void STDMETHODCALLTYPE GSSetSamplers( 
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot )  UINT NumSamplers,
            __in_ecount(NumSamplers)  ID3D10SamplerState *const *ppSamplers) = 0;
        
        virtual void STDMETHODCALLTYPE OMSetRenderTargets( 
            __in_range( 0, D3D10_SIMULTANEOUS_RENDER_TARGET_COUNT )  UINT NumViews,
            __in_ecount_opt(NumViews)  ID3D10RenderTargetView *const *ppRenderTargetViews,
            __in_opt  ID3D10DepthStencilView *pDepthStencilView) = 0;
        
        virtual void STDMETHODCALLTYPE OMSetBlendState( 
            __in_opt  ID3D10BlendState *pBlendState,
            __in  const FLOAT BlendFactor[ 4 ],
            __in  UINT SampleMask) = 0;
        
        virtual void STDMETHODCALLTYPE OMSetDepthStencilState( 
            __in_opt  ID3D10DepthStencilState *pDepthStencilState,
            __in  UINT StencilRef) = 0;
        
        virtual void STDMETHODCALLTYPE SOSetTargets( 
            __in_range( 0, D3D10_SO_BUFFER_SLOT_COUNT)  UINT NumBuffers,
            __in_ecount_opt(NumBuffers)  ID3D10Buffer *const *ppSOTargets,
            __in_ecount_opt(NumBuffers)  const UINT *pOffsets) = 0;
        
        virtual void STDMETHODCALLTYPE DrawAuto( void) = 0;
        
        virtual void STDMETHODCALLTYPE RSSetState( 
            __in_opt  ID3D10RasterizerState *pRasterizerState) = 0;
        
        virtual void STDMETHODCALLTYPE RSSetViewports( 
            __in_range(0, D3D10_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE)  UINT NumViewports,
            __in_ecount_opt(NumViewports)  const D3D10_VIEWPORT *pViewports) = 0;
        
        virtual void STDMETHODCALLTYPE RSSetScissorRects( 
            __in_range(0, D3D10_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE)  UINT NumRects,
            __in_ecount_opt(NumRects)  const D3D10_RECT *pRects) = 0;
        
        virtual void STDMETHODCALLTYPE CopySubresourceRegion( 
            __in  ID3D10Resource *pDstResource,
            __in  UINT DstSubresource,
            __in  UINT DstX,
            __in  UINT DstY,
            __in  UINT DstZ,
            __in  ID3D10Resource *pSrcResource,
            __in  UINT SrcSubresource,
            __in_opt  const D3D10_BOX *pSrcBox) = 0;
        
        virtual void STDMETHODCALLTYPE CopyResource( 
            __in  ID3D10Resource *pDstResource,
            __in  ID3D10Resource *pSrcResource) = 0;
        
        virtual void STDMETHODCALLTYPE UpdateSubresource( 
            __in  ID3D10Resource *pDstResource,
            __in  UINT DstSubresource,
            __in_opt  const D3D10_BOX *pDstBox,
            __in  const void *pSrcData,
            __in  UINT SrcRowPitch,
            __in  UINT SrcDepthPitch) = 0;
        
        virtual void STDMETHODCALLTYPE ClearRenderTargetView( 
            __in  ID3D10RenderTargetView *pRenderTargetView,
            __in  const FLOAT ColorRGBA[ 4 ]) = 0;
        
        virtual void STDMETHODCALLTYPE ClearDepthStencilView( 
            __in  ID3D10DepthStencilView *pDepthStencilView,
            __in  UINT ClearFlags,
            __in  FLOAT Depth,
            __in  UINT8 Stencil) = 0;
        
        virtual void STDMETHODCALLTYPE GenerateMips( 
            __in  ID3D10ShaderResourceView *pShaderResourceView) = 0;
        
        virtual void STDMETHODCALLTYPE ResolveSubresource( 
            __in  ID3D10Resource *pDstResource,
            __in  UINT DstSubresource,
            __in  ID3D10Resource *pSrcResource,
            __in  UINT SrcSubresource,
            __in  DXGI_FORMAT Format) = 0;
        
        virtual void STDMETHODCALLTYPE VSGetConstantBuffers( 
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot )  UINT NumBuffers,
            __out_ecount(NumBuffers)  ID3D10Buffer **ppConstantBuffers) = 0;
        
        virtual void STDMETHODCALLTYPE PSGetShaderResources( 
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot )  UINT NumViews,
            __out_ecount(NumViews)  ID3D10ShaderResourceView **ppShaderResourceViews) = 0;
        
        virtual void STDMETHODCALLTYPE PSGetShader( 
            __out  ID3D10PixelShader **ppPixelShader) = 0;
        
        virtual void STDMETHODCALLTYPE PSGetSamplers( 
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot )  UINT NumSamplers,
            __out_ecount(NumSamplers)  ID3D10SamplerState **ppSamplers) = 0;
        
        virtual void STDMETHODCALLTYPE VSGetShader( 
            __out  ID3D10VertexShader **ppVertexShader) = 0;
        
        virtual void STDMETHODCALLTYPE PSGetConstantBuffers( 
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot )  UINT NumBuffers,
            __out_ecount(NumBuffers)  ID3D10Buffer **ppConstantBuffers) = 0;
        
        virtual void STDMETHODCALLTYPE IAGetInputLayout( 
            __out  ID3D10InputLayout **ppInputLayout) = 0;
        
        virtual void STDMETHODCALLTYPE IAGetVertexBuffers( 
            __in_range( 0, D3D10_1_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_1_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - StartSlot )  UINT NumBuffers,
            __out_ecount_opt(NumBuffers)  ID3D10Buffer **ppVertexBuffers,
            __out_ecount_opt(NumBuffers)  UINT *pStrides,
            __out_ecount_opt(NumBuffers)  UINT *pOffsets) = 0;
        
        virtual void STDMETHODCALLTYPE IAGetIndexBuffer( 
            __out_opt  ID3D10Buffer **pIndexBuffer,
            __out_opt  DXGI_FORMAT *Format,
            __out_opt  UINT *Offset) = 0;
        
        virtual void STDMETHODCALLTYPE GSGetConstantBuffers( 
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot )  UINT NumBuffers,
            __out_ecount(NumBuffers)  ID3D10Buffer **ppConstantBuffers) = 0;
        
        virtual void STDMETHODCALLTYPE GSGetShader( 
            __out  ID3D10GeometryShader **ppGeometryShader) = 0;
        
        virtual void STDMETHODCALLTYPE IAGetPrimitiveTopology( 
            __out  D3D10_PRIMITIVE_TOPOLOGY *pTopology) = 0;
        
        virtual void STDMETHODCALLTYPE VSGetShaderResources( 
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot )  UINT NumViews,
            __out_ecount(NumViews)  ID3D10ShaderResourceView **ppShaderResourceViews) = 0;
        
        virtual void STDMETHODCALLTYPE VSGetSamplers( 
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot )  UINT NumSamplers,
            __out_ecount(NumSamplers)  ID3D10SamplerState **ppSamplers) = 0;
        
        virtual void STDMETHODCALLTYPE GetPredication( 
            __out_opt  ID3D10Predicate **ppPredicate,
            __out_opt  BOOL *pPredicateValue) = 0;
        
        virtual void STDMETHODCALLTYPE GSGetShaderResources( 
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot )  UINT NumViews,
            __out_ecount(NumViews)  ID3D10ShaderResourceView **ppShaderResourceViews) = 0;
        
        virtual void STDMETHODCALLTYPE GSGetSamplers( 
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - 1 )  UINT StartSlot,
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot )  UINT NumSamplers,
            __out_ecount(NumSamplers)  ID3D10SamplerState **ppSamplers) = 0;
        
        virtual void STDMETHODCALLTYPE OMGetRenderTargets( 
            __in_range( 0, D3D10_SIMULTANEOUS_RENDER_TARGET_COUNT )  UINT NumViews,
            __out_ecount_opt(NumViews)  ID3D10RenderTargetView **ppRenderTargetViews,
            __out_opt  ID3D10DepthStencilView **ppDepthStencilView) = 0;
        
        virtual void STDMETHODCALLTYPE OMGetBlendState( 
            __out_opt  ID3D10BlendState **ppBlendState,
            __out_opt  FLOAT BlendFactor[ 4 ],
            __out_opt  UINT *pSampleMask) = 0;
        
        virtual void STDMETHODCALLTYPE OMGetDepthStencilState( 
            __out_opt  ID3D10DepthStencilState **ppDepthStencilState,
            __out_opt  UINT *pStencilRef) = 0;
        
        virtual void STDMETHODCALLTYPE SOGetTargets( 
            __in_range( 0, D3D10_SO_BUFFER_SLOT_COUNT )  UINT NumBuffers,
            __out_ecount_opt(NumBuffers)  ID3D10Buffer **ppSOTargets,
            __out_ecount_opt(NumBuffers)  UINT *pOffsets) = 0;
        
        virtual void STDMETHODCALLTYPE RSGetState( 
            __out  ID3D10RasterizerState **ppRasterizerState) = 0;
        
        virtual void STDMETHODCALLTYPE RSGetViewports( 
            __inout /*_range(0, D3D10_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE )*/   UINT *NumViewports,
            __out_ecount_opt(*NumViewports)  D3D10_VIEWPORT *pViewports) = 0;
        
        virtual void STDMETHODCALLTYPE RSGetScissorRects( 
            __inout /*_range(0, D3D10_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE )*/   UINT *NumRects,
            __out_ecount_opt(*NumRects)  D3D10_RECT *pRects) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceRemovedReason( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetExceptionMode( 
            UINT RaiseFlags) = 0;
        
        virtual UINT STDMETHODCALLTYPE GetExceptionMode( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPrivateData( 
            __in  REFGUID guid,
            __inout  UINT *pDataSize,
            __out_bcount_opt(*pDataSize)  void *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPrivateData( 
            __in  REFGUID guid,
            __in  UINT DataSize,
            __in_bcount_opt(DataSize)  const void *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface( 
            __in  REFGUID guid,
            __in_opt  const IUnknown *pData) = 0;
        
        virtual void STDMETHODCALLTYPE ClearState( void) = 0;
        
        virtual void STDMETHODCALLTYPE Flush( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateBuffer( 
            __in  const D3D10_BUFFER_DESC *pDesc,
            __in_opt  const D3D10_SUBRESOURCE_DATA *pInitialData,
            __out_opt  ID3D10Buffer **ppBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateTexture1D( 
            __in  const D3D10_TEXTURE1D_DESC *pDesc,
            __in_xcount_opt(pDesc->MipLevels * pDesc->ArraySize)  const D3D10_SUBRESOURCE_DATA *pInitialData,
            __out  ID3D10Texture1D **ppTexture1D) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateTexture2D( 
            __in  const D3D10_TEXTURE2D_DESC *pDesc,
            __in_xcount_opt(pDesc->MipLevels * pDesc->ArraySize)  const D3D10_SUBRESOURCE_DATA *pInitialData,
            __out  ID3D10Texture2D **ppTexture2D) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateTexture3D( 
            __in  const D3D10_TEXTURE3D_DESC *pDesc,
            __in_xcount_opt(pDesc->MipLevels)  const D3D10_SUBRESOURCE_DATA *pInitialData,
            __out  ID3D10Texture3D **ppTexture3D) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateShaderResourceView( 
            __in  ID3D10Resource *pResource,
            __in_opt  const D3D10_SHADER_RESOURCE_VIEW_DESC *pDesc,
            __out_opt  ID3D10ShaderResourceView **ppSRView) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateRenderTargetView( 
            __in  ID3D10Resource *pResource,
            __in_opt  const D3D10_RENDER_TARGET_VIEW_DESC *pDesc,
            __out_opt  ID3D10RenderTargetView **ppRTView) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateDepthStencilView( 
            __in  ID3D10Resource *pResource,
            __in_opt  const D3D10_DEPTH_STENCIL_VIEW_DESC *pDesc,
            __out_opt  ID3D10DepthStencilView **ppDepthStencilView) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateInputLayout( 
            __in_ecount(NumElements)  const D3D10_INPUT_ELEMENT_DESC *pInputElementDescs,
            __in_range( 0, D3D10_1_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT )  UINT NumElements,
            __in  const void *pShaderBytecodeWithInputSignature,
            __in  SIZE_T BytecodeLength,
            __out_opt  ID3D10InputLayout **ppInputLayout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateVertexShader( 
            __in  const void *pShaderBytecode,
            __in  SIZE_T BytecodeLength,
            __out_opt  ID3D10VertexShader **ppVertexShader) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateGeometryShader( 
            __in  const void *pShaderBytecode,
            __in  SIZE_T BytecodeLength,
            __out_opt  ID3D10GeometryShader **ppGeometryShader) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateGeometryShaderWithStreamOutput( 
            __in  const void *pShaderBytecode,
            __in  SIZE_T BytecodeLength,
            __in_ecount_opt(NumEntries)  const D3D10_SO_DECLARATION_ENTRY *pSODeclaration,
            __in_range( 0, D3D10_SO_SINGLE_BUFFER_COMPONENT_LIMIT )  UINT NumEntries,
            __in  UINT OutputStreamStride,
            __out_opt  ID3D10GeometryShader **ppGeometryShader) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreatePixelShader( 
            __in  const void *pShaderBytecode,
            __in  SIZE_T BytecodeLength,
            __out_opt  ID3D10PixelShader **ppPixelShader) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateBlendState( 
            __in  const D3D10_BLEND_DESC *pBlendStateDesc,
            __out_opt  ID3D10BlendState **ppBlendState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateDepthStencilState( 
            __in  const D3D10_DEPTH_STENCIL_DESC *pDepthStencilDesc,
            __out_opt  ID3D10DepthStencilState **ppDepthStencilState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateRasterizerState( 
            __in  const D3D10_RASTERIZER_DESC *pRasterizerDesc,
            __out_opt  ID3D10RasterizerState **ppRasterizerState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateSamplerState( 
            __in  const D3D10_SAMPLER_DESC *pSamplerDesc,
            __out_opt  ID3D10SamplerState **ppSamplerState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateQuery( 
            __in  const D3D10_QUERY_DESC *pQueryDesc,
            __out_opt  ID3D10Query **ppQuery) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreatePredicate( 
            __in  const D3D10_QUERY_DESC *pPredicateDesc,
            __out_opt  ID3D10Predicate **ppPredicate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateCounter( 
            __in  const D3D10_COUNTER_DESC *pCounterDesc,
            __out_opt  ID3D10Counter **ppCounter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CheckFormatSupport( 
            __in  DXGI_FORMAT Format,
            __out  UINT *pFormatSupport) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CheckMultisampleQualityLevels( 
            __in  DXGI_FORMAT Format,
            __in  UINT SampleCount,
            __out  UINT *pNumQualityLevels) = 0;
        
        virtual void STDMETHODCALLTYPE CheckCounterInfo( 
            __out  D3D10_COUNTER_INFO *pCounterInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CheckCounter( 
            __in  const D3D10_COUNTER_DESC *pDesc,
            __out  D3D10_COUNTER_TYPE *pType,
            __out  UINT *pActiveCounters,
            __out_ecount_opt(*pNameLength)  LPSTR szName,
            __inout_opt  UINT *pNameLength,
            __out_ecount_opt(*pUnitsLength)  LPSTR szUnits,
            __inout_opt  UINT *pUnitsLength,
            __out_ecount_opt(*pDescriptionLength)  LPSTR szDescription,
            __inout_opt  UINT *pDescriptionLength) = 0;
        
        virtual UINT STDMETHODCALLTYPE GetCreationFlags( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenSharedResource( 
            __in  HANDLE hResource,
            __in  REFIID ReturnedInterface,
            __out_opt  void **ppResource) = 0;
        
        virtual void STDMETHODCALLTYPE SetTextFilterSize( 
            __in  UINT Width,
            __in  UINT Height) = 0;
        
        virtual void STDMETHODCALLTYPE GetTextFilterSize( 
            __out_opt  UINT *pWidth,
            __out_opt  UINT *pHeight) = 0;
        
    };
MIDL_INTERFACE("9B7E4E00-342C-4106-A19F-4F2704F689F0")
    ID3D10Multithread : public IUnknown
    {
    public:
        virtual void STDMETHODCALLTYPE Enter( void) = 0;
        
        virtual void STDMETHODCALLTYPE Leave( void) = 0;
        
        virtual BOOL STDMETHODCALLTYPE SetMultithreadProtected( 
            __in  BOOL bMTProtect) = 0;
        
        virtual BOOL STDMETHODCALLTYPE GetMultithreadProtected( void) = 0;
        
    };
