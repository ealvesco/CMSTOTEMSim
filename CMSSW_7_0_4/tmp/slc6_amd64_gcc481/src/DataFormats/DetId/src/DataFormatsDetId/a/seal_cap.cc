static  const char* clnames[] = {
  "LCGReflex/DetId",
  "LCGReflex/edm::EDCollection<DetId>",
  "LCGReflex/std::pair<DetId,float>",
  "LCGReflex/std::vector<std::pair<DetId,float> >",
  "LCGReflex/std::vector<DetId>",
  "LCGReflex/std::map<DetId,std::pair<unsigned long,unsigned long> >",
  "LCGReflex/std::map<DetId,std::pair<unsigned int,unsigned int> >",
  "LCGReflex/edm::Wrapper<edm::EDCollection<DetId> >",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
