#pragma once

#include "Loader.h"
#include "GameFileManager.h"
#include "UObject.h"

class FLoader;

class UPackage : public UObject
{
	FGameFilePath Path;
	TSharedPtr<FLoader> Linker;

protected:
	
	UPackage()
	{
	}

	TSharedPtr<class GContext> Context;

public:

	friend class FLoader;

	UPackage(FGameFilePath PackagePath) : Path(PackagePath)
	{
	}

	__forceinline std::string GetName()
	{
		return Name;
	}

	__forceinline FGameFilePath GetPath()
	{
		return Path;
	}

	__forceinline bool IsValid()
	{
		return Path.IsValid();
	}

	__forceinline bool HasLoader()
	{
		return !!Linker;
	}

	__forceinline TSharedPtr<FLoader> GetLoader()
	{
		return Linker;
	}
};