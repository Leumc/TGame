#pragma once
#include <unordered_map>
#include <memory>

enum class ResourceType{
    BULLET,PLAYER,ENEMY
};

class ResourceManager;

class Resource{
    private:
    int m_identifier;
    ResourceType m_type;
    public:
    virtual ~Resource()=default;
    Resource(ResourceManager* manager,ResourceType type);
    int getIdentifier();
    ResourceType getType();
};

class AddResourceInterface{
    public:
    virtual void AddResource(std::shared_ptr<Resource> object)=0;
};

class ResourceManager:public AddResourceInterface{
    private:
    static int AvailableID;
    std::unordered_map<int,std::shared_ptr<Resource>> m_resource_pool;
    public:
    ResourceManager();
    static int allocateID();
    void AddResource(std::shared_ptr<Resource> object);
    std::shared_ptr<Resource> getResourceByID(int identifier);
};
