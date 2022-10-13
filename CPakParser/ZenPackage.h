#pragma once

#include "Package.h"
#include "ZenData.h"
#include "GlobalContext.h"
#include "ExportReader.h"

struct FExportObject
{
	UObjectPtr Object;
	UObjectPtr TemplateObject;
};

struct FZenPackageData
{
	TSharedPtr<FExportReader> Reader;
	FZenPackageHeaderData Header;
	std::vector<FExportObject> Exports;

	__forceinline bool HasFlags(uint32_t Flags)
	{
		return Header.HasFlags(Flags);
	}
};

class UZenPackage : public UPackage, public std::enable_shared_from_this<UZenPackage>
{
	template <typename T = UObject>
	UObjectPtr IndexToObject(FZenPackageHeaderData& Header, std::vector<FExportObject>& Exports, FPackageObjectIndex Index);

public:

	UZenPackage(FZenPackageHeaderData& InHeader, TSharedPtr<GContext> InContext)
	{
		Name = InHeader.PackageName;
		Context = InContext;
	}

	void ProcessExports(FZenPackageData& PackageData);
	void CreateExport(FZenPackageHeaderData& Header, std::vector<FExportObject>& Exports, int32_t LocalExportIndex);
	void SerializeExport(FZenPackageData& PackageData, int32_t LocalExportIndex);
};