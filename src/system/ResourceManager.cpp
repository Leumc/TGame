#include "ResourceManager.hpp"

Resource::Resource(ResourceManager* manager,ResourceType type){
    m_identifier=manager->allocateID();
    m_type=type;
}

int Resource::getIdentifier(){
    return m_identifier;
}

ResourceType Resource::getType(){
    return m_type;
}

int ResourceManager::AvailableID=0;

ResourceManager::ResourceManager(){}

int ResourceManager::allocateID(){
    return ++AvailableID;
}

void ResourceManager::AddResource(std::shared_ptr<Resource> object){
    m_resource_pool.insert(std::make_pair(object->getIdentifier(),object));
}

std::shared_ptr<Resource> ResourceManager::getResourceByID(int identifier){
    std::unordered_map<int,std::shared_ptr<Resource>>::iterator it=m_resource_pool.find(identifier);
    if(it==m_resource_pool.end()){
        return nullptr;
    }
    else{
        return it->second;
    }
}