#pragma once
#include "stdafx.h"
#include <string>
#include "DisplayList.h"
#include "Skeleton.h"
#include "DataConverters.h"

struct aiScene;

class Model : public DisplayList::Node
{
	Skeleton* mSkeleton;

	struct Mesh
	{
		IDirect3DVertexBuffer9* m_pVertexBuffer;
		IDirect3DVertexDeclaration9* m_pVertexDeclaration;
		IDirect3DIndexBuffer9* m_pIndexBuffer;

		IDirect3DVertexShader9* m_pVertexShader;
		IDirect3DPixelShader9* m_pPixelShader;
	};

	std::vector<Mesh> m_Meshes;

	int CreateDataConverters( aiMesh* mesh, std::vector<DataConverter*>& result );

public:
	Model( const std::string& fileName );
	~Model(void);

	bool load( RenderContext* context );

	void Render( RenderContext* context );
 
	bool mIsLoaded;
	std::string mFileName;

	aiScene* mScene;
};
