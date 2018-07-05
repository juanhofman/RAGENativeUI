#include "Memory.h"
#include <iostream>

#define EXPORT __declspec(dllexport)

extern "C"
{
	EXPORT void Init()
	{
		Memory::Init();
	}

	EXPORT void* Allocate(int64 size)
	{
		return Memory::ms_pAllocator->Allocate(size);
	}

	EXPORT void Free(void* ptr)
	{
		Memory::ms_pAllocator->Free(ptr);
	}

	EXPORT bool DoesTextureDictionaryExist(const char* name)
	{
		return Memory::DoesTextureDictionaryExist(name);
	}

	EXPORT bool DoesCustomTextureExist(const char* name)
	{
		return Memory::DoesCustomTextureExist(name);
	}

	EXPORT uint32 CreateCustomTexture(const char* name, uint32 width, uint32 height, uint8* pixelData, bool updatable)
	{
		return Memory::CreateCustomTexture(name, width, height, pixelData, updatable);
	}

	EXPORT uint32 GetNumberOfTexturesFromDictionary(const char* name)
	{
		return Memory::GetNumberOfTexturesFromDictionary(name);
	}

	EXPORT void GetTexturesFromDictionary(const char* name, Memory::TextureDesc* outTextureDescs)
	{
		Memory::GetTexturesFromDictionary(name, outTextureDescs);
	}
}

#undef EXPORT
