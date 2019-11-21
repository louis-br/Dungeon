#pragma once
#include"stdafx.h"

template<class Resource, class Identifier>
class ResourceHolder
{
private:
  map<Identifier, Resource*> resourceMap;
public:
  void loadResource(Identifier id, string filename){
    Resource* resource(new Resource());
    resource->loadFromFile(filename);

    resourceMap.insert(make_pair(id, move(resource)));
  }
  Resource& getResource(Identifier id){
    auto it = resourceMap.find(id);
    return *it->second;
  }

  ResourceHolder(){}
  ~ResourceHolder(){
    resourceMap.clear();
  }
};
