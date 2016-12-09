static  const char* clnames[] = {
  "LCGReflex/T2Cluster",
  "LCGReflex/cluster_entry",
  "LCGReflex/T2ROGeometry",
  "LCGReflex/std::pair<T2DetId,std::vector<T2Cluster> >",
  "LCGReflex/std::vector<T2Cluster>",
  "LCGReflex/std::vector<cluster_entry>",
  "LCGReflex/edm::Wrapper<std::pair<T2DetId,std::vector<T2Cluster> > >",
  "LCGReflex/std::map<T2DetId,std::vector<T2Cluster> >",
  "LCGReflex/edm::Wrapper<std::map<T2DetId,std::vector<T2Cluster> > >",
  "LCGReflex/edm::Wrapper<std::vector<std::map<T2DetId,std::vector<T2Cluster> > > >",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
