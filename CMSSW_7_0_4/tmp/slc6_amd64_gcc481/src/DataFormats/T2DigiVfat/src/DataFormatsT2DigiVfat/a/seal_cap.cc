static  const char* clnames[] = {
  "LCGReflex/T2DigiVfat",
  "LCGReflex/TotemDigiCollection<T2DetId,T2DigiVfat>",
  "LCGReflex/std::pair<T2DetId,std::vector<T2DigiVfat> >",
  "LCGReflex/std::vector<T2DigiVfat>",
  "LCGReflex/std::map<T2DetId,std::vector<T2DigiVfat> >",
  "LCGReflex/edm::Wrapper<std::pair<T2DetId,std::vector<T2DigiVfat> > >",
  "LCGReflex/edm::Wrapper<TotemDigiCollection<T2DetId,T2DigiVfat> >",
  "LCGReflex/std::map<unsigned int,unsigned int>",
  "LCGReflex/edm::Wrapper<std::map<unsigned int,unsigned int> >",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
