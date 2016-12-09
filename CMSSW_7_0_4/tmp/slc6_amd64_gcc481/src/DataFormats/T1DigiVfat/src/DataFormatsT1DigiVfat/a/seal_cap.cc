static  const char* clnames[] = {
  "LCGReflex/TotemDigiCollection<T1DetId,T1DigiVfat>",
  "LCGReflex/T1DigiVfat",
  "LCGReflex/std::pair<T1DetId,std::vector<T1DigiVfat> >",
  "LCGReflex/std::vector<T1DigiVfat>",
  "LCGReflex/std::map<T1DetId,std::vector<T1DigiVfat> >",
  "LCGReflex/edm::Wrapper<std::pair<T1DetId,std::vector<T1DigiVfat> > >",
  "LCGReflex/edm::Wrapper<TotemDigiCollection<T1DetId,T1DigiVfat> >",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
