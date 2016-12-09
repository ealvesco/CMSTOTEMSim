static  const char* clnames[] = {
  "LCGReflex/T1Cluster",
  "LCGReflex/TotemDigiCollection<T1DetId,T1Cluster>",
  "LCGReflex/std::pair<T1DetId,std::vector<T1Cluster> >",
  "LCGReflex/std::vector<T1Cluster>",
  "LCGReflex/std::map<T1DetId,std::vector<T1Cluster> >",
  "LCGReflex/edm::Wrapper<std::pair<T1DetId,std::vector<T1Cluster> > >",
  "LCGReflex/edm::Wrapper<TotemDigiCollection<T1DetId,T1Cluster> >",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
