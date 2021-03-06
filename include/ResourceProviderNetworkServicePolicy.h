#ifndef RESOURCEPROVIDERNETWORKSERVICEPOLICY_H
#define RESOURCEPROVIDERNETWORKSERVICEPOLICY_H

#include <vector>
#include "InternetResource.h"

class QJsonObject;
class ResourceProviderNetworkServicePolicy {
private:
  QString m_url_management;
  std::vector<InternetResource> m_lstResources;
  void updateListOfResourcesNetworkImpl();
  void updateListOfResourcesLocalImpl();
  QString downloadImgToTemp(const QString &imgUrl, bool &success);

  //static methods
  static bool parseReply(const QJsonObject &obj, InternetResource &ir);
  static bool parseLocal(const QJsonObject &obj, InternetResource &ir);
  static ResourceProviderNetworkServicePolicy& Instance(void);

  static size_t updateResWriteFunc(void *ptr,
                              size_t size,
                              size_t nmemb,
                              std::string* data);

  static size_t downloadImgWriteFunc(void *ptr,
                                     size_t size,
                                     size_t nmemb,
                                     void *stream);

  ResourceProviderNetworkServicePolicy(ResourceProviderNetworkServicePolicy const &) = delete;
  void operator =(ResourceProviderNetworkServicePolicy const &) = delete;

public:
  ResourceProviderNetworkServicePolicy();

protected:
  ~ResourceProviderNetworkServicePolicy(); //because we don't want vptr here.
  static std::vector<InternetResource> updateListOfResources();
};

#endif // RESOURCEPROVIDERNETWORKSERVICEPOLICY_H
