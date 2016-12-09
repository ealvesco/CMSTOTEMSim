static  const char* clnames[] = {
  "LCGReflex/T1Digi",
  "LCGReflex/TotemDigiCollection<T1DetId,T1Digi>",
  "LCGReflex/std::vector<T1Digi>",
  "LCGReflex/std::map<T1DetId,std::vector<T1Digi> >",
  "LCGReflex/edm::Wrapper<TotemDigiCollection<T1DetId,T1Digi> >",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
