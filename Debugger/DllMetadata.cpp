#include "DllMetadata.h"
#include "rapidjson.h"

using namespace rapidjson;

DllExportSymbol::DllExportSymbol()
{
}

DllExportSymbol::DllExportSymbol(const std::string &name) : name(name)
{
}

DllExportSymbol::DllExportSymbol(
    const std::string& name,
    const Value& symbolObj)
    : name(name)
{
    this->isWatched = symbolObj["isWatched"].GetBool();
}

void DllExportSymbol::SetWatched(bool isWatched)
{
    this->isWatched = isWatched;
}

bool DllExportSymbol::IsWatched()
{
    return isWatched;
}

Value DllExportSymbol::Dump(Document& document) const
{
    Value symbolObj(Type::kObjectType);
    symbolObj.AddMember(
            Value("isWatched", document.GetAllocator()),
            Value(isWatched),
            document.GetAllocator());
    return symbolObj;
}

DllInfo::DllInfo()
{
}

DllInfo::DllInfo(const Value &dllInfoObj)
{
    auto& symbolsObj = dllInfoObj["symbols"];
    for (auto& m : symbolsObj.GetObject())
    {
        this->symbols[m.name.GetString()] = DllExportSymbol(
            m.name.GetString(),
            m.value);
    }
}

void DllInfo::AddSymbols(std::vector<std::string> symbols)
{
    for (auto symbolName : symbols)
    {
        if (this->symbols.find(symbolName) == this->symbols.end())
        {
            this->symbols[symbolName] = DllExportSymbol(symbolName);
        }
    }
}

DllExportSymbol& DllInfo::GetSymbol(const std::string& symbolName)
{
    return this->symbols[symbolName];
}

Value DllInfo::Dump(Document &document) const
{
    Value dllInfoObj(Type::kObjectType);
    Value symbolsObj(Type::kObjectType);
    for (auto& symbol : symbols)
    {
        auto& name = symbol.first;
        auto& symbolInfo = symbol.second;
        Value symbolObj = symbolInfo.Dump(document);
        symbolsObj.AddMember(
            Value(name.c_str(), document.GetAllocator()),
            symbolObj,
            document.GetAllocator());
    }
    dllInfoObj.AddMember("symbols", symbolsObj, document.GetAllocator());
    return dllInfoObj;
}

DllMetadata::DllMetadata(std::string fileName) : fileName(fileName)
{
    FILE* fp;
    auto err = fopen_s(&fp, fileName.c_str(), "r");
    if (err)
    {
        printf("Failed to read %s\n", fileName.c_str());
        return;
    }
    char readBuffer[1024];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    Document document;
    document.ParseStream(is);
    fclose(fp);
    auto &dllsObj = document["dlls"];
    for (auto& m : dllsObj.GetObject())
    {
        dlls[m.name.GetString()] = DllInfo(m.value);
    }
}

void DllMetadata::AddDllInfo(std::string name, std::vector<std::string> symbols)
{
    if (this->dlls.find(name) == this->dlls.end())
    {
        this->dlls[name] = DllInfo();
    }
    this->dlls[name].AddSymbols(symbols);
    Dump();
}

DllInfo& DllMetadata::GetDll(const std::string& dllName)
{
    return this->dlls[dllName];
}

void DllMetadata::Dump() const
{
    Document document(Type::kObjectType);
    Value dllsObj(Type::kObjectType);
    for (auto& dll : dlls)
    {
        auto& dllName = dll.first;
        auto& dllInfo = dll.second;
        auto dllInfoObj = dllInfo.Dump(document);
        dllsObj.AddMember(
            Value(dllName.c_str(), document.GetAllocator()),
            dllInfoObj,
            document.GetAllocator());
    }
    document.AddMember("dlls", dllsObj, document.GetAllocator());
    FILE* fp;
    auto err = fopen_s(&fp, fileName.c_str(), "w");
    if (err)
    {
        char errorMsg[256];
        strerror_s(errorMsg, err);
        printf("Failed to open %s: %s\n", fileName.c_str(), errorMsg);
        return;
    }
    char writeBuffer[1024];
    FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));
    PrettyWriter<FileWriteStream> writer(os);
    document.Accept(writer);
    fclose(fp);
}
