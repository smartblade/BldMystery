#pragma once

#include <map>
#include <string>
#include <vector>
#include "rapidjson.h"

class DllExportSymbol
{
public:
	DllExportSymbol();
	DllExportSymbol(const std::string& name);
	DllExportSymbol(
		const std::string& name,
		const rapidjson::Value& symbolObj);
	void SetWatched(bool isWatched);
	bool IsWatched();
	rapidjson::Value Dump(rapidjson::Document& document) const;
private:
	std::string name;
	bool isWatched = true;
};

class DllInfo
{
public:
	DllInfo();
	DllInfo(const rapidjson::Value &dllInfoObj);
	void AddSymbols(std::vector<std::string> symbols);
	DllExportSymbol& GetSymbol(const std::string& symbolName);
	rapidjson::Value Dump(rapidjson::Document& document) const;

private:
	std::map<std::string, DllExportSymbol> symbols;
};

class DllMetadata
{
public:
	DllMetadata(std::string fileName);
	void AddDllInfo(std::string name, std::vector<std::string> symbols);
	DllInfo& GetDll(const std::string& dllName);

private:
	void Dump() const;

	std::map<std::string, DllInfo> dlls;
	std::string fileName;
};
