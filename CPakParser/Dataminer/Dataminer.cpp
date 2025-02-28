#include "Dataminer.h"

#include "Core/Globals/GlobalContext.h"

import CPakParser.Compression.Oodle;
import CPakParser.Logging;
// getters and setters

static const std::string BaseMountPoint("../../../");


void Dataminer::Options::WithLogging(bool bEnableLogging)
{
	LOGGING_ENABLED = bEnableLogging;
}

void Dataminer::Options::WithOodleDecompressor(const char* OodleDllPath)
{
	Oodle::LoadDLL(OodleDllPath);
}

std::vector<TSharedPtr<IDiskFile>> Dataminer::GetMountedFiles()
{
	return MountedFiles;
}

TMap<FGuid, std::string> Dataminer::GetUnmountedPaks()
{
	return UnmountedPaks;
}

FDirectoryIndex Dataminer::Files()
{
	return Context->FilesManager.GetFiles();
}

TMap<std::string, UObjectPtr> Dataminer::GetObjectArray()
{
	return Context->ObjectArray;
}

FPakDirectory Dataminer::GetDirectory(std::string InDirectory)
{
	return Context->FilesManager.GetDirectory(InDirectory);
}

std::optional<FPakDirectory> Dataminer::TryGetDirectory(std::string InDirectory)
{
	if (!InDirectory.starts_with(BaseMountPoint))
		InDirectory = BaseMountPoint + InDirectory;

	return Context->FilesManager.TryGetDirectory(InDirectory);
}