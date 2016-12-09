static  const char* clnames[] = {
  "LCGReflex/TotemDigiCollection<T1DetId,T1DigiSantiard>",
  "LCGReflex/T1DigiSantiard",
  "LCGReflex/std::vector<T1DigiSantiard>",
  "LCGReflex/std::map<T1DetId,std::vector<T1DigiSantiard> >",
  "LCGReflex/edm::Wrapper<TotemDigiCollection<T1DetId,T1DigiSantiard> >",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
